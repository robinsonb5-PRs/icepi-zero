module top (
    // 50MHz clock
    input clk,

    // UART input
    input usb_rx,

    // USB output (Emulated PS/2)
    output logic [1:0] usb_dp,
    output logic [1:0] usb_dn,
    // output [1:0] usb_pull_dp,
    // output [1:0] usb_pull_dn,
    // LED indication
    output logic [4:0] led
);
    // UART input
	logic       uart_finish; // One pulse
	logic [7:0] uart_data;
    uart_rx uart_core(
        .clk(clk),
        .rx(usb_rx),
        .finish(uart_finish),
        .data(uart_data)
    );

	wire [7:0] scancode;
    wire       send;
    ascii2ps2 converter(
        .clk(clk),
        .ascii(uart_data),
        .latch(uart_finish),
        .scancode(scancode),
        .send(send)
    );

    // PS/2 output
    wire ps2_clk;
    wire ps2_data;
    ps2_tx ps1_core(
        .clk(clk),

        .data(scancode),
        .send(send),

        .ps2_clk(ps2_clk),
        .ps2_data(ps2_data)
    );

    // Output 2 copies because why not
    // Maybe someone needs to controll 2 devices at the same time
    assign usb_dp[0] = ps2_clk;
    assign usb_dp[1] = ps2_clk;
    assign usb_dn[0] = ps2_data;
    assign usb_dn[1] = ps2_data;

    // assign usb_pull_dp = 2'b11;
    // assign usb_pull_dn = 2'b11;

    assign led[0] = 1'b1;
    assign led[1] = 1'b0;
    assign led[2] = ^scancode;
    assign led[3] = ps2_data;
    assign led[4] = ps2_clk;
endmodule
