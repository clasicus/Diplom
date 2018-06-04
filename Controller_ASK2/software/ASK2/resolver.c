#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include "alt_types.h"
#include "resolver.h"
#include "ACK2_main.h"

//struct resolver_struct resolver_data_y = {0,0,0};
//struct resolver_struct resolver_data_z = {0,0,0};
//------------------------------------------------------------
//�������, ������������  ����
// ������-8 ��� ��� ������ ������������ 
//------------------------------------------------------------   
void Resolver_write_byte_config_mode (alt_u8 address,alt_u8 data)
{
	alt_u8 i;
// ���������� ������ �1 �0 � ����� ������������
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_A1_A0_BASE,A1_A0_MASK_CONFIGURATION_MODE);
	//��������� ��������������� ���� � ����� ������ (��� 8 �������)
	IOWR_ALTERA_AVALON_PIO_DIRECTION(PIO_ANGLE_BASE,ANGLE_DIRECTION_16BIT_OUTPUT_MASK);
		// ���������� ����� �������� 8 ��� � ����
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_ANGLE_BASE,address);
// ���������� ����� CS � 0
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,0);
	// ���������� ����� nRD � 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NRD_BASE,1);
	// ���������� ����� nWR � 0
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NWR_BASE,0);
	//�������� �� 22 �� (1 ���� ���������� 20 ��)
	for(i=1;i<=2;i++) asm("nop");
	// ���������� ����� nWR � 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NWR_BASE,1);
	// ���������� ����� CS � 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,1);
	//�������� �� 10 ��
	for(i=1;i<=2;i++) asm("nop");
	// ���������� ����� CS � 0
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,0);
	// ���������� ������ 8 ��� � ����
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_ANGLE_BASE,data);
	// ���������� ����� nWR � 0
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NWR_BASE,0);
	// �������� 240 �� ����� ������� ������ � ������� ������
	 Delay_for_microsec (10);
	 // ���������� ����� nWR � 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NWR_BASE,1);
	 	// ���������� ����� CS � 1
	 IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,1);
	 	//�������� �� 620 ��
	  Delay_for_microsec (31);
// ������ ������ �� spi �����  
 //  alt_u8 rdata = IORD_ALTERA_AVALON_SPI_RXDATA(SPI_RESOLVER_BASE);
//   return rdata;
} // �����  Resolver_write_byte_config_mode
//------------------------------------------------------------
//�������, ����������� �� �����   resolver ����
// ������-8 ��� ��� ������ ������������   
//------------------------------------------------------------  
alt_u8 Resolver_read_byte_config_mode (alt_u8 address) 
{
	alt_u8 i;
 // ������ ������ �  ����
	// ���������� ������ �1 �0 � ����� ������������
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_A1_A0_BASE,A1_A0_MASK_CONFIGURATION_MODE);
		//��������� ��������������� ���� � ����� ������ (��� 8 �������)
	 IOWR_ALTERA_AVALON_PIO_DIRECTION(PIO_ANGLE_BASE,ANGLE_DIRECTION_16BIT_OUTPUT_MASK);
		// ���������� ����� �������� 8 ��� � ����
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_ANGLE_BASE,address);
	// ���������� ����� CS � 0
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,0);
		// ���������� ����� nRD � 1
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NRD_BASE,1);
	// ���������� ����� nWR � 0
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NWR_BASE,0);
		//�������� �� 22 �� (1 ���� ���������� 20 ��)
		for(i=1;i<=2;i++) asm("nop");
		// ���������� ����� nWR � 1
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NWR_BASE,1);
		// ���������� ����� CS � 1
	        //	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,1);
		//�������� �� 10 ��
		for(i=1;i<2;i++) asm("nop");
		// ���������� ����� CS � 0
		//IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,0);
		// ���������� ����� nRD � 0
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NRD_BASE,0);
		//�������� �� 10 ��
				for(i=1;i<2;i++) asm("nop");
		//��������� ��������������� ���� � ����� ����� (��� 16 ������)
		IOWR_ALTERA_AVALON_PIO_DIRECTION(PIO_ANGLE_BASE,ANGLE_DIRECTION_16BIT_INTPUT_MASK);
		// ������ ������ ��  �����
	    alt_u8 rdata = IORD_ALTERA_AVALON_PIO_DATA(PIO_ANGLE_BASE);
	  //   return rdata;
        return rdata;
}// �����  Resolver_read_byte_config_mode
//----------------------------------------------------------------
//������� ������ �� ��������� ��������������� ����������
//----------------------------------------------------------------
alt_16  Resolver_read_position_in_normal_mode ()
{
	alt_u8 i;
// ���������� ������ SAMPLE � 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NSAMPLE_BASE,1);
	// ���������� ����� nRD � 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NRD_BASE,1);
	//�������� �� 42 �� (1 ���� ���������� 20 ��)
	for(i=1;i<2;i++) asm("nop");
	// ���������� ������ SAMPLE � 0
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NSAMPLE_BASE,0);
	//�������� �� 220 �� (1 ���� ���������� 600 ��)
		Delay_for_microsec (32);
   // ���������� ����� CS � 0
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,0);
	// ���������� ������ �1 �0 � ����� ������ ����
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_A1_A0_BASE,A1_A0_MASK_NORMAL_MODE_POSITION);
	//�������� �� 220 �� (1 ���� ���������� 20 ��)
	Delay_for_microsec (2);
	  // ���������� ����� nWR � 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NWR_BASE,1);
	// ���������� ����� nRD � 0
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NRD_BASE,0);
	//�������� �� 42 �� (1 ���� ���������� 20 ��)
		for(i=1;i<3;i++) asm("nop");
		//��������� ��������������� ���� � ����� ����� (��� 16 ������)
	IOWR_ALTERA_AVALON_PIO_DIRECTION(PIO_ANGLE_BASE,ANGLE_DIRECTION_16BIT_INTPUT_MASK);
		//������ �������� ����
	alt_u16 rdata =IORD_ALTERA_AVALON_PIO_DATA(PIO_ANGLE_BASE);
	alt_16 position= rdata-32760;
		//  var.u= var.u^0x8000;
		 //  p-> position=var.i;
		   //�������� �� 100 �� (1 ���� ���������� 20 ��)
	for(i=1;i<5;i++) asm("nop");
		   // ���������� ����� CS � 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,1);
		   	// ���������� ����� nRD � 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NRD_BASE,1);
	   	//�������� �� 220 �� (1 ���� ���������� 20 ��)
   	Delay_for_microsec (20);
	   //	return(position);
   	return (position);
}

    //������ ���������� �� �������� ��������� ������� ���
  /// Resolver_write_read_byte_config_mode(RES_ADDR_POSITION_REG_H);
  // var.u = Resolver_write_read_byte_config_mode (RES_ADDR_POSITION_REG_L)<<8;
  // var.u= var.u^0x8000;
  // p-> position=var.i;

