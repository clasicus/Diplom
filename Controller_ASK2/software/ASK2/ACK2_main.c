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

  //�������������
 /* Resolver_initialization();
  LCD_INITIALIZATION();
  Angle_norm=0;
  Current_norm=0;
  k=0;
  while(1)
     {

 fault_reg= Resolver_read_byte_config_mode (RES_ADDR_FAULT_REG);
 //���� ������� �� ������ ������, �� ������ ���� � ����������
 if (fault_reg == 0) 	//������ ���� � ����������
 resolver_angle=Resolver_read_position_in_normal_mode();
 if (k==0)
 {
 //������������� ����� ��������� ����
 setting_mode=3;
 Angle_norm=ANGLE_SETTING(Angle_norm);
 //������������� ����� ��������� ����
 setting_mode=2;
 Current_norm=CURRENT_SETTING(Current_norm);
 k=1;
 }
 else
 {
 //������������ ������
 setting_mode=MODE_FORMATION();
 switch (setting_mode)
    {
 //���� ������ ����� ������
     case 0:
     {

    	 // ���������� ������ SAMPLE � 0
    	 IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NSAMPLE_BASE,0);
    	 //�������� �� 2 us (1 ���� ���������� 20 ��)����� ������ SAMPLE �� �������� SAMPLE
    	 	Delay_for_microsec (2);
    	 // ���������� ������ SAMPLE � 1
    	  IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NSAMPLE_BASE,1);
    	  //�������� �� 2 us (1 ���� ���������� 20 ��)����� ������ SAMPLE �� �������� CS
    	   	Delay_for_microsec (2);
    	  //������ �������� ������
    	 //��������� ���� � ����������
    	 //������ �������� ������
    	  fault_reg= Resolver_read_byte_config_mode (RES_ADDR_FAULT_REG);
    	  //���� ������� �� ������ ������, �� ������ ���� � ����������
    	  if (fault_reg == 0) 	//������ ���� � ����������
    	  resolver_angle=Resolver_read_position_in_normal_mode();
    	  else
    	 	 Out_ERROR_RESOLVER();	//�������� ����� ERROR_RESOLVER
    	 //��������� ��� ��������� � ���
    	  Current_temp=IORD_ALTERA_AVALON_PIO_DATA(PIO_SDO_ADC_BASE);
    	  //������ �� PWM �������� ����������� ����(�� ������ ��������� ����)
    	  IOWR_ALTERA_AVALON_PIO_DATA(PIO_PWM_IN_BASE,Current_norm);
    	  //���������� �� ��� ����� ������
    	   Out_WORKING();
     }
      break;
      //���� ������ ����� ���������  ����
      case 2:
    	  CURRENT_SETTING(Current_norm);
    	  break;
    	  //���� ������ ����� ���������  ����
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

 //������������������ ��������,��� ��������� �� ���������� ����� ����� ������ 9 ������
   // ����� ������ ����� CPU_CYCLE_DELAY_nS =20��, ������� ����� ���������� ����� = 20*9=190��
   //amount_us-���������� ����������� ��������.����������� �������� 1 ������������.
   // (1000*MILI/(DELAY_KOEFF))-������ ������� ��������� ������� , ���� ���������� ��������
   //� �������������, �� (�����*MICRO/(DELAY_KOEFF))

      for (i=0;i<(amount_us);i++);
 }
