module top (
	input  wire        clk,
	input  logic [1:0] button,
	output logic [4:0] led
);
    logic btn, btn_last;
    debouncer bounce(.clk(clk), .btn(!button[0]), .sig(btn));

	always_ff @(posedge clk) begin
        btn_last <= btn;

		// Timer ended
		if (btn != btn_last && !btn) begin
            led <= led + 1;
		end
	end
endmodule

module debouncer #(
    parameter N = 7
) (
    input  clk,
    input  btn,
    output sig
);
    logic [N-1:0] buffer;
    assign sig = buffer[N-1];

    always_ff @(posedge clk) begin
        if (!buffer[N-1] && btn) begin
            buffer <= buffer + 1;
        end else if (!btn) begin
            buffer <= 0;
        end
    end
endmodule
