`timescale 10ns/10ns // 50MHz = 20ns perios for clk = 10ns per change

module dvi_out (
    input  wire        clkp, // 25MHz clock
    input  wire  [1:0] button,

	output logic [4:0] led,
	output wire  [7:0] vga_r,
    output wire  [7:0] vga_g,
    output wire  [7:0] vga_b,
	output wire        vsync,
    output wire        hsync,
    output wire        de
);
	// VGA input and output signals
	logic [7:0] r, g, b;
	wire  [9:0] px, py;

    logic [7:0] offset;

	// VGA Signal generator
	vga vga_driver(
		.clk(clkp),
		.r(r), .g(g), .b(b), 
		.px(px), .py(py), .vsync(vsync), .hsync(hsync), .de(de),
		.vga_r(vga_r), .vga_g(vga_g), .vga_b(vga_b)
	);

	// Output colors
	always_comb begin
		r = py[7:0] + offset;
		g = px[7:0] + offset;
	end

    always @(posedge clkp) begin
        if (px == 0 && py == 0) begin
            offset <= offset + 20;
        end
    end
    
    assign led = {hsync, vsync, de, button};
endmodule
