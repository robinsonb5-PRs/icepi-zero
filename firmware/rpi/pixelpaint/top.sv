module top (
	input        clk,

    inout [27:0] gpio,

    input        usb_rx,
    output       usb_tx,

	output logic [3:0] gpdi_dp,
	output logic [4:0] led
);
    // assign gpio[14] = 1'bz;
    assign usb_tx = gpio[14];
    assign gpio[15] = usb_rx;

    wire color_in;
    // assign gpio[1:0] = 2'bzz;
    assign color_in = gpio[1:0];

	// Generate pixel and tmds clock (25MHz and 250MHz)
	wire clkp, clkt;
	dvi_pll pll(.clk_in(clk), .clkp(clkp), .clkt(clkt), .locked(led[0]));

	// VGA input and output signals
	logic [7:0] r, g, b;
	wire  [9:0] px, py;
	wire        vsync, hsync, de;
	wire  [7:0] vga_r, vga_g, vga_b;

    logic [1:0] counter;
    logic       gpio_last;

    always_ff @(posedge clk) begin
        // gpio_last <= gpio[0];
        counter <= color_in;
    end

	// Output colors
	always_comb begin
		r = (counter == 2'd0) ? 8'hFF : 0;
		g = (counter == 2'd1) ? 8'hFF : 0;
		b = (counter == 2'd2) ? 8'hFF : 0;
		b = (counter == 2'd3) ? 8'h3F : 0;
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

