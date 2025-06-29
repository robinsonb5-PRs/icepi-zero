module top(
	input clk,

	inout [1:0] usb_dp,
	inout [1:0] usb_dn,

	input [1:0] button,

	output usb_tx,

	output [3:0] gpdi_dp,

	output [4:0] led
);
	assign reset_n = button[0];

	wire clk12;
	pll pll(clk, clk12, );


	wire report;
	assign led[2] = report;

	wire signed [7:0] mouse_dx;
	wire signed [7:0] mouse_dy;

	usb_hid_host usb(
		.usbclk(clk12),
		.usbrst_n(reset_n),
		.usb_dm(usb_dn[0]),
		.usb_dp(usb_dp[0]),

		.typ(led[1:0]),
		.report(report),
		.conerr(led[3]),

		.key_modifiers(),
		.key1(),
		.key2(),
		.key3(),
		.key4(),

		.mouse_btn(),
		.mouse_dx(mouse_dx),
		.mouse_dy(mouse_dy),

		.game_l(),
		.game_r(),
		.game_u(),
		.game_d(),
		.game_a(),
		.game_b(),
		.game_x(),
		.game_y(),
		.game_sel(),
		.game_sta(),

		.dbg_hid_report()
	);

	// Mouse pos
	reg [9:0] mx;
	reg [9:0] my;

	reg dx;
	reg dy;

	always @(posedge clk12) begin
		if (~reset_n) begin 
			mx <= 0;
			my <= 0;
		end else begin 
			mx <= (report) ? mx + {{2{mouse_dx[7]}}, mouse_dx[7:0]} : mx;
			my <= (report) ? my + {{2{mouse_dy[7]}}, mouse_dy[7:0]} : my;

			// Record sign for future use
			dx <= mouse_dx[7];
			dy <= mouse_dy[7];

			// 640x480
			if (mx > 640) begin
				mx <= (dx) ? mx + 640 : mx - 640;
			end

			if (my > 480) begin
				my <= (dy) ? my + 480 : my - 480;
			end
		end
	end


	wire clkp, clkt;
	pll_dvi pll_dvi(.clk(clk), .clkout0(clkt), .clkout1(clkp), .locked());

	// VGA input and output signals
	reg  [7:0] r, g, b;
	wire [9:0] px, py;
	wire       vsync, hsync, de;
	wire [7:0] vga_r, vga_g, vga_b;
	reg  [9:0] vmx, vmy;

	always @(posedge hsync) begin
		vmx <= mx;
		vmy <= my;
	end

	// Output colors
	always_comb begin
		g = 0;
		b = 0;

		r = (px >= vmx && px <= vmx + 20 && py >= vmy && py <= vmy + 20) ? 'hFF : 0;
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
