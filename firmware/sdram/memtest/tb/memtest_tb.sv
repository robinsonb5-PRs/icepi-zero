module tb();
    logic clk;

    wire [12:0] sdram_a;
    logic  [15:0] sdram_dq;
    wire  [1:0] sdram_ba;
    wire  [1:0] sdram_dqm;

    wire        sdram_wen;
    wire        sdram_casn;
    wire        sdram_rasn;

    wire        sdram_csn;
    wire        sdram_cke;
    wire        sdram_clk;

    wire  [4:0] led;
    logic   [1:0] button;

    top t(    
        .clk(clk),

        .sdram_a(sdram_a),
        .sdram_dq(sdram_dq),
        .sdram_ba(sdram_ba),
        .sdram_dqm(sdram_dqm),

        .sdram_wen(sdram_wen),
        .sdram_casn(sdram_casn),
        .sdram_rasn(sdram_rasn),

        .sdram_csn(sdram_csn),
        .sdram_cke(sdram_cke),
        .sdram_clk(sdram_clk),

        .led(led),
        .button(button)
    );

    always begin
        #1 clk = ~clk;
    end

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0, clk);
        button = 2'b11;

        #4
        button[1] = 0;

        #100
        button[1] = 1;

        #10
        button[1] = 0;

        #100
        button[1] = 1;

        #20000
        button[0] = 0;
        #20000
        button[0] = 1;
        #20000
        button[0] = 0;
        #20000
        button[0] = 1;
        #20000
        button[0] = 0;
        #20000
        button[0] = 1;

        #100000 $finish;
    end
endmodule
