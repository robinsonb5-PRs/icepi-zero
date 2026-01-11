`default_nettype none

module jtag_register #(parameter bits=32) (
	input sysclk,
	input tck,
	input tdi,
	input sel,
	input shift,
	input update,
	output reg tdo,
	input [bits-1:0] d,
	output reg [bits-1:0] q,
	output reg q_stb
);

reg [2:0] tck_s; // JTAG clock synced to sysclk domain

always @(posedge sysclk) begin
	tck_s <= {tck_s[1:0],tck};
end

wire tck_p,tck_n; // Rising and falling edges of JTAG clock, in sysclk domain
assign tck_p=tck_s[2:1]==2'b01 ? 1'b1 : 1'b0;
assign tck_n=tck_s[2:1]==2'b10 ? 1'b1 : 1'b0;


// As we leave the shift state we latch the previous value of tdi, which will
// have evaporated by the time the update signal triggers.

reg shift_d;
reg tdi_latched;
always @(posedge sysclk) begin
	if(tck_p) begin
		shift_d <= shift;
		if(shift_d)
			tdi_latched <= tdi;
	end
end

wire tdi_mux = shift_d ? tdi : tdi_latched; // Multiplex between live and latched tdi signal

reg [bits-1:0] shiftreg;
wire [bits-1:0] shiftnext;

assign shiftnext = {tdi_mux,shiftreg[bits-1:1]};

reg selected;
always @(posedge sysclk) begin
	q_stb <= 1'b0;

	if(tck_p) begin

		if(sel && !shift) // Work around the lack of a capture signal
			shiftreg <= d;
	
		if(shift)
			selected <= sel;

		if(shift && sel) begin
			tdo <= shiftreg[0];
			shiftreg <= shiftnext;
		end

		if(update && selected) begin
			q <= shiftnext;
			q_stb <= 1'b1;
		end
	end
end

endmodule 

