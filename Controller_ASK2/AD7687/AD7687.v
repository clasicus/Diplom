//--Программа запуска и чтения АЦП AD7687-16--
//написанный Ильницкой Л.Л. 05.2018г.
module AD7687
(
//input wire BUSY, 
input wire RESET,
input wire CLK,
input wire DATA_IN,//выходы АЦП

output reg CNV,//входа АЦП
output wire SCK,
output reg [4:0] ST,
output reg [15:0] SHIFT_REG_REC,
output reg [15:0]DATA_OUT_ADC
);
//input wire SDO_ADC,
//output reg  SDI_ADC,//вход АЦП
//output wire RESET_OUT,//выходной резет
//output reg [7:0]SHIFT_REG_TRANS,
//output reg [7:0]CONFIGURATION_WORD,//слова, задающие режимы работы АЦП
//output reg [15:0]DATA_OUT_DAC1,
//output reg [15:0]DATA_OUT_DAC2,
//output reg [15:0]DATA_OUT_DAC3,
//output reg [7:0]DATA_C7_C0,
//tput reg [3:0] DATA_A,
//utput reg DATA_SOS,
//output reg [1:0] DATA_R1_R0


reg enable;
//reg [1:0] ST_1;
reg [2:0] state;
wire HOLD_CLK,HOLD_CLK2,HOLD_CLK3,HOLD_CLK1;
//ss mashine с состоянием S1,S2,S3,S4,S5,S6
parameter S0=3'b000, S1=3'b001, S2=3'b010, S3=3'b011, S4=3'b100, S5=3'b101, S6=3'b110;
//вводим Lcell , чтобы избавиться от гонок в SCK, который переключается по состоянию S5
LCELL HOLD_1CLK (.in(CLK), .out(HOLD_CLK));  
LCELL HOLD_2CLK (.in(HOLD_CLK),.out(HOLD_CLK1));
LCELL HOLD_3CLK (.in(HOLD_CLK1), .out(HOLD_CLK2));  
LCELL HOLD_4CLK (.in(HOLD_CLK2),.out(HOLD_CLK3));


wire wireCLK;
initial 
begin
 ST <= 0;//присваиваем начальные значения регистрам
 //ST_1 <= 2'b0;
 state<=3'b0;
 enable<=0;
 CNV<=0;
 SHIFT_REG_REC<=0;
 DATA_OUT_ADC<=0;
  
end
//описание счетчика ST для подсчета принятых SPI бит(16)
//счетчик обнуляется по !RESET 
always @(posedge CLK or negedge RESET)
begin
	if (!RESET)
		ST<=1'b0;
		else if (enable ==1'b0 || (state==S0))
		ST<=1'b0;
		else if (enable ==1'b1)
		ST<=ST+1'b1;
	end

//организация клока для SPI
//ssign SCK= (state ==S5) ?(~CLK) : 1'b1;
 
assign  wireCLK = (state==S5) ? (~HOLD_CLK3) : 1'b1;		
assign SCK = wireCLK;	
//описание сдвигового регистра получателя
	always@(negedge SCK)
	begin 
		if(!RESET)
			SHIFT_REG_REC<=0;
		else if (state==S5)
			begin
				SHIFT_REG_REC[15:0]<= {SHIFT_REG_REC[14:0], DATA_IN};
				//SHIFT_REG_REC[0]<=DATA_IN;
			end	
	end
	always@(posedge CLK)
			begin 
				if (state==S6)
					begin					
					DATA_OUT_ADC=SHIFT_REG_REC[15:0];//сохраняем померянное значение
					end
			end		
	//описание машины состояния устройства
		always@(posedge CLK)
			begin
				if(!RESET)//исходное состояние -обнуляем счетчик и сдвиговый регистр приемника
					state<=S0;
				else 
				case(state)
					S0:
						state<=S1;
					S1://если DATA_IN=1 переходим в состояние  S2, иначе возвращаемся в S0 
					begin
						if(!DATA_IN)
						state<=S0;
						else
						state<=S2;
					end						
					S2:	
						state<=S3;
					S3://если ложное срабатывание DATA_IN(0 после 1)- сидим в S3, иначе переход в S4						
						begin
							if(!DATA_IN)
							state<=S3;
							else
							state<=S4;
						end
					S4:
						state<=S5;
					S5:
					begin
						if(ST<15)
							state<=S5;//выдача SCK, считывание D15..D0
						else
							state<=S6;//возврат в состояние  S0
					end		
					S6:
					begin
					if (ST<30)
						state<=S6;
						else
						state<=S0;
					end	
						default: state<=S0;// значение по умолчанию
				endcase
			end
		always@(posedge CLK) //разрешение на включение шифтового регистра
			begin
				if(state==S5 || state==S6)
					enable<=1;
				else
					enable<=0;
			end
	//операции CNV в конечном автомате
		always@(posedge CLK or negedge RESET)
			begin
			    if(!RESET)
			    CNV<=0;
				else if(state==S6)
				   CNV<=0;
				else
					CNV<=1;
			end
	
//assign port_b = ST;
//assign port_a = ST_1;
//assign RESET_OUT = RESET;
//assign sr_out = SHIFT_REG_REC[15];
//assign sr_in =	SHIFT_REG_TRANS[7];				
	endmodule			
				