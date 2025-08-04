module top (
	input  wire        clk,
    input       [27:12] gpioi,
    output      [11:00] gpioo
);
	// Add one to the led register
	always_ff @(posedge clk) begin
        gpioo[11:0] <= gpioi[27:20] * gpioi[19:12];
	end
endmodule
