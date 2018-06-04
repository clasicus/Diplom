

`timescale 1 ns/ 10 ps


/*
	Модуль формирования сброса для мс. AD2S1210
*/


module SYS_REST
( 
	input wire 	CLK_IN,	
	input wire	MASTER_OK,
	// Описание выходных сигналов схемы
	output reg	REST_master,
	output reg	REST_slave
);

	// объявление переменных
	reg [7:0]  ST_REST;
		
	//начальная установка всех регистров
	initial                                                
	begin                                                  
		REST_master = 0;			
		REST_slave = 0;
		ST_REST = 0;		
	end

		// Счетчик задержки
	always @(posedge CLK_IN)
	begin
		if (REST_master)
		begin
			ST_REST  <= ST_REST;
		end		
		else
		begin
			ST_REST  <= ST_REST +1 ;
		end
	end
	
	always @(posedge CLK_IN)
	begin
		if (ST_REST > 224) 
		begin
			REST_master  <= 1;
		end
		else
		begin
			REST_master  <= 0;
		end
	end	
		
	always @(posedge CLK_IN)
	begin
		if (ST_REST < 154) 
		begin
			REST_slave  <= 0;
		end
		else if (REST_master & MASTER_OK) 
		begin
			REST_slave  <= 1;
		end
		else
		begin
			REST_slave  <= REST_slave;
		end
	end	
	 

endmodule
