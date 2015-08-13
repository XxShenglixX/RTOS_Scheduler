#define __TEST_CODE
#include "unity.h"
#include "Message.h"
#include "ButtonSM.h"
#include "LedSM.h"
#include "mock_LED.h"
#include "mock_Timer.h"
#include "mock_Button.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/* void test_message_passsing_given_send_a_message_LedState_should_change_to_LED_BLINKING_ON()
{
	LedData ledData ; ButtonData buttonData ;
	
	ledInitData(&ledData);
	buttonInitData(&buttonData);
	
	turnOffLED_Expect();
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
	
	isButtonPressed_ExpectAndReturn(true);
	buttonSM(&buttonData);
	
	turnOffLED_Expect();
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_ON);
}  */