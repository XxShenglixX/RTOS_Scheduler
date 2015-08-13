#include "Button.h"


int isButtonPressed()
{
	GPIO_PinState UserInput = 0;
	UserInput = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);

	if (UserInput == 1)
		return 1 ;
	else
		return 0 ;
}
