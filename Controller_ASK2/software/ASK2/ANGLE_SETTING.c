/*
 * SETTING.c
 *
 *  Created on: 10.05.2018
 *      Author: ilnitskaya-ll
 */
#include "sys/alt_stdio.h"
#include "alt_types.h"
#include <io.h>
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include "ACK2_main.h"
#include "LCD.h"
#include "resolver.h"
#include "ANGLE_SETTING.h"
//������� ��������� ����
alt_16 ANGLE_SETTING(alt_16 k)
{
alt_u32 timer;
timer=0;
alt_16 resolver_angle;
alt_u32 perem_cycla;
perem_cycla=0;
if (perem_cycla==0)
    {
    //�������� 0,5�
	while(timer==500000000)timer++;
	//�������� SW_5" (���� ��������� �������)
  	  if (SW5_MASK||IORD_ALTERA_AVALON_PIO_DATA(PIO_KEYBOARD_SW6_SW1_BASE)==0x0)
  	  {
  				  	   Angle_norm++;
  	//������� �� ��� �������� ����
  	  /* ������� �� ���-��������� ���� � ���������� ���������� ������������
  	    				   * (������������ �� 16-���������� ���� � ����
  	    				   * (���*100(� ����� ������� ����� �������)*360/65535,� ������ ������� � 10-�� �������
  	    				   * � ����� ������� ����� �������   				   */

  	    				    //temp = PIO_2_ANGLE_BASE*100*360/65535;
  	    	  LCD_print_digital_number_on_screen (Angle_norm*100*360/65535,9,2);
  	  }//�������� SW_6" (���� ��������� �������)
  	    	  else if (SW6_MASK||IORD_ALTERA_AVALON_PIO_DATA(PIO_KEYBOARD_SW6_SW1_BASE)==0x0)
  	    	  {
  				  		Angle_norm=Angle_norm-1;
  			  LCD_print_digital_number_on_screen (Angle_norm*100*360/65535,9,2);
  		       }
  	    	 if (((SW5_MASK||(IORD_ALTERA_AVALON_PIO_DATA(PIO_KEYBOARD_SW6_SW1_BASE)))==0x01)&&((SW6_MASK||IORD_ALTERA_AVALON_PIO_DATA(PIO_KEYBOARD_SW6_SW1_BASE)==0x01)))
  	    		perem_cycla=1;
  	    			else
  	    		perem_cycla=0;
	}
	return (Angle_norm);
}
 //����� �������  alt_16 ANGLE_SETTING(alt_16 k)
//������� ��������� ����
alt_16 CURRENT_SETTING(alt_16 k)
{
alt_u32 timer;
timer=0;
alt_u32 perem_cycla;
perem_cycla=0;
if (perem_cycla==0)
{
 //�������� 0,5�
	while(timer==500000000) timer++;
 	//�������� SW_5" (���� ��������� �������)
  	  if (SW5_MASK||IORD_ALTERA_AVALON_PIO_DATA(PIO_KEYBOARD_SW6_SW1_BASE)==0x0)
  	  {
  		Current_norm++;
  	//������� �� ��� �������� ����
  	  /* ������� �� ���-��������� ���
  	    * (������������ �� 16-���������� ���� � ����
  	    * (���*100(� ����� ������� ����� �������)*360/65535,� ������ ������� � 10-�� �������
  	    * � ����� ������� ����� �������   				   */

  	    				    //temp = PIO_2_ANGLE_BASE*100*360/65535;
  	    	  LCD_print_digital_number_on_screen (Current_norm*100*360/65535,9,2);
  	    	  timer=0;
  	  }//�������� SW_6" (���� ��������� �������)
  	    	  else if (SW6_MASK||IORD_ALTERA_AVALON_PIO_DATA(PIO_KEYBOARD_SW6_SW1_BASE)==0x0)
  	    	  {
  	    		Current_norm=Current_norm-1;
  			  LCD_print_digital_number_on_screen (Current_norm*100*360/65535,9,2);
  		      timer=0;
  	    	  }
  	    	 if (((SW5_MASK||(IORD_ALTERA_AVALON_PIO_DATA(PIO_KEYBOARD_SW6_SW1_BASE)))==0x01)&&((SW6_MASK||IORD_ALTERA_AVALON_PIO_DATA(PIO_KEYBOARD_SW6_SW1_BASE)==0x01)))
  	    		perem_cycla=0;
  	    			else
  	    				perem_cycla=1;
}
 return (Current_norm);
 }
    //����� �������  alt_16 CURRENT_SETTING(alt_16 k)
//������� ��������� ������
alt_u8 MODE_FORMATION(void)
{
	alt_32 timer;
if (SW2_MASK||IORD_ALTERA_AVALON_PIO_DATA(PIO_KEYBOARD_SW6_SW1_BASE)==0x1)
  			   {
  				  		  if(SW1_MASK||IORD_ALTERA_AVALON_PIO_DATA(PIO_KEYBOARD_SW6_SW1_BASE)==0x0)
  				  		  {
  				  			  //���������� ����� ������ setting_mode=1
  				  		        setting_mode=1;
  				  		   //�������� ���� LED1
  				  		     IOWR_ALTERA_AVALON_PIO_DATA(PIO_LED2_LED1_BASE,0x1);
  				  		   //���������� ��������� ��������
  				  		while (timer==25000000)	//�������� SW_1" (���� ��������� �������)
  				  		{

  				  	 if (SW1_MASK||IORD_ALTERA_AVALON_PIO_DATA(PIO_KEYBOARD_SW6_SW1_BASE)==0x0)
  				  		timer=0;
  				  	 else
  				  	   timer++;
  				  	    }
  				  		//����������� ������ ������ �� ��� �������
  				  	 Out_WORKING();
  			  	  }  				  		    				  	  }
  		else
  				  {
  				  	     //���������� ����� ��������� setting_mode=0
  				  	       setting_mode=0;
  				  	   	 //��������� ���� LED1 � �������� ���� LED2
  				  	   	   IOWR_ALTERA_AVALON_PIO_DATA(PIO_LED2_LED1_BASE,0x2);
  				  	  if (SW3_MASK||IORD_ALTERA_AVALON_PIO_DATA(PIO_KEYBOARD_SW6_SW1_BASE)==0x1)
  				  	  {
  				  		  if (SW4_MASK||IORD_ALTERA_AVALON_PIO_DATA(PIO_KEYBOARD_SW6_SW1_BASE)==0x0)
  				   //���������� ����� "��������� ����"
  				  			 setting_mode=2;
  				  	  }
  				  	  else
  				  //���������� ����� "��������� ����"
  				  			  setting_mode=3;
  				    }
  		return (setting_mode);
   }
 //����� ������� alt_u8 MODE_FORMATION(void)

