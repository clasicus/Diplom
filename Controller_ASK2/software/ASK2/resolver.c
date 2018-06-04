#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include "alt_types.h"
#include "resolver.h"
#include "ACK2_main.h"

//struct resolver_struct resolver_data_y = {0,0,0};
//struct resolver_struct resolver_data_z = {0,0,0};
//------------------------------------------------------------
//Функция, записывающая  байт
// данных-8 бит для режима конфигурации 
//------------------------------------------------------------   
void Resolver_write_byte_config_mode (alt_u8 address,alt_u8 data)
{
	alt_u8 i;
// выставляем выводы А1 А0 в режим конфигурации
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_A1_A0_BASE,A1_A0_MASK_CONFIGURATION_MODE);
	//Объявляем двунаправленный порт в режим вывода (все 8 выводов)
	IOWR_ALTERA_AVALON_PIO_DIRECTION(PIO_ANGLE_BASE,ANGLE_DIRECTION_16BIT_OUTPUT_MASK);
		// выставляем адрес регистра 8 бит в порт
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_ANGLE_BASE,address);
// выставляем вывод CS в 0
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,0);
	// выставляем вывод nRD в 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NRD_BASE,1);
	// выставляем вывод nWR в 0
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NWR_BASE,0);
	//задержка на 22 нс (1 такт процессора 20 нс)
	for(i=1;i<=2;i++) asm("nop");
	// выставляем вывод nWR в 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NWR_BASE,1);
	// выставляем вывод CS в 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,1);
	//задержка на 10 нс
	for(i=1;i<=2;i++) asm("nop");
	// выставляем вывод CS в 0
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,0);
	// выставляем данные 8 бит в порт
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_ANGLE_BASE,data);
	// выставляем вывод nWR в 0
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NWR_BASE,0);
	// задержка 240 нс между записью адреса и записью данных
	 Delay_for_microsec (10);
	 // выставляем вывод nWR в 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NWR_BASE,1);
	 	// выставляем вывод CS в 1
	 IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,1);
	 	//задержка на 620 нс
	  Delay_for_microsec (31);
// чтение данных из spi порта  
 //  alt_u8 rdata = IORD_ALTERA_AVALON_SPI_RXDATA(SPI_RESOLVER_BASE);
