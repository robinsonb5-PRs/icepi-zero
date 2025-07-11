module top ();
    logic       clk;
    logic [7:0] uart_data;
    logic       uart_finish;

    wire ps2_clk;
    wire ps2_data;

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0, clk, uart_data, uart_finish, ps2_clk, ps2_data);

        clk = 0;
        uart_data = 11;
        uart_finish = 0;
        #5 uart_finish = 1;
        #5 uart_finish = 0;

        #5000 $finish;
    end

    always begin
        #5 clk = ~clk;
    end

    ps2output ps2_core(.clk(clk), .data(uart_data), .rts(uart_finish), .ps2_clk(ps2_clk), .ps2_data(ps2_data));
endmodule
