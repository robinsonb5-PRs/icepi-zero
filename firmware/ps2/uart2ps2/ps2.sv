module ps2output (
    input clk,

    input [7:0] data,
    input       rts,

    output logic ps2_clk,
    output logic ps2_data
);
    localparam CLK_DIVISOR = 5000;

    logic [ 8:0] data_latch;
    logic [15:0] clkd;
    logic [ 3:0] index;

    enum {IDLE, START, TRANSMISSION, STOP} state;

    initial begin
        state = IDLE;
        clkd = 0;
        data_latch = 0;
        index = 0;
        ps2_clk = 1;
    end

    always_ff @(posedge clk) begin
        case (state)
        IDLE: begin
            ps2_data <= 1;
			clkd <= 0;
            index <= 0;
            ps2_clk <= 1;

            if (rts) begin
                state <= START;

                // Data w/ pairity bit
                data_latch <= {~{^data}, data};
            end
        end
        START: begin
            ps2_data <= 0;

            if (clkd == CLK_DIVISOR/2-1) begin
                ps2_clk <= 0;
            end 

            if (clkd < CLK_DIVISOR-1) begin
				clkd <= clkd + 1;
			end else begin
                state <= TRANSMISSION;
                clkd <= 0;
                ps2_clk <= 1;
            end
        end
        TRANSMISSION: begin
            ps2_data <= data_latch[index];

            if (clkd == CLK_DIVISOR/2-1) begin
                ps2_clk <= 0;
            end 

			if (clkd < CLK_DIVISOR-1) begin
				clkd <= clkd + 1;
			end else begin
				clkd <= 0;
                ps2_clk <= 1;

				if (index < 8) begin
					// Transmit a bit
					index <= index + 1;
				end else begin
					index <= 0;
					state <= STOP;
				end
            end
        end
        STOP: begin
            ps2_data <= 1;

            if (clkd == CLK_DIVISOR/2-1) begin
                ps2_clk <= 0;
            end 

			if (clkd < CLK_DIVISOR-1) begin
				clkd <= clkd + 1;
			end else begin
                state <= IDLE;
                clkd <= 0;
                ps2_clk <= 1;
            end
        end
        endcase
    end
endmodule
