/*
 * ANGLE_SETTING.h
 *
 *  Created on: 10.05.2018
 *      Author: ilnitskaya-ll
 */

#ifndef ANGLE_SETTING_H_
#define ANGLE_SETTING_H_
#define SW1_MASK  1
#define SW2_MASK  2    //10
#define SW3_MASK  4    //100
#define SW4_MASK  8	     //1000
#define SW5_MASK  16    //10000
#define SW6_MASK  20    //100000
//������� ��������� ����
alt_16 ANGLE_SETTING(alt_16 k);
//������� ��������� ����
alt_16 CURRENT_SETTING(alt_16 k);
extern alt_16 Angle_norm;
extern alt_16 Current_norm;
extern alt_u8 setting_mode;
#endif /* ANGLE_SETTING_H_ */