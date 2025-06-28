module top(
	input        clk,
	input        usb_rx,

	output       usb_tx,
	output [2:0] led
);
	logic       finish;
	logic [7:0] data;

	uart_tx TX (clk, finish, data, usb_rx);
	uart_rx RX (clk, usb_tx, finish, data);

	// Indicator leds
	assign led[0] = finish;
	assign led[1] = ~usb_rx;
	assign led[2] = ~usb_tx;
endmodule