//   return rdata;
} // конец  Resolver_write_byte_config_mode
//------------------------------------------------------------
//Функция, считывающая из порта   resolver байт
// данных-8 бит для режима конфигурации   
//------------------------------------------------------------  
alt_u8 Resolver_read_byte_config_mode (alt_u8 address) 
{
	alt_u8 i;
 // Запись адреса в  порт
	// выставляем выводы А1 А0 в режим конфигурации
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_A1_A0_BASE,A1_A0_MASK_CONFIGURATION_MODE);
		//Объявляем двунаправленный порт в режим вывода (все 8 выводов)
	 IOWR_ALTERA_AVALON_PIO_DIRECTION(PIO_ANGLE_BASE,ANGLE_DIRECTION_16BIT_OUTPUT_MASK);
		// выставляем адрес регистра 8 бит в порт
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_ANGLE_BASE,address);
	// выставляем вывод CS в 0
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,0);
		// выставляем вывод nRD в 1
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NRD_BASE,1);
	// выставляем вывод nWR в 0
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NWR_BASE,0);
		//задержка на 22 нс (1 такт процессора 20 нс)
		for(i=1;i<=2;i++) asm("nop");
		// выставляем вывод nWR в 1
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NWR_BASE,1);
		// выставляем вывод CS в 1
	        //	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,1);
		//задержка на 10 нс
		for(i=1;i<2;i++) asm("nop");
		// выставляем вывод CS в 0
		//IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,0);
		// выставляем вывод nRD в 0
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NRD_BASE,0);
		//задержка на 10 нс
				for(i=1;i<2;i++) asm("nop");
		//Объявляем двунаправленный порт в режим ввода (все 16 вводов)
		IOWR_ALTERA_AVALON_PIO_DIRECTION(PIO_ANGLE_BASE,ANGLE_DIRECTION_16BIT_INTPUT_MASK);
		// чтение данных из  порта
	    alt_u8 rdata = IORD_ALTERA_AVALON_PIO_DATA(PIO_ANGLE_BASE);
	  //   return rdata;
        return rdata;
}// конец  Resolver_read_byte_config_mode
//----------------------------------------------------------------
//Функция чтения из регистров преобразователя резольвера
//----------------------------------------------------------------
alt_16  Resolver_read_position_in_normal_mode ()
{
	alt_u8 i;
// выставляем выводы SAMPLE в 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NSAMPLE_BASE,1);
	// выставляем вывод nRD в 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NRD_BASE,1);
	//задержка на 42 нс (1 такт процессора 20 нс)
	for(i=1;i<2;i++) asm("nop");
	// выставляем выводы SAMPLE в 0
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NSAMPLE_BASE,0);
	//задержка на 220 нс (1 такт процессора 600 нс)
		Delay_for_microsec (32);
   // выставляем вывод CS в 0
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,0);
	// выставляем выводы А1 А0 в режим чтения угла
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_A1_A0_BASE,A1_A0_MASK_NORMAL_MODE_POSITION);
	//задержка на 220 нс (1 такт процессора 20 нс)
	Delay_for_microsec (2);
	  // выставляем вывод nWR в 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NWR_BASE,1);
	// выставляем вывод nRD в 0
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NRD_BASE,0);
	//задержка на 42 нс (1 такт процессора 20 нс)
		for(i=1;i<3;i++) asm("nop");
		//Объявляем двунаправленный порт в режим ввода (все 16 вводов)
	IOWR_ALTERA_AVALON_PIO_DIRECTION(PIO_ANGLE_BASE,ANGLE_DIRECTION_16BIT_INTPUT_MASK);
		//читаем значение угла
	alt_u16 rdata =IORD_ALTERA_AVALON_PIO_DATA(PIO_ANGLE_BASE);
	alt_16 position= rdata-32760;
		//  var.u= var.u^0x8000;
		 //  p-> position=var.i;
		   //задержка на 100 нс (1 такт процессора 20 нс)
	for(i=1;i<5;i++) asm("nop");
		   // выставляем вывод CS в 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,1);
		   	// выставляем вывод nRD в 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NRD_BASE,1);
	   	//задержка на 220 нс (1 такт процессора 20 нс)
   	Delay_for_microsec (20);
	   //	return(position);
   	return (position);
}

    //чтение информации из регистра положения старший бит
  /// Resolver_write_read_byte_config_mode(RES_ADDR_POSITION_REG_H);
  // var.u = Resolver_write_read_byte_config_mode (RES_ADDR_POSITION_REG_L)<<8;
  // var.u= var.u^0x8000;
  // p-> position=var.i;

//чтение информации из регистра позиции младший бит   
  // p->position = p->position + Resolver_write_read_byte_config_mode (RES_ADDR_VELOCITY_REG_H);
//чтение информации из регистра скорости старший бит   
 //  p->velocity = Resolver_write_read_byte_config_mode (RES_ADDR_VELOCITY_REG_L)<<8;
//   var.u = Resolver_write_read_byte_config_mode (RES_ADDR_VELOCITY_REG_L)<<8;
//   var.u= var.u^0x8000;
//   p-> velocity=var.i;
 //чтение информации из регистра скорости младший бит   
 //  p->velocity =  p->velocity +Resolver_write_read_byte_config_mode (RES_ADDR_FAULT_REG);
//чтение информации из регистра ошибки   
 //  p->fault = Resolver_write_read_byte_config_mode(RES_ADDR_FAULT_REG);

// конец функции Resolver_read_position_in_normal_mode чтения из регистров преобразователь резольвера
//--------------------------------------------------------------------
//функция инициализации
alt_u8 Resolver_initialization ()
{
//  alt_u8 Reg_dos_overrange;
//  alt_u8 Reg_dos_mismatch; 
//  alt_u8 Ex_freq;
 // alt_u8 Dos_mismatch_thre;

// выставляем выводы SAMPLE в 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NSAMPLE_BASE,1);
//	 // выставляем вывод nWR в 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NWR_BASE,1);
	 // выставляем вывод nRD в 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NRD_BASE,1);
// выставляем вывод CS в 1
	 IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,1);
	 //выставляем порт в  режим паралельного чтения
	 IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NSOE_BASE,1);
 // IOWR_ALTERA_AVALON_PIO_DATA(PIO_MUX_BASE,0 | RESOLVER_MUX_RESOLVER0_MASK);    
   Resolver_write_byte_config_mode (RES_ADDR_CONTROL_REG, 0x0);
