module pwm_ver
(
input wire  i_clk,      //входная частота 60 МГц,чтобы fшима = 30кГц=i_clk/Pwm_in
input wire RESET,        //Входной RESET
input wire [11:0] Pwm_in,//управление Шимом 
input wire [15:0] I_max,  //максимальный ток с АЦП, выше которого ШИМ обнуляем 
input wire [15:0] I_in,   //входной ток АЦП   
   
 
output wire   PWM_out,   	//выход ШИМ-формирователя
output reg  [10:0] Count, //выход счетчика 
output reg   DIR, // направление ШИМа
output reg   OFF  //выключение ШИМа
);

//wire clk;
//reg d_clk;
//wire t_clk;
reg t_count;
reg [10:0] Pwm_in_reg; //модуль ШИМа
reg [15:0] I_in_mod; //модуль входного тока
//reg t_pwm = 1'b0;
reg PWM;
//находим модуль входного ШИМа в конце периода
always @ (negedge RESET or posedge(Count==2000))
	begin
         if(!RESET)
			Pwm_in_reg <= 11'b0;
		else if (Pwm_in[11])
			begin
			Pwm_in_reg[10:0]=(~Pwm_in[10:0])+1;
			DIR=1;
			end
		else
			begin
		   Pwm_in_reg[10:0]=Pwm_in[10:0];
         DIR=0;
			end
	end
 //описание счетчика 
always @ (posedge i_clk or negedge RESET)
	begin
		if (!RESET)  
			Count <= 11'b0;
		else 
			Count <= Count+1;
	end
//	//делим входную частоту на 2
//	 always @(posedge i_clk)
//    begin
//      if (!RESET)
//        d_clk <= 1'b0;
//      else
//        d_clk <= ~d_clk;
//    end
// находим модуль входного тока с АЦП
	 always @(posedge i_clk)
    begin
      if (!RESET)
        I_in_mod <= 16'b0;
		  	else if (I_in[15])
			begin
			I_in_mod[15]=0;
			I_in_mod[14:0]=(~I_in[14:0])+1;
			end
		   else
			begin
		   I_in_mod[15:0]=I_in[15:0];
        	end
     end
		 //выбор частоты , если число порога больше, чем входной ШИМ,
	 //то i_clk, в противном случае d_clk
 // assign t_clk = (Pwm_in > I_max) ? i_clk : d_clk;
 // assign clk = i_clk;
 //формируем ШИМ (если ток АЦП > максимального,то обнуляем ШИМ
  always @(posedge i_clk or negedge RESET)
    begin
      if (!RESET)
        PWM <= 1'b0;
      else 
			begin
				if (I_in_mod[15:0]>I_max[15:0])
					begin
					PWM <= 1'b0;
					OFF<=1'b1;
					end
					else 
					 begin
						OFF<=0;
						if (Pwm_in_reg < Count)
							PWM <= 1'b1;
						else
							PWM <= 1'b0;
					 end
			end
	end		
//	 //счетчик t_count считает импульсы с меньшей частотой
//		  always @(posedge t_clk)
//    begin
//      if (!RESET ==  1'b0)
//        t_count <= 8'b0;
//      else
//        t_count <= t_count + 1'b1;
//    end
////формируем ШИМ с импульсами с меньшей частотой
//  always @(posedge t_clk)
//    begin
//      if (!RESET == 1'b0)
//        t_pwm <= 1'b0;
//      else
//        if (Pwm_in > t_count)
//          t_pwm <= 1'b1;
//        else
//          t_pwm <= 1'b0;
//    end
// ----- t ^
 assign PWM_out = PWM;
  
endmodule
