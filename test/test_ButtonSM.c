#include "unity.h"
#include "ButtonSM.h"
#include "Message.h"
#include "mock_LED.h"
#include "mock_Timer.h"
#include "mock_Button.h"


void setUp(void)
{
}

void tearDown(void)
{
}

void test_ButtonSM_should_change_state_to_PRESS__and_change_msg_when_button_is_pressed_INITIAL_RELEASE()
{
	ButtonData buttonData ;
	buttonInitData(&buttonData);
	
	TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
	
	isButtonPressed_ExpectAndReturn(true);
	buttonSM(&buttonData);
	
	TEST_ASSERT_EQUAL(buttonData.state,PRESS);
	TEST_ASSERT_EQUAL(msg,CHANGE_MODE);
}

void test_ButtonSM_should_remain_at_state_RELEASE_when_button_is_released_INITIAL_RELEASE()
{
	ButtonData buttonData ;
	buttonInitData(&buttonData);
	
	TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
	
	isButtonPressed_ExpectAndReturn(false);
	buttonSM(&buttonData);
	
	TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
}

void test_ButtonSM_should_change_state_to_RELEASE_when_button_is_released_INITIAL_PRESS()
{
	ButtonData buttonData ;
	
	buttonData.state =PRESS ;
	
	TEST_ASSERT_EQUAL(buttonData.state,PRESS);
	
	isButtonPressed_ExpectAndReturn(false);
	buttonSM(&buttonData);
	
	TEST_ASSERT_EQUAL(buttonData.state,RELEASE);
}