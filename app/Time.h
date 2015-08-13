#ifndef Time_H
#define Time_H

#ifndef TEST
#include "stm32f4xx_hal.h"
#endif
#include "stm32f4xx_hal_gpio.h"

#define _10ms 100
#define _12ms 120
#define _20ms 200
#define _50ms 500
#define _100ms 1000
#define _200ms 2000

void updateCurrentTime();
int checkTime(int Time_LED,int LED_no);
uint32_t getCurrentTime();

#endif // Time_H
