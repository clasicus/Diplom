#include "sys/alt_stdio.h"
#include "alt_types.h"
#include <io.h>
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include "ACK2_main.h"
#include "LCD.h"
#include "resolver.h"
#include "ANGLE_SETTING.h"
//alt_16 X[10];
// alt_32 Y[10];
//alt_16 position;
 alt_16 Angle_norm;
 alt_16 Current_norm;
 alt_u8 setting_mode;

int main()
{ 
  //int count = 0;
  //int delay;
#ifdef ALT_DEBUG
  alt_putstr("Hello from Nios II!\n");
#endif
  alt_u8 fault_reg;
  alt_16 resolver_angle;
//alt_32 timer;
  alt_u8 k;
  alt_16  Current_temp;
 // alt_16 Pwm_out;

  //инициализация
 /* Resolver_initialization();
  LCD_INITIALIZATION();
  Angle_norm=0;
  Current_norm=0;
  k=0;
  while(1)
     {

 fault_reg= Resolver_read_byte_config_mode (RES_ADDR_FAULT_REG);
 //если регистр не выдает ошибку, то читаем угол с резольвера
 if (fault_reg == 0) 	//читаем угол с резольвера
 resolver_angle=Resolver_read_position_in_normal_mode();
 if (k==0)
 {
 //устанавливаем режим настройки угла
 setting_mode=3;
 Angle_norm=ANGLE_SETTING(Angle_norm);
 //устанавливаем режим настройки тока
 setting_mode=2;
 Current_norm=CURRENT_SETTING(Current_norm);
 k=1;
 }
 else
 {
 //формирование режима
 setting_mode=MODE_FORMATION();
 switch (setting_mode)
    {
 //если выбран режим работа
     case 0:
     {

    	 // выставляем выводы SAMPLE в 0
    	 IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NSAMPLE_BASE,0);
    	 //задержка на 2 us (1 такт процессора 20 нс)после сброса SAMPLE до поднятия SAMPLE
    	 	Delay_for_microsec (2);
    	 // выставляем выводы SAMPLE в 1
    	  IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NSAMPLE_BASE,1);
    	  //задержка на 2 us (1 такт процессора 20 нс)после сброса SAMPLE до поднятия CS
    	   	Delay_for_microsec (2);
    	  //чтение регистра ошибки
    	 //прочитать угол с резольвера
    	 //чтение регистра ошибки
    	  fault_reg= Resolver_read_byte_config_mode (RES_ADDR_FAULT_REG);
    	  //если регистр не выдает ошибку, то читаем угол с резольвера
    	  if (fault_reg == 0) 	//читаем угол с резольвера
    	  resolver_angle=Resolver_read_position_in_normal_mode();
    	  else
    	 	 Out_ERROR_RESOLVER();	//Печатаем слово ERROR_RESOLVER
    	 //прочитать ток двигателя с АЦП
    	  Current_temp=IORD_ALTERA_AVALON_PIO_DATA(PIO_SDO_ADC_BASE);
    	  //выдаем на PWM значение померянного тока(из режима настройки тока)
    	  IOWR_ALTERA_AVALON_PIO_DATA(PIO_PWM_IN_BASE,Current_norm);
    	  //отобразить на ЖКИ режим работа
    	   Out_WORKING();
     }
      break;
      //если выбран режим настройка  тока
      case 2:
    	  CURRENT_SETTING(Current_norm);
    	  break;
    	  //если выбран режим настройка  угла
      case 3:
    	  Angle_norm=ANGLE_SETTING(Angle_norm);
    	  break;
    }
 k=1;
 }
  	 */ return 0;
  	   getchar();
// }	//END WHILE(1)
} //END MAIN()
void Delay_for_microsec (alt_u32 amount_us)
 {
    int i;

 //дисассемблирование показало,что процессор на выполнение этого цикла тратит 9 тактов
   // время одного такта CPU_CYCLE_DELAY_nS =20нс, поэтому время выполнения цикла = 20*9=190нс
   //amount_us-количество микросекунд задержки.Минимальная задержка 1 микросекунда.
   // (1000*MILI/(DELAY_KOEFF))-пример задания аргумента функции , если необходима задержка
   //в микросекундах, то (число*MICRO/(DELAY_KOEFF))

      for (i=0;i<(amount_us);i++);
 }
