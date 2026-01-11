// JTAG demo by Alastair M. Robinson

// Demonstrates communicating with a running design over JTAG,
// controlling the boards LEDs from a Tcl script, and reading
// back the value of a freerunning counter.

`default_nettype none

module top
(
    input         clk,
    output  [4:0] led
);

	wire locked;
    wire [3:0] clocks;
    ecp5pll
    #(
        .in_hz(50_000_000), // 25 MHz
      .out0_hz(100_000_000)
    )
    clk_25_video
    (
      .clk_i(clk),
      .clk_o(clocks),
      .locked(locked)
    );
    
    wire sysclk = clocks[0];
    
    wire reset_n = locked;


	// Instantiate the ECP5 JTAGG primitive
	wire tck,tdi,shift,update,rstn,sel1,sel2,tdo1,tdo2;

	JTAGG jtag_inst (
		.JTCK(tck),
		.JTDI(tdi),
		.JSHIFT(shift),
		.JUPDATE(update),
		.JRSTN(rstn),
		.JCE1(sel1),
		.JCE2(sel2),
		.JRTI1(),
		.JRTI2(),
		.JTDO1(tdo1),
		.JTDO2(tdo2)
	);

	// Attach a 5-bit register to the USER1 IR code (0x32), 

	wire [4:0] from_jtag;
	wire from_jtag_stb;
	jtag_register #(.bits(5)) reg1 (
		.sysclk(sysclk),
		.tck(tck),
		.tdi(tdi),
		.sel(sel1),
		.shift(shift),
		.update(update),
		.tdo(tdo1),
		.d(5'h15), // Shift out a fixed value, used for identification
		.q(from_jtag), // The value shifted in will be sent to the LEDs...
		.q_stb(from_jtag_stb) // ...when this strobe signal fires.
	);
	
	always @(posedge sysclk) begin
		if(from_jtag_stb)
			led <= from_jtag;
	end

	// Create a 32-bit freerunning counter, and attach it to
	// the USER2 IR code (0x38)
	
	reg [31:0] counter;
	always @(posedge sysclk) begin
		counter <= counter + 1;
		if(!reset_n)
			counter <= 0;
	end
	
	jtag_register #(.bits(32)) reg2 (
		.sysclk(sysclk),
		.tck(tck),
		.tdi(tdi),
		.sel(sel2),
		.shift(shift),
		.update(update),
		.tdo(tdo2),
		.d(counter), // Shift out the current value of the freerunning counter
		.q(), // Ignore whatever's shifted into this register.
		.q_stb()
	);
	

endmodule
