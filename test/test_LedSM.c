#define IsTestCode
#include "unity.h"
#include "LedSM.h"
#include "Message.h"
#include "mock_LED.h"
#include "mock_Timer.h"
#include "mock_Button.h"

#include "stm32f4xx_hal_gpio.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void test_LedSM_should_change_state_to_LED_BLINKING_ON_when_receive_message_CHANGE_MODE___INITIAL_LED_OFF()
{
	LedData ledData ; 
	ledInitData(&ledData);

	msg = DO_NOTHING ;
	
	turnOffLED_Expect(LED3);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);

 	msg = CHANGE_MODE;
	
	turnOffLED_Expect(LED3);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_ON); 
}

void test_LedSM_should_change_state_to_LED_BLINKING_OFF_and_reset_timer_when_timer_expires___INITIAL_LED_BLINKING_ON()
{
	LedData ledData ; 
	ledData.state = LED_BLINKING_ON ;
	
	msg = DO_NOTHING ;
	
	turnOnLED_Expect(LED3);
	checkTime_ExpectAndReturn(500,LED3,0);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_ON);
	
	turnOnLED_Expect(LED3);
	checkTime_ExpectAndReturn(500,LED3,1);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_OFF);
	
}

void test_LedSM_should_change_state_to_LED_BLINKING_ON_and_reset_timer_when_timer_expires___INITIAL_LED_BLINKING_OFF()
{
	LedData ledData ; 
	ledData.state = LED_BLINKING_OFF ;
	
	msg = DO_NOTHING ;
	
	turnOffLED_Expect(LED3);
	checkTime_ExpectAndReturn(500,LED3,0);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_OFF);
	
	turnOffLED_Expect(LED3);
	checkTime_ExpectAndReturn(500,LED3,1);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_BLINKING_ON);
	
}

void test_LEDSM_should_change_state_to_LED_ON_when_receive_message_CHANGE_MODE___INITIAL_LED_BLINKING_ON()
{
	LedData ledData ; 
	ledData.state = LED_BLINKING_ON ;
	
	msg = CHANGE_MODE;
	
	turnOnLED_Expect(LED3);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_ON);
}

void test_LEDSM_should_change_state_to_LED_ON_when_receive_message_CHANGE_MODE___INITIAL_LED_BLINKING_OFF()
{
	LedData ledData ; 
	ledData.state = LED_BLINKING_OFF ;
	
	msg = CHANGE_MODE;
	
	turnOffLED_Expect(LED3);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_ON);
}

void test_LEDSM_should_change_state_to_LED_OFF_when_receive_message_CHANGE_MODE__INITIAL_LED_ON()
{
	LedData ledData ; 
	ledData.state = LED_ON ;
	
	msg = CHANGE_MODE;
	turnOnLED_Expect(LED3);
	ledSM(&ledData);
	TEST_ASSERT_EQUAL(ledData.state,LED_OFF);
}