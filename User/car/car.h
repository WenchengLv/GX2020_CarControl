#ifndef __CAR_H
#define __CAR_H

#include "stm32f10x.h"
#include "bsp_GeneralTim.h" 
#include "bsp_adc.h"
#include "bsp_usart.h"


#define chartonumber(x) (x-'0')
#define Desired_Number   6300

void CAR_Down(u8 step);
void CAR_Go(u8 step);
void CAR_Left(u8 step);
void CAR_Right(u8 step);
#endif
