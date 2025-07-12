module scancode_translator (
    input  [7:0] ascii,
    output logic [7:0] ps2,
    output logic       shift
);
    always_comb begin
        case (ascii)
        "a": ps2 = 8'h1C;
        "b": ps2 = 8'h32;
        "c": ps2 = 8'h21;
        "d": ps2 = 8'h23;
        "e": ps2 = 8'h24;
        "f": ps2 = 8'h2B;
        "g": ps2 = 8'h34;
        "h": ps2 = 8'h33;
        "i": ps2 = 8'h43;
        "j": ps2 = 8'h3B;
        "k": ps2 = 8'h42;
        "l": ps2 = 8'h4B;
        "m": ps2 = 8'h3A;
        "n": ps2 = 8'h31;
        "o": ps2 = 8'h44;
        "p": ps2 = 8'h4D;
        "q": ps2 = 8'h15;
        "r": ps2 = 8'h2D;
        "s": ps2 = 8'h1B;
        "t": ps2 = 8'h2C;
        "u": ps2 = 8'h3C;
        "v": ps2 = 8'h2A;
        "w": ps2 = 8'h1D;
        "x": ps2 = 8'h22;
        "y": ps2 = 8'h35;
        "z": ps2 = 8'h1A;

        "0": ps2 = 8'h45;
        "1": ps2 = 8'h16;
        "2": ps2 = 8'h1E;
        "3": ps2 = 8'h26;
        "4": ps2 = 8'h25;
        "5": ps2 = 8'h2E;
        "6": ps2 = 8'h36;
        "7": ps2 = 8'h3D;
        "8": ps2 = 8'h3E;
        "9": ps2 = 8'h46;
        "`": ps2 = 8'h0E;
        "-": ps2 = 8'h4E;
        "=": ps2 = 8'h55;
        "\\": ps2 = 8'h5D;
        "[": ps2 = 8'h54;
        "]": ps2 = 8'h5B;
        ";": ps2 = 8'h4C;
        "'": ps2 = 8'h52;
        ",": ps2 = 8'h41;
        ".": ps2 = 8'h49;
        "/": ps2 = 8'h4A;

        " ": ps2 = 8'h29;
        8'h0D: ps2 = 8'h5A; // Enter
        8'h0A: ps2 = 8'h5A; // Enter
        8'h08: ps2 = 8'hE0;

        // Capital of these symbols
        "A": ps2 = 8'h1C;
        "B": ps2 = 8'h32;
        "C": ps2 = 8'h21;
        "D": ps2 = 8'h23;
        "E": ps2 = 8'h24;
        "F": ps2 = 8'h2B;
        "G": ps2 = 8'h34;
        "H": ps2 = 8'h33;
        "I": ps2 = 8'h43;
        "J": ps2 = 8'h3B;
        "K": ps2 = 8'h42;
        "L": ps2 = 8'h4B;
        "M": ps2 = 8'h3A;
        "N": ps2 = 8'h31;
        "O": ps2 = 8'h44;
        "P": ps2 = 8'h4D;
        "Q": ps2 = 8'h15;
        "R": ps2 = 8'h2D;
        "S": ps2 = 8'h1B;
        "T": ps2 = 8'h2C;
        "U": ps2 = 8'h3C;
        "V": ps2 = 8'h2A;
        "W": ps2 = 8'h1D;
        "X": ps2 = 8'h22;
        "Y": ps2 = 8'h35;
        "Z": ps2 = 8'h1A;

        ")": ps2 = 8'h45;
        "!": ps2 = 8'h16;
        "@": ps2 = 8'h1E;
        "#": ps2 = 8'h26;
        "$": ps2 = 8'h25;
        "%": ps2 = 8'h2E;
        "^": ps2 = 8'h36;
        "&": ps2 = 8'h3D;
        "*": ps2 = 8'h3E;
        "(": ps2 = 8'h46;
        "~": ps2 = 8'h0E;
        "_": ps2 = 8'h4E;
        "+": ps2 = 8'h55;
        "|": ps2 = 8'h5D;
        "{": ps2 = 8'h54;
        "}": ps2 = 8'h5B;
        ":": ps2 = 8'h4C;
        "\"": ps2 = 8'h52;
        "<": ps2 = 8'h41;
        ">": ps2 = 8'h49;
        "?": ps2 = 8'h4A;

        default: ps2 = 8'h26; // Error
        endcase

        // Needs to be capital letter
        case (ascii)
        // Capital of these symbols
        "A": shift = 1;
        "B": shift = 1;
        "C": shift = 1;
        "D": shift = 1;
        "E": shift = 1;
        "F": shift = 1;
        "G": shift = 1;
        "H": shift = 1;
        "I": shift = 1;
        "J": shift = 1;
        "K": shift = 1;
        "L": shift = 1;
        "M": shift = 1;
        "N": shift = 1;
        "O": shift = 1;
        "P": shift = 1;
        "Q": shift = 1;
        "R": shift = 1;
        "S": shift = 1;
        "T": shift = 1;
        "U": shift = 1;
        "V": shift = 1;
        "W": shift = 1;
        "X": shift = 1;
        "Y": shift = 1;
        "Z": shift = 1;

        ")": shift = 1;
        "!": shift = 1;
        "@": shift = 1;
        "#": shift = 1;
        "$": shift = 1;
        "%": shift = 1;
        "^": shift = 1;
        "&": shift = 1;
        "*": shift = 1;
        "(": shift = 1;
        "~": shift = 1;
        "_": shift = 1;
        "+": shift = 1;
        "|": shift = 1;
        "{": shift = 1;
        "}": shift = 1;
        ":": shift = 1;
        "\"": shift = 1;
        "<": shift = 1;
        ">": shift = 1;
        "?": shift = 1;
        default: shift = 0;
        endcase
    end
endmodule
