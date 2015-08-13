#ifndef LED_H
#define LED_H

#ifndef TEST
#include "stm32f4xx_hal.h"
#endif
#include "stm32f4xx_hal_gpio.h"

enum {
				LED3 = 0,
				LED4,
				LED5,
				LED6
};

void turnOffLED(int LED);
void turnOnLED(int LED);

#endif // LED_H
