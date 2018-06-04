
`timescale 1 ns/ 10 ps


/*
	Модуль формирования общего сброса
*/


module REST_Global
( 
	input wire 	CLK_IN,	
	input wire	PLL_OK,
	// Описание выходных сигналов схемы
	output reg	n_RESET
);

	// объявление переменных
	reg [7:0]  ST_REST;
		
	//начальная установка всех регистров
	initial                                                
	begin                                                  
		n_RESET = 0;
		ST_REST = 0;		
	end

		// Счетчик задержки
	always @(posedge CLK_IN or negedge PLL_OK)
	begin
		if (!PLL_OK)
		begin
			ST_REST  <= 8'b0;
		end
		else if (!n_RESET)
		begin
			ST_REST  <= ST_REST +1;
		end		
		else
		begin
			ST_REST  <= ST_REST;
		end
	end
	
	always @(posedge CLK_IN or negedge PLL_OK)
	begin
		if (!PLL_OK)
		begin
			n_RESET <= 0;
		end
		else if (ST_REST > 224) 
		begin
			n_RESET <= 1;
		end
		else
		begin
			n_RESET <= 0;
		end
	end	
	
endmodule //REST_Global