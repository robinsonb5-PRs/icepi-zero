`define SIMULATION

module top (
    input clk,

    output [12:0] sdram_a,
    inout  [15:0] sdram_dq,
    output  [1:0] sdram_ba,
    output  [1:0] sdram_dqm,

    output        sdram_wen,
    output        sdram_casn,
    output        sdram_rasn,

    output        sdram_csn,
    output        sdram_cke,
    output        sdram_clk,

    output logic [4:0] led,
    input   [1:0] button
);
`ifndef VERILATOR
    wire [3:0] sys_sdram_clocks;
    wire sys_sdram_clocks_locked;
    ecp5pll #(
          .in_hz( 50*1000000),
        .out0_hz(100*1000000), // 4*25*6/7 MHz
        .out1_hz(100*1000000), .out1_deg(90), // 0-45 ok, 90 fail, 150-359 ok
        .out2_hz( 20*1000000), .out2_tol_hz(1*1000), //   25*6/7 MHz
        .out3_hz( 20*1000000), .out3_tol_hz(1*1000)  // not used
    ) clk_sdram_sys_inst (
        .clk_i(clk),
        .clk_o(sys_sdram_clocks),
        .locked(sys_sdram_clocks_locked)
    );
    wire clock_sdram_core = sys_sdram_clocks[0];
    wire clock_sdram_chip = sys_sdram_clocks[1];
    wire clock            = sys_sdram_clocks[2];
    reg clock_locked;
    always @(posedge clock) begin
        clock_locked <= sys_sdram_clocks_locked;
    end
`else
    wire clock_sdram_core = clk;
    wire clock_sdram_chip = clk;
    wire clock            = clk;
    wire clock_locked     = 1;
`endif

    logic [15:0] din;        // data input from cpu
    wire  [15:0] dout;       // data output to cpu
    logic [23:0] addr;       // 24 bit word address
    logic  [1:0] dstrobe;       // upper data strobe
    logic        astrobe;        // address strobe
    logic        rw;         // cpu/chipset requests write

    // Press button 1 to reset the system
    wire reset;
    debouncer reset_debounce(.clk(clock), .btn(!button[1] || !clock_locked), .sig(reset));

    // Advance button
    wire  advance;
    logic advance_last;
    debouncer advance_debounce(.clk(clock), .btn(!button[0]), .sig(advance));

    assign sdram_clk = clock_sdram_chip;
    sdram sdram_controller(
        .clk100_mhz(clock_sdram_core), // sdram is accessed at 100MHz

        // interface to the MT48LC16M16 chip
        .sd_data(sdram_dq),    // 16 bit databus
        .sd_addr(sdram_a),    // 13 bit multiplexed address bus
        .sd_dqm(sdram_dqm),     // two byte masks
        .sd_ba(sdram_ba),      // two banks
        .sd_cs(sdram_csn),      // a single chip select
        .sd_we(sdram_wen),      // write enable
        .sd_ras(sdram_rasn),     // row address select
        .sd_cas(sdram_casn),     // columns address select

        // M68K interface
        .din(din),        // data input from cpu
        .dout(dout),       // data output to cpu
        .addr(addr),       // 24 bit word address
        .udsn(dstrobe[1]),       // upper data strobe
        .ldsn(dstrobe[0]),       // lower data strobe
        .asn(astrobe),        // address strobe
        .rw(rw),         // cpu/chipset requests write 1=read
        .rst(reset)         // cpu reset

        ,.led(led)
    );

    enum {INIT, WRITE, READ, REPORT} state;

    always_ff @(posedge clock) begin
        advance_last <= advance;
        dstrobe <= 0;
        astrobe <= 0;

        case (state)
        INIT: begin
            rw <= 0;
            addr <= 0;
            led <= 0;
            rw <= 0;

            state <= WRITE;
        end
        WRITE: begin
            rw <= 0;
            led[4] <= 1;
            led[3:0] <= addr[3:0];

            addr <= addr + 1;
            din <= addr[15:0] + 1;
            astrobe <= 1;
            dstrobe <= 2'b11;

            if (addr >= 20) begin
                state <= READ;
                addr <= 0;
                rw <= 1;
            end
        end
        READ: begin
            rw <= 1;
            led[4] <= 0;

            if (advance_last != advance && advance) begin
                led[3:0] <= dout[3:0];
                addr <= addr + 1;
                astrobe <= 1;
            end 

            if (addr >= 20) begin
                state <= REPORT;
                addr <= 0;
                read <= 0;
            end
        end
        REPORT: begin
            rw <= 1;
            addr <= 0;
            din <= 0;

            if (~button[0]) begin
                state <= INIT;
            end
        end
        default: state <= INIT;
        endcase

        // Reset
        if (reset) begin
            state <= INIT;
            addr <= 0;
        end
    end
endmodule

module debouncer #(
    parameter N = 12
) (
    input  clk,
    input  btn,
    output sig
);
    logic [N-1:0] buffer;
    assign sig = buffer[N-1];

    always_ff @(posedge clk) begin
        if (!buffer[N-1] && btn) begin
            buffer <= buffer + 1;
        end else if (!btn) begin
            buffer <= 0;
        end
    end
endmodule
