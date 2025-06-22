module uart_tx #(
	parameter CLK = 50000000,
	parameter BAUD_RATE = 115200,
	parameter BITS = 8
) (
	input                   clk,
	input                   send,
	input        [BITS-1:0] data,
	output logic            tx
);
	localparam CLK_DIVISOR = CLK / BAUD_RATE;

	logic [$clog2(CLK_DIVISOR):0] clkd;
	logic [$clog2(BITS)-1:0]      index;

	enum {IDLE, START, TRANSMISSION, STOP} state;

	initial begin
		tx = 1'b1;
		clkd = 0;
		index = 0;
		state = IDLE;
	end

	always @(posedge clk) begin
		case (state)
		IDLE: begin
			tx <= 1'b1;
			clkd <= 0;
			index <= 0;

			if (send) begin
				state <= START;
			end
		end
		START: begin
			tx <= 1'b0;

			// For one clock cycle
			if (clkd < CLK_DIVISOR-1) begin
				clkd <= clkd + 1;
			end else begin
				clkd <= 0;
				state <= TRANSMISSION;
			end
		end
		TRANSMISSION: begin
			tx <= data[index];

			if (clkd < CLK_DIVISOR-1) begin
				clkd <= clkd + 1;
			end else begin
				clkd <= 0;

				if (index < (BITS-1)) begin
					// Transmit a bit
					index <= index + 1;
				end else begin
					index <= 0;
					state <= STOP;
				end
			end
		end
		STOP: begin
			tx <= 1'b1;

			if (clkd < CLK_DIVISOR-1) begin
				clkd <= clkd + 1;
			end else begin
				clkd <= 0;
				state <= IDLE;
			end
		end
		endcase
	end
endmodule
