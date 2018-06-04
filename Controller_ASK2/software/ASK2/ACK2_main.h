/*
 * hello_world.h
 *
 *  Created on: 4 вер. 2017
 *      Author: Администратор
 */

#ifndef ACK1_MAIN_H_
#define ACK1_MAIN_H_
#define MASK_D1  0x1E // 11110
#define MASK_D2  0x1D // 11101
#define MASK_D3  0x1B // 11011
#define MASK_D4  0x17 // 10111
#define MASK_D5  0xF //   1111
#define E1_E2MASK 0x3 // 0011
#define E3_E4MASK 0xC // 1100
extern alt_16 Angle_norm;
extern alt_16 Current_norm;
extern alt_u8 setting_mode;
void Delay_for_microsec (alt_u32 amount_us);

#endif /* ACK1_MAIN_H_ */

