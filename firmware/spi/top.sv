module top (
    input clk,

    input usb_rx,
    output usb_tx,

    input pi_tx,
    output pi_rx,

    output pi_nirq,
    input  pi_sclk,
    input  pi_mosi,
    output pi_miso,
    input  pi_ce0,

    output [4:0] led
);
    assign pi_rx = usb_rx;
    assign usb_tx = pi_tx;

endmodule
