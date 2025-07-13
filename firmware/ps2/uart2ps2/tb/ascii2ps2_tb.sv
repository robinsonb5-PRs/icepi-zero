module ascii2ps2_tb ();
    logic clk;

    logic [7:0] uart_data;
    logic       uart_finish;

	wire [7:0] scancode;
    wire       send;
    wire       ready;

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0, clk);

        uart_data = 0;
        uart_finish = 0;
        #4
        uart_data = "a";
        uart_finish = 1;
        #2
        uart_finish = 0;
        #2
        
        #500000
        uart_data = "A";
        uart_finish = 1;
        #2
        uart_finish = 0;
        #2
        
        #500000
        uart_data = "1";
        uart_finish = 1;
        #2
        uart_finish = 0;
        #2
        
        #500000
        uart_data = "1";
        uart_finish = 1;
        #2
        uart_finish = 0;
        #2
        
        #500000
        uart_data = "!";
        uart_finish = 1;
        #2
        uart_finish = 0;
        #2

        #500000
        $finish;
    end

    always begin
        #1 clk = ~clk;
    end

    ascii2ps2 converter(
        .clk(clk),
        .ascii(uart_data),
        .latch(uart_finish),
        .scancode(scancode),
        .send(send),
        .ready(ready)
    );

    wire ps2_clk;
    wire ps2_data;
    ps2_tx ps2_core(
        .clk(clk),

        .data(scancode),
        .send(send),

        .ps2_clk(ps2_clk),
        .ps2_data(ps2_data),
        .ready(ready)
    );
endmodule
