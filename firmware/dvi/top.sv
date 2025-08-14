module top (
	input  wire        clk,
	output logic [3:0] gpdi_dp,
	output logic [4:0] led
);
	// Generate pixel and tmds clock (25MHz and 250MHz)
	wire clkp, clkt;
	dvi_pll pll(.clk_in(clk), .clkp(clkp), .clkt(clkt), .locked(led[0]));

	// VGA input and output signals
	logic [7:0] r, g, b;
	wire  [9:0] px, py;
	wire        vsync, hsync, de;
	wire  [7:0] vga_r, vga_g, vga_b;

	// Output colors
	always_comb begin
		r = py[7:0];

		g = px[7:0];

		if (px[3])
			b = 8'h00;
		else
			b = 8'hFF;
	end

	// VGA Signal generator
	vga vga_driver(
		.clk(clkp),
		.r(r), .g(g), .b(b), 
		.px(px), .py(py), .vsync(vsync), .hsync(hsync), .de(de),
		.vga_r(vga_r), .vga_g(vga_g), .vga_b(vga_b)
	);

	// Convert the signal to DVI and send over HDMI
	vga2tmds tmds_generator(
		.clkp(clkp), .clkt(clkt), 
		.vsync(vsync), .hsync(hsync), .de(de),
		.r(vga_r), .g(vga_g), .b(vga_b), .tmds(gpdi_dp));
endmodule
