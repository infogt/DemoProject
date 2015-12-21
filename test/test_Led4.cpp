/*
 * test_Led.cpp
 *
 *  Created on: 11.12.2015
 *      Author: rgdsouza
 */

# include "gtest/gtest.h"
# include "Led.h"

#define NUM_OF_STATES                    4
#define NUM_OF_METHODS                   2 // only testing On(), Off()


class TEST_LED: public LED
{
public:
	LED_STATE StateUnderTest;		// This is the state that is being tested
	LED_STATE NewState;				// This is the state to which the transition occurs
	LED_STATE ValidNewState[NUM_OF_STATES][NUM_OF_METHODS];

	void TestCode_IniSt_To_StUnderTest(void);
	void TestCode_NewSt_To_StUnderTest(void);
	void TestCode_CallMethod(unsigned int m);
};

/*
 * New states after calling the method
 *
 * 	------------|---------------|---------------|---------------|---------------|---------------|---------------|
 * 		 		|	Method1		|	Method 2	|   Method3		|	Method4		|	Method5		|   Method6     |
 * 		 		|	  Off()		|	  On()  	|	Blink(0)	|	Blink(1)	|	Blink(2)	|   Blink(3)    |
 * 	------------|---------------|---------------|---------------|---------------|---------------|---------------|
 *	S_OFF		|      S_OFF    |     S_ON		|	  S_OFF		|	  S_OFF		|	  S_OFF		|	  S_OFF		|
 * 	------------|---------------|---------------|---------------|---------------|---------------|---------------|
 *  S_ON		|      S_OFF    |     S_ON      |	  S_ON 		|	S_BLINK_1S  |	S_BLINK_2S	|	  S_ON		|
 * 	------------|---------------|---------------|---------------|---------------|---------------|---------------|
 *  S_BLINK_1S	|   S_BLINK_1S  |     S_ON		|	S_BLINK_1S	|	S_BLINK_1S  |	S_BLINK_2S	|	S_BLINK_1S  |
 * 	------------|---------------|---------------|---------------|---------------|---------------|---------------|
 *  S_BLINK_2S	|   S_BLINK_2S  |     S_ON		|	S_BLINK_2S	|	S_BLINK_1S 	|	S_BLINK_2S	|	S_BLINK_2S  |
 * 	------------|---------------|---------------|---------------|---------------|---------------|---------------|
*/
TEST_LED::LED_STATE ValidNewState[NUM_OF_STATES][NUM_OF_METHODS] =
{
		TEST_LED::S_OFF, TEST_LED::S_ON, TEST_LED::S_OFF, TEST_LED::S_ON,
		TEST_LED::S_BLINK_1S, TEST_LED::S_ON, TEST_LED::S_BLINK_2S, TEST_LED::S_ON
};

void TEST_LED::TestCode_IniSt_To_StUnderTest(void)
{
	switch(StateUnderTest)
	{
		// Transition from Initial state -> S_OFF
		case S_OFF:
			// Initial state = S_OFF, so nothing to do
			break;

		// Transition from Initial state -> S_ON
		case S_ON:
			On();
			break;

		// Transition from Initial state -> S_BLINK_1S
		case S_BLINK_1S:
			On();
			Blink(1);
			break;

		// Transition from Initial state -> S_BLINK_2S
		case S_BLINK_2S:
			On();
			Blink(2);
			break;
	}
}

void TEST_LED::TestCode_NewSt_To_StUnderTest(void)
{
	switch(NewState)
	{
		case S_OFF:
			switch(StateUnderTest)
			{
				case S_OFF:
					break;

				case S_ON:
					On();
					break;

				case S_BLINK_1S:
					On();
					Blink(1);
					break;

				case S_BLINK_2S:
					On();
					Blink(2);
					break;
			}
			break;

		case S_ON:
			switch(StateUnderTest)
			{
				case S_OFF:
					Off();
					break;

				case S_ON:
					break;

				case S_BLINK_1S:
					Blink(1);
					break;

				case S_BLINK_2S:
					Blink(2);
					break;
			}
			break;

		case S_BLINK_1S:
			switch(StateUnderTest)
			{
				case S_OFF:
					On();
					Off();
					break;

				case S_ON:
					On();
					break;

				case S_BLINK_1S:
					break;

				case S_BLINK_2S:
					Blink(2);
					break;
			}
			break;

		case S_BLINK_2S:
			switch(StateUnderTest)
			{
				case S_OFF:
					On();
					Off();
					break;

				case S_ON:
					On();
					break;

				case S_BLINK_1S:
					Blink(1);
					break;

				case S_BLINK_2S:
					break;
			}
			break;
	}
}

void TEST_LED::TestCode_CallMethod(unsigned int m)
{
	switch(m)
	{
		case 0:
			Off();
			break;
		case 1:
			On();
			break;
		case 2:
			Blink(0);
			break;
		case 3:
			Blink(1);
			break;
		case 4:
			Blink(2);
		case 5:
			Blink(3);
		default:
			break;
	}
}


TEST(LED_TEST_OPTION_4, TEST_CASES)
{
	printf("\n---------------------------------------------------------------");
	printf("\n                   OPTION 4                                    ");
	printf("\n---------------------------------------------------------------");
	printf("\n");
}


TEST(LED_TEST_LED_STATE, all)
{
	for (unsigned int s = 0; s < NUM_OF_STATES; s++)
	{
		for (unsigned int m = 0; m <NUM_OF_METHODS; m++)
		{
			TEST_LED Test;

			// Move from Initial state to State under test
			Test.StateUnderTest = (LED::LED_STATE)s;
			Test.TestCode_IniSt_To_StUnderTest();

			// Call the method and check for expected return value
			Test.TestCode_CallMethod(m);

			// Check if the new state is as expected
			// i.e., moved to new state or remain in current state
			EXPECT_EQ(Test.ValidNewState[s][m], Test.GetCurrentState());

			// If new state is not the state under test, move to state under test
			Test.NewState = Test.GetCurrentState();
			Test.TestCode_NewSt_To_StUnderTest();
		}
	}
}
