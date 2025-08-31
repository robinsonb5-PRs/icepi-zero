module top (
	input  wire        clk,
    input  wire  [1:0] button,
	output logic [3:0] gpdi_dp,
	output logic [4:0] led
);
	wire        vsync, hsync, de;
	wire  [7:0] vga_r, vga_g, vga_b;

	// Generate pixel and tmds clock (25MHz and 250MHz)
	wire clkp, clkt;
	dvi_pll pll(.clk_in(clk), .clkp(clkp), .clkt(clkt), .locked());

    dvi_out dvi(
        .clkp(clkp),
        .button(button),
        .led(led),
	    .vga_r(vga_r),
        .vga_g(vga_g),
        .vga_b(vga_b),
	    .vsync(vsync),
        .hsync(hsync),
        .de(de)
    );

	// Convert the signal to DVI and send over HDMI
	vga2tmds tmds_generator(
		.clkp(clkp), .clkt(clkt), 
		.vsync(vsync), .hsync(hsync), .de(de),
		.r(vga_r), .g(vga_g), .b(vga_b), .tmds(gpdi_dp));
endmodule
