`timescale 10ns/10ns

module vga (
	input  wire        clk,
	input  wire  [7:0] r,
	input  wire  [7:0] g,
	input  wire  [7:0] b,
	output logic [9:0] px,
	output logic [9:0] py,
	output logic       vsync,
	output logic       hsync,
	output logic       de,
	output logic [7:0] vga_r,
	output logic [7:0] vga_g,
	output logic [7:0] vga_b
);
    initial begin
        px = 0;
        py = 0;
    end

	// 640x480 @ 60Hz
	localparam HA_END = 639;
	localparam HS_STA = HA_END + 16;
	localparam HS_END = HS_STA + 96;
	localparam LINE   = 799;

	localparam VA_END = 479;
	localparam VS_STA = VA_END + 10;
	localparam VS_END = VS_STA + 2; 
	localparam SCREEN = 524;

	// Generate hsync and vsync signals
	always_comb begin
		hsync = ~(px >= HS_STA && px < HS_END);
		vsync = ~(py >= VS_STA && py < VS_END);
		de = (px <= HA_END && py <= VA_END);

		vga_r = de ? r : 8'b0;
		vga_g = de ? g : 8'b0;
		vga_b = de ? b : 8'b0;
	end

	// Count the x, y positions
	always_ff @(posedge clk) begin
		if (px == LINE) begin
			px <= 0;
			py <= (py == SCREEN) ? 0 : py + 1;
		end else begin
			px <= px + 1;
		end
	end
endmodule