//������ ���������� �� �������� ������� ������� ���   
  // p->position = p->position + Resolver_write_read_byte_config_mode (RES_ADDR_VELOCITY_REG_H);
//������ ���������� �� �������� �������� ������� ���   
 //  p->velocity = Resolver_write_read_byte_config_mode (RES_ADDR_VELOCITY_REG_L)<<8;
//   var.u = Resolver_write_read_byte_config_mode (RES_ADDR_VELOCITY_REG_L)<<8;
//   var.u= var.u^0x8000;
//   p-> velocity=var.i;
 //������ ���������� �� �������� �������� ������� ���   
 //  p->velocity =  p->velocity +Resolver_write_read_byte_config_mode (RES_ADDR_FAULT_REG);
//������ ���������� �� �������� ������   
 //  p->fault = Resolver_write_read_byte_config_mode(RES_ADDR_FAULT_REG);

// ����� ������� Resolver_read_position_in_normal_mode ������ �� ��������� ��������������� ����������
//--------------------------------------------------------------------
//������� �������������
alt_u8 Resolver_initialization ()
{
//  alt_u8 Reg_dos_overrange;
//  alt_u8 Reg_dos_mismatch; 
//  alt_u8 Ex_freq;
 // alt_u8 Dos_mismatch_thre;

// ���������� ������ SAMPLE � 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NSAMPLE_BASE,1);
//	 // ���������� ����� nWR � 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NWR_BASE,1);
	 // ���������� ����� nRD � 1
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NRD_BASE,1);
// ���������� ����� CS � 1
	 IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NCS_BASE,1);
	 //���������� ���� �  ����� ������������ ������
	 IOWR_ALTERA_AVALON_PIO_DATA(PIO_RES_NSOE_BASE,1);
 // IOWR_ALTERA_AVALON_PIO_DATA(PIO_MUX_BASE,0 | RESOLVER_MUX_RESOLVER0_MASK);    
   Resolver_write_byte_config_mode (RES_ADDR_CONTROL_REG, 0x0);
// �������������  control �������� ����������   0x7F=111 1111 0x5F= 0101 1111 0xDF 1101 1111
   Resolver_write_byte_config_mode (RES_ADDR_CONTROL_REG, 0xDF);
// �������������   �������� EXCITATION_FREQUENCY_REG ����������   0x21 
// fclkin=10kHz(������ � ����),fexc=33=0x21-- fwc=35=0x23  fexc=10.6kHz3
   Resolver_write_byte_config_mode ( RES_ADDR_EXCITATION_FREQUENCY_REG, 0x21);
//// �������������  Los_threshold_reg =0x39=2,2V/38mv=57,89=ox39   
//   Resolver_write_byte_config_mode (RES_ADDR_LOS_THRESHOLD_REG,0x39,SPI_RESOLVER_BASE);
////// �������������  DOS_OVERRANGE_THRESHOLD_REG = 0x6c=4,104V/38mv=108=0x6c   
//   Resolver_write_byte_config_mode (RES_ADDR_DOS_OVERRANGE_THRESHOLD_REG,0x6c,SPI_RESOLVER_BASE); 
////// �������������  DOS_MISMATCH_THRESHOLD_REG = 0x0a=380mv/38mv=10=0x0a   
//   Resolver_write_byte_config_mode(RES_ADDR_DOS_MISMATCH_THRESHOLD_REG,0x0a,SPI_RESOLVER_BASE);
////// �������������  DOS_RESET_MAX_THRESHOLD_REG = 0x3d = 2,28v/38mv=60=0x3d   
//   Resolver_write_byte_config_mode(RES_ADDR_DOS_RESET_MAX_THRESHOLD_REG,0x3d,SPI_RESOLVER_BASE);
////// ������������� RES_ADDR_DOS_RESET_MIN_THRESHOLD_REG = 0x69=3,99v/38mv=105=0x69   
//   Resolver_write_byte_config_mode(RES_ADDR_DOS_RESET_MIN_THRESHOLD_REG,0x69,SPI_RESOLVER_BASE);
////// �������������  RES_ADDR_LOT_HIGH_THRESHOLD_REG = 0x1b=2,5deg/0,09deg=27,7=0x1b     
//    Resolver_write_byte_config_mode(RES_ADDR_LOT_HIGH_THRESHOLD_REG,0x1b,SPI_RESOLVER_BASE);
////// �������������  RES_ADDR_LOT_LOW_THRESHOLD_REG = 0x05=0,5deg/0,09deg=5,55=0x06     
//    Resolver_write_byte_config_mode(RES_ADDR_LOT_LOW_THRESHOLD_REG,0x06,SPI_RESOLVER_BASE);
//// //   Resolver_write_byte_config_mode ( RES_ADDR_DOS_MISMATCH_THRESHOLD_REG,0x0a);
 //Dos_mismatch_thre = Resolver_read_byte_config_mode(RES_ADDR_DOS_MISMATCH_THRESHOLD_REG);
   // #ifdef ALT_DEBUG
   //    alt_printf("Dos_mismatch_thre= %x\n\n",Dos_mismatch_thre);
 //#endif              
// �������������  control �������� ����������   0x7F=111 1111 0x5F= 0101 1111

   return (1);
}
//����� ������� ������������� Resolver_initialization
//---------------------------------------------------------------------------
//�������,���������� ���������,������������� ��������� � ��������� ����������
//�� ����������
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
//  //������������� ����� SAMPLE � 0 (��� ����������� ������ ������ � ����������)   
//   i=IORD_ALTERA_AVALON_PIO_DATA(PIO_0_BASE);
//   i=i & ~RESOLVER_SAMPLE_MASK;
//   IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,i);
//    asm("nop");
//    asm("nop");
//    //������������� ����� SAMPLE � 1  
//    i=i|RESOLVER_SAMPLE_MASK;
//   IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,i);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
//    asm("nop"); 
   //������������� ����� SAMPLE � 0 (��� ����������� ������ ������ � ����������)   
//   i=IORD_ALTERA_AVALON_PIO_DATA(PIO_0_BASE);
//   i=i & ~RESOLVER_SAMPLE_MASK;
 //  IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,i);
    
 //   for(i=1;i<2;i++) asm("nop");
    //������������� ����� SAMPLE � 1  
 //   i=i|RESOLVER_SAMPLE_MASK;
//   IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,i);
//    asm("nop");
   
  // if (resolver_number == 1)
 //  {
  
    
// ������������� ��������������� ������ CS0  � ����� ������ ����������
// �������� ������ ��������� (CS0 =0)
//   IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, 0 |~RESOLVER_1RES_MASK | RESOLVER_SAMPLE_MASK);
   //�������� ����� ����������� CS � �������
 //    asm ("nop");
   //  asm ("nop");
   
 //�������� SPI_resolver1
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
  // ������������� ��������������� ������ CS2 � ����� ������ ����������
// �������� ������ ��������� (CS2=0)
//   IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, 0 | ~RESOLVER_2RES_MASK | RESOLVER_SAMPLE_MASK);
//    asm("nop");
 //   asm("nop");
    
  //�������� SPI_resolver2
  //IOWR_ALTERA_AVALON_PIO_DATA(PIO_MUX_BASE,0 | RESOLVER_MUX_RESOLVER1_MASK);        
  // Resolver_read_position_velocity_fault (&resolver_data_z);
  //   }
//IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,0 | RESOLVER_CS_NOTHING | RESOLVER_SAMPLE_MASK);
////����� �� ����� ��������� ���������� ������� ���� � �������
 //   alt_printf("Position =  %x \n",resolver_data.position);
////����� �� ����� �������� ���������� ������� ���� � ������� 
 //   alt_printf("velocity =  %x\n",resolver_data.velocity);  
////����� �� ����� �������� ������ ���� ����
 //   alt_printf("fault =  %x \n",resolver_data.fault);
   // return(1);
  //  }
// ����� ������� Reading_resolver
