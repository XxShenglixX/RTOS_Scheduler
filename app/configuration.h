#ifndef configuration_H
#define configuration_H

#ifndef TEST
#include "stm32f4xx_hal.h"
#endif
#include "stm32f4xx_hal_gpio.h"

void initLED();
void configButton();

#endif // configuration_H