// инициализация  control регистра резольвера   0x7F=111 1111 0x5F= 0101 1111 0xDF 1101 1111
   Resolver_write_byte_config_mode (RES_ADDR_CONTROL_REG, 0xDF);
// инициализация   регистра EXCITATION_FREQUENCY_REG резольвера   0x21 
// fclkin=10kHz(подана с ПЛИС),fexc=33=0x21-- fwc=35=0x23  fexc=10.6kHz3
   Resolver_write_byte_config_mode ( RES_ADDR_EXCITATION_FREQUENCY_REG, 0x21);
//// инициализация  Los_threshold_reg =0x39=2,2V/38mv=57,89=ox39   
//   Resolver_write_byte_config_mode (RES_ADDR_LOS_THRESHOLD_REG,0x39,SPI_RESOLVER_BASE);
////// инициализация  DOS_OVERRANGE_THRESHOLD_REG = 0x6c=4,104V/38mv=108=0x6c   
//   Resolver_write_byte_config_mode (RES_ADDR_DOS_OVERRANGE_THRESHOLD_REG,0x6c,SPI_RESOLVER_BASE); 
////// инициализация  DOS_MISMATCH_THRESHOLD_REG = 0x0a=380mv/38mv=10=0x0a   
//   Resolver_write_byte_config_mode(RES_ADDR_DOS_MISMATCH_THRESHOLD_REG,0x0a,SPI_RESOLVER_BASE);
////// инициализация  DOS_RESET_MAX_THRESHOLD_REG = 0x3d = 2,28v/38mv=60=0x3d   
//   Resolver_write_byte_config_mode(RES_ADDR_DOS_RESET_MAX_THRESHOLD_REG,0x3d,SPI_RESOLVER_BASE);
////// инициализация RES_ADDR_DOS_RESET_MIN_THRESHOLD_REG = 0x69=3,99v/38mv=105=0x69   
//   Resolver_write_byte_config_mode(RES_ADDR_DOS_RESET_MIN_THRESHOLD_REG,0x69,SPI_RESOLVER_BASE);
////// инициализация  RES_ADDR_LOT_HIGH_THRESHOLD_REG = 0x1b=2,5deg/0,09deg=27,7=0x1b     
//    Resolver_write_byte_config_mode(RES_ADDR_LOT_HIGH_THRESHOLD_REG,0x1b,SPI_RESOLVER_BASE);
////// инициализация  RES_ADDR_LOT_LOW_THRESHOLD_REG = 0x05=0,5deg/0,09deg=5,55=0x06     
//    Resolver_write_byte_config_mode(RES_ADDR_LOT_LOW_THRESHOLD_REG,0x06,SPI_RESOLVER_BASE);
//// //   Resolver_write_byte_config_mode ( RES_ADDR_DOS_MISMATCH_THRESHOLD_REG,0x0a);
 //Dos_mismatch_thre = Resolver_read_byte_config_mode(RES_ADDR_DOS_MISMATCH_THRESHOLD_REG);
   // #ifdef ALT_DEBUG
   //    alt_printf("Dos_mismatch_thre= %x\n\n",Dos_mismatch_thre);
 //#endif              
// инициализация  control регистра резольвера   0x7F=111 1111 0x5F= 0101 1111

   return (1);
}
//конец функции инициализации Resolver_initialization
//---------------------------------------------------------------------------
//функция,выбирающая резольвер,конфигурирует резольвер и считывает информацию
//из резольвера
//---------------------------------------------------------------------------
//alt_u8 Resolver_reading ()
//  {
 // alt_u16 i;
//  alt_u8  Los_threshold;
//  alt_u8  Dos_over_thre;
//  alt_u8  Dos_mismatch_thre;
//  alt_u8  Dos_reset_thre_max;
//  alt_u8 Ex_freq;
//  alt_u8 Dos_reset_thre_min;
//  alt_u8 Lot_high_thre;
//  alt_u8 Lot_low_thre;
//  alt_u8 Control;
//  //Устанавливаем вывод SAMPLE в 0 (для возможности чтения данных с резольвера)   
//   i=IORD_ALTERA_AVALON_PIO_DATA(PIO_0_BASE);
//   i=i & ~RESOLVER_SAMPLE_MASK;
//   IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,i);
//    asm("nop");
//    asm("nop");
//    //Устанавливаем вывод SAMPLE в 1  
//    i=i|RESOLVER_SAMPLE_MASK;
//   IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,i);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
//    asm("nop"); 
   //Устанавливаем вывод SAMPLE в 0 (для возможности чтения данных с резольвера)   
//   i=IORD_ALTERA_AVALON_PIO_DATA(PIO_0_BASE);
//   i=i & ~RESOLVER_SAMPLE_MASK;
 //  IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,i);
    
 //   for(i=1;i<2;i++) asm("nop");
    //Устанавливаем вывод SAMPLE в 1  
 //   i=i|RESOLVER_SAMPLE_MASK;
//   IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,i);
//    asm("nop");
   
  // if (resolver_number == 1)
 //  {
  
    
// устанавливаем конфигуровочные выводы CS0  в режим выбора резольвера
// выбираем первый резольвер (CS0 =0)
//   IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, 0 |~RESOLVER_1RES_MASK | RESOLVER_SAMPLE_MASK);
   //задержка после выставления CS в единицу
 //    asm ("nop");
   //  asm ("nop");
   
 //Включаем SPI_resolver1
//  IOWR_ALTERA_AVALON_PIO_DATA(PIO_MUX_BASE,0 | RESOLVER_MUX_RESOLVER0_MASK);     
 //   Resolver_read_position_velocity_fault (&resolver_data_y);
//    Los_threshold = Resolver_read_byte_config_mode(RES_ADDR_LOS_THRESHOLD_REG);
//    Dos_over_thre =  Resolver_read_byte_config_mode (RES_ADDR_DOS_OVERRANGE_THRESHOLD_REG); 
//    Dos_mismatch_thre = Resolver_read_byte_config_mode(RES_ADDR_DOS_MISMATCH_THRESHOLD_REG);
//    Dos_reset_thre_max =  Resolver_read_byte_config_mode (RES_ADDR_DOS_RESET_MAX_THRESHOLD_REG);
//    Dos_reset_thre_min = Resolver_read_byte_config_mode(RES_ADDR_DOS_RESET_MIN_THRESHOLD_REG);
//    Lot_high_thre =  Resolver_read_byte_config_mode (RES_ADDR_LOT_HIGH_THRESHOLD_REG); 
//    Lot_low_thre = Resolver_read_byte_config_mode(RES_ADDR_LOT_LOW_THRESHOLD_REG);
//    Ex_freq =  Resolver_read_byte_config_mode (RES_ADDR_EXCITATION_FREQUENCY_REG);
//    Control =  Resolver_read_byte_config_mode (RES_ADDR_CONTROL_REG);
//   #ifdef ALT_DEBUG
//   //  alt_printf("Los_thr = %x, DOS_ov_thr =%x,Dos_mismatch_thre= %x,Dos_reset_max = %x\n\n", Los_threshold,Dos_over_thre,Dos_mismatch_thre,Dos_reset_thre_max);
//   #endif              
//   #ifdef ALT_DEBUG
//   //    alt_printf("Dos_res_min = %x, Lot_high_thre =%x,Lot_low_thre= %x,Ex_freq = %x,cont=%x\n\n", Dos_reset_thre_min,Lot_high_thre,Lot_low_thre,Ex_freq,Control);
//   #endif                   
 //  }
//    if (resolver_number == 2)
  //   {
  // устанавливаем конфигуровочные выводы CS2 в режим выбора резольвера
// выбираем второй резольвер (CS2=0)
//   IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, 0 | ~RESOLVER_2RES_MASK | RESOLVER_SAMPLE_MASK);
//    asm("nop");
 //   asm("nop");
    
  //Включаем SPI_resolver2
  //IOWR_ALTERA_AVALON_PIO_DATA(PIO_MUX_BASE,0 | RESOLVER_MUX_RESOLVER1_MASK);        
  // Resolver_read_position_velocity_fault (&resolver_data_z);
  //   }
//IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,0 | RESOLVER_CS_NOTHING | RESOLVER_SAMPLE_MASK);
////вывод на экран положения резольвера старший байт и младший
 //   alt_printf("Position =  %x \n",resolver_data.position);
////вывод на экран скорости резольвера старший байт и младший 
 //   alt_printf("velocity =  %x\n",resolver_data.velocity);  
////вывод на экран регистра ошибки один байт
 //   alt_printf("fault =  %x \n",resolver_data.fault);
   // return(1);
  //  }
// конец функции Reading_resolver
