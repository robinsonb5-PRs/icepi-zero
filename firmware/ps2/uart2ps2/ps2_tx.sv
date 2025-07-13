module ps2_tx #(
	parameter CLK = 50000000,
	parameter FREQUENCY = 12000,
) (
    input clk,
    input reset,

    input [7:0] data,
    input       send,

    output logic ps2_clk,
    output logic ps2_data,
    output logic ready
);
    localparam CLK_DIVISOR = CLK/FREQUENCY;

    logic [ 8:0] data_latch;
    logic [15:0] clkd;
    logic [ 3:0] index;

    enum {IDLE, START, TRANSMISSION, STOP} state;

    always_ff @(posedge clk) begin
        if (reset) begin
            data_latch = 0;
            clkd = 0;
            index = 0;
            state = IDLE;

            ps2_clk = 1;
            ps2_data = 1;
            ready = 1;
        end else begin
        case (state)
        IDLE: begin
            ps2_data <= 1;
            ps2_clk <= 1;
			clkd <= 0;
            index <= 0;

            if (send) begin
                state <= START;
                ready <= 0;

                // Data w/ pairity bit
                data_latch <= {~{^data}, data};
            end else begin
                ready <= 1;
            end
        end
        START: begin
            ps2_data <= 0;
            ready <= 0;

            if (clkd == CLK_DIVISOR/2-1) begin
                ps2_clk <= 0;
            end 

            if (clkd < CLK_DIVISOR-1) begin
				clkd <= clkd + 1;
			end else begin
                state <= TRANSMISSION;
                clkd <= 0;
                ps2_clk <= 1;
            end
        end
        TRANSMISSION: begin
            ps2_data <= data_latch[index];
            ready <= 0;

            if (clkd == CLK_DIVISOR/2-1) begin
                ps2_clk <= 0;
            end 

			if (clkd < CLK_DIVISOR-1) begin
				clkd <= clkd + 1;
			end else begin
				clkd <= 0;
                ps2_clk <= 1;

				if (index < 8) begin
					// Transmit a bit
					index <= index + 1;
				end else begin
					index <= 0;
					state <= STOP;
				end
            end
        end
        STOP: begin
            ps2_data <= 1;

            if (clkd == CLK_DIVISOR/2-1) begin
                ps2_clk <= 0;
            end 

			if (clkd < CLK_DIVISOR-1) begin
				clkd <= clkd + 1;
                ready <= 0;
			end else begin
                clkd <= 0;
                ps2_clk <= 1;
                data_latch <= 0;
                index <= 0;
                state <= IDLE;
            end
        end
        endcase
        end
    end
endmodule
