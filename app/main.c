#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "main.h"
#include "configuration.h"
#include "Time.h"
#include "LED.h"
#include "LedSM.h"
#include "ButtonSM.h"
#include "State.h"
#include "Message.h"
#include "Task.h"
#include "LinkedList.h"

void testFunc(void);
int dummy (int value)
{
	return value * 3 ;
}



int main(void)
{
	initTcb();
	initLED();
	configButton();

	initSysTick();
	taskswitch();

	while(1)
	{

	}


}



void initSysTick()
{
	if(SysTick_Config(SystemCoreClock / 1000))
	{
		while(1);
	}

}

