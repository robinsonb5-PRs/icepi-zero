module ascii2ps2 #(
	parameter BUFFER_SIZE = 32
) (
    input clk,

    // UART input
    input [7:0] ascii,
    input       latch,

    // PS2 Scancode output
    output logic [7:0] scancode,
    output logic       send
);
    logic                   [7:0] buffer [BUFFER_SIZE];
    logic [$clog2(BUFFER_SIZE)-1:0] waddress;
    logic [$clog2(BUFFER_SIZE)-1:0] raddress;
    logic                         shift_state;

    // For all ascii, 
    wire [7:0] scancode_press;
    wire shift;

    scancode_translator translator(
        .ascii(ascii),
        .ps2(scancode_press),
        .shift(shift)
    );

    always_ff @(posedge clk) begin
        if (latch) begin

            shift_state <= shift;

            // Shifts
            if (shift != shift_state) begin
                buffer[waddress] <= 8'h12;
                buffer[waddress+1] <= scancode_press;
                buffer[waddress+2] <= 8'hF0;

                if (waddress >= BUFFER_SIZE-4) begin
                    buffer[0] <= scancode_press;

                    buffer[1] <= 8'hF0;
                    buffer[2] <= 8'h12;
                end else begin
                    buffer[waddress] <= scancode_press;

                    buffer[waddress+1] <= 8'hF0;
                    buffer[waddress+2] <= 8'h12;
                end
            end else begin
                buffer[waddress] <= scancode_press;
                buffer[waddress+1] <= 8'hF0;
                buffer[waddress+2] <= scancode_press;
            end

            if (waddress >= BUFFER_SIZE-3) begin
                waddress <= 0;
            end else if (shift != shift_state) begin 
                if (waddress >= BUFFER_SIZE-3) begin
                    waddress <= 3;
                end else if (waddress >= BUFFER_SIZE-6) begin
                    waddress <= 0;
                end else begin
                    waddress <= waddress + 6;
                end
            end else begin
                waddress <= waddress + 3;
            end
        end

        if (send) begin
            send <= 0; // Send should be pulse
        end else if (waddress != raddress) begin
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
endmodule
