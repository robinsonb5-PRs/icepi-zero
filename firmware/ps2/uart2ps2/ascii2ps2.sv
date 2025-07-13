module ascii2ps2 #(
	parameter BUFFER_SIZE = 15
) (
    input clk,
    input reset,

    // UART input
    input [7:0] ascii,
    input       latch,

    // PS2 Scancode output
    input              ready,
    output logic [7:0] scancode,
    output logic       send,
    output wire shifts
);
    logic                     [7:0] buffer [0:BUFFER_SIZE-1];
    logic [$clog2(BUFFER_SIZE)-1:0] waddress;
    logic [$clog2(BUFFER_SIZE)-1:0] raddress;

    wire [7:0] scancode_press;
    wire shift;
    assign shifts = shift;

    scancode_translator translator(
        .ascii(ascii),
        .ps2(scancode_press),
        .shift(shift)
    );

    always_ff @(posedge clk) begin
        if (reset) begin
            scancode = 0;
            send = 0;
            waddress = 0;
            raddress = 0;
        end else begin
        if (latch && ((raddress == BUFFER_SIZE-1) ? 0 : raddress+1) != waddress) begin
            // Shifts
            if (shift) begin
                buffer[waddress] <= 8'h12; // Press shift
                buffer[waddress+1] <= scancode_press;
                buffer[waddress+2] <= 8'hF0;

                if (waddress >= BUFFER_SIZE-3) begin
                    buffer[0] <= scancode_press;

                    // Release shift
                    buffer[1] <= 8'hF0;
                    buffer[2] <= 8'h12;
                end else begin
                    buffer[waddress+3] <= scancode_press;

                    buffer[waddress+4] <= 8'hF0;
                    buffer[waddress+5] <= 8'h12;
                end

                if (waddress >= BUFFER_SIZE-3) begin
                    waddress <= 3;
                end else if (waddress >= BUFFER_SIZE-6) begin
                    waddress <= 0;
                end else begin
                    waddress <= waddress + 6;
                end
            end else begin
                // No shift
                buffer[waddress] <= scancode_press;
                buffer[waddress+1] <= 8'hF0;
                buffer[waddress+2] <= scancode_press;

                if (waddress >= BUFFER_SIZE-3) begin
                    waddress <= 0;
                end else begin
                    waddress <= waddress + 3;
                end
            end
        end

        if (send) begin
            send <= 0; // Send should be pulse of 1 clk cycle
        end else if (waddress != raddress && ready) begin
            // We need to send some characters
            send <= 1;
            scancode <= buffer[raddress];

            if (raddress >= BUFFER_SIZE-1) begin
                raddress <= 0;
            end else begin
                raddress <= raddress + 1;
            end
        end
        end
    end
endmodule
