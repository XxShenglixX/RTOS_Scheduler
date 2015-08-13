#include "ButtonSM.h"
#include "Message.h"
#include "LED.h"
#include "Time.h"
#include "Button.h"

void buttonInitData(ButtonData *data)
{
	data -> state = RELEASE;
}



void buttonSM(ButtonData *data)
{
	switch (data->state)
	{
		case RELEASE	:	
							if (isButtonPressed() == 1)
							{
								msg = CHANGE_MODE; // Pass the message to LED
								data->state = PRESS ;
							}
							break ;
		
		case PRESS		:	
							if (isButtonPressed() == 0)
								data->state = RELEASE ;
							
							break ;
	
		default 		:	 
							//printf("Error : unknown state encountered in buttonSM : %d\n",data->state);
							break ;
	}
}
