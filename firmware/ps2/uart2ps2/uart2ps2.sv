module top (
    // 50MHz clock
    input clk,

    // UART input
    input usb_rx,

    // USB output (Emulated PS/2)
    output [1:0] usb_dp,
    output [1:0] usb_dn,
    // output [1:0] usb_pull_dp,
    // output [1:0] usb_pull_dn,

    // LED indication
    output [4:0] led
);
    // UART input
	logic       uart_finish; // One pulse
	logic [7:0] uart_data;
	logic [7:0] ps2_code;
    uart_rx uart_core(.clk(clk), .rx(usb_rx), .finish(uart_finish), .data(uart_data));


    // D9S6 (U)
    // 8'h23
    // 8'h46
    // 8'h1B
    // 8'h36
    // 8'h3C

    always_comb begin
        case(uart_data)
            "A": ps2_code = 8'h1C;
            "B": ps2_code = 8'h32;
            "C": ps2_code = 8'h21;
            "D": ps2_code = 8'h23;
            "E": ps2_code = 8'h24;
            "F": ps2_code = 8'h2B;
            "G": ps2_code = 8'h34;
            "H": ps2_code = 8'h33;
            "I": ps2_code = 8'h43;
            "J": ps2_code = 8'h3B;
            "K": ps2_code = 8'h42;
            "L": ps2_code = 8'h4B;
            "M": ps2_code = 8'h3A;
            "N": ps2_code = 8'h31;
            "O": ps2_code = 8'h44;
            "P": ps2_code = 8'h4D;
            "Q": ps2_code = 8'h15;
            "R": ps2_code = 8'h2D;
            "S": ps2_code = 8'h1B;
            "T": ps2_code = 8'h2C;
            "U": ps2_code = 8'h3C;
            "V": ps2_code = 8'h2A;
            "W": ps2_code = 8'h1D;
            "X": ps2_code = 8'h22;
            "Y": ps2_code = 8'h35;
            "Z": ps2_code = 8'h1A;

            "0": ps2_code = 8'h45;
            "1": ps2_code = 8'h16;
            "2": ps2_code = 8'h1E;
            "3": ps2_code = 8'h26;
            "4": ps2_code = 8'h25;
            "5": ps2_code = 8'h2E;
            "6": ps2_code = 8'h36;
            "7": ps2_code = 8'h3D;
            "8": ps2_code = 8'h3E;
            "9": ps2_code = 8'h46;

            "-": ps2_code = 8'h4E;
            "=": ps2_code = 8'h55;
            // 8'h34: ps2_code = 8'h5D ;     // backslash
            // "_": ps2_code = 8'h66;      // backspace
            " ": ps2_code = 8'h29;
                                
            8'd13: ps2_code = 8'h5A;     // enter
            "[": ps2_code = 8'h54;
            "]": ps2_code = 8'h5B;
            ";": ps2_code = 8'h4C;
            "'": ps2_code = 8'h52;
            ",": ps2_code = 8'h41;
            ".": ps2_code = 8'h49;
            "/": ps2_code = 8'h4A;

            "a": ps2_code = 8'h1C;
            "b": ps2_code = 8'h32;
            "c": ps2_code = 8'h21;
            "d": ps2_code = 8'h23;
            "e": ps2_code = 8'h24;
            "f": ps2_code = 8'h2B;
            "g": ps2_code = 8'h34;
            "h": ps2_code = 8'h33;
            "i": ps2_code = 8'h43;
            "j": ps2_code = 8'h3B;
            "k": ps2_code = 8'h42;
            "l": ps2_code = 8'h4B;
            "m": ps2_code = 8'h3A;
            "n": ps2_code = 8'h31;
            "o": ps2_code = 8'h44;
            "p": ps2_code = 8'h4D;
            "q": ps2_code = 8'h15;
            "r": ps2_code = 8'h2D;
            "s": ps2_code = 8'h1B;
            "t": ps2_code = 8'h2C;
            "u": ps2_code = 8'h3C;
            "v": ps2_code = 8'h2A;
            "w": ps2_code = 8'h1D;
            "x": ps2_code = 8'h22;
            "y": ps2_code = 8'h35;
            "z": ps2_code = 8'h1A;
                                 
            ")": ps2_code = 8'h45;
            "!": ps2_code = 8'h16;
            "@": ps2_code = 8'h1E;
            "#": ps2_code = 8'h26;
            "$": ps2_code = 8'h25;
            "%": ps2_code = 8'h2E;
            "^": ps2_code = 8'h36;
            "&": ps2_code = 8'h3D;
            "*": ps2_code = 8'h3E;
            "(": ps2_code = 8'h46;
                                 
            8'd8: ps2_code = 8'h4E;
            "+": ps2_code = 8'h55;
            "|": ps2_code = 8'h5D;
            "_": ps2_code = 8'h66;      // backspace, normally ASCII 0x08 but '_' for Apple 1

            "{": ps2_code = 8'h54;
            "}": ps2_code = 8'h5B;
            ":": ps2_code = 8'h4C;
            "\"": ps2_code = 8'h52;
            "<": ps2_code = 8'h41;
            ">": ps2_code = 8'h49;
            "?": ps2_code = 8'h4A;
            default: 
                ps2_code = 8'h24;
        endcase
    end

    // PS/2 output
    wire ps2_clk;
    wire ps2_data;
    ps2output ps2_core(.clk(clk), .data(ps2_code), .rts(uart_finish), .ps2_clk(ps2_clk), .ps2_data(ps2_data));

    // Output 2 copies because why not
    // Maybe someone needs to controll 2 devices at the same time
    assign usb_dp[0] = ps2_clk;
    assign usb_dp[1] = ps2_clk;
    assign usb_dn[0] = ps2_data;
    assign usb_dn[1] = ps2_data;

    assign led[0] = clk;
    assign led[1] = usb_rx;
    assign led[2] = uart_finish;
    assign led[3] = ps2_clk;
    assign led[4] = ps2_data;
endmodule
