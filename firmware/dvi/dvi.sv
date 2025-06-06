module top (
	input  wire        clk,
	output logic [3:0] gpdi_dp
);
	// Generate pixel and tmds clock (25MHz and 250MHz)
	wire clkp, clkt;
	dvi_pll pll(clk, clkp, clkt, led[0]);

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
	vga vga_driver(clkp, r, g, b, px, py, vsync, hsync, de, vga_r, vga_g, vga_b);

	// Convert the signal to DVI and send over HDMI
	vga2tmds tmds_generator(clkp, clkt, vsync, hsync, de, vga_r, vga_g, vga_b, gpdi_dp);
endmodule
