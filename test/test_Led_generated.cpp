/*
 * test_Led.cpp
 *
 *  Created on: Wed Jan 13 14:31:00 2016
 *      Author: Tool Generated
 */

# include "gtest/gtest.h"
# include "Led.h"

#define NUM_OF_STATES                    4
#define NUM_OF_METHODS                   4

/* Method to read the current state */
#define TESTCODE_GET_CURRENT_STATE       GetCurrentState

class TEST_LED: public LED
{
public:
	LED_STATE StateUnderTest;		// This is the state that is being tested
	LED_STATE NewState;				// This is the state to which the transition occurs
	static LED_STATE const ValidNewState[NUM_OF_STATES][NUM_OF_METHODS];

	void TestCode_IniSt_To_StUnderTest(void);
	void TestCode_CallMethod(unsigned int m);
};


TEST_LED::LED_STATE const TEST_LED::ValidNewState[NUM_OF_STATES][NUM_OF_METHODS] =
{
	
	/* New states expected when methods are called in state S_BLINK_1S */
	{
		S_BLINK_1S, //Method Blink(1);
		S_BLINK_2S, //Method Blink(2);
		S_BLINK_1S, //Method Off();
		S_ON, //Method On();
	},

	/* New states expected when methods are called in state S_BLINK_2S */
	{
		S_BLINK_1S, //Method Blink(1);
		S_BLINK_2S, //Method Blink(2);
		S_BLINK_2S, //Method Off();
		S_ON, //Method On();
	},

	/* New states expected when methods are called in state S_OFF */
	{
		S_OFF, //Method Blink(1);
		S_OFF, //Method Blink(2);
		S_OFF, //Method Off();
		S_ON, //Method On();
	},

	/* New states expected when methods are called in state S_ON */
	{
		S_BLINK_1S, //Method Blink(1);
		S_BLINK_2S, //Method Blink(2);
		S_OFF, //Method Off();
		S_ON, //Method On();
	},

};

/* TODO: Can this be represented in a sequence diagram? */
void TEST_LED::TestCode_IniSt_To_StUnderTest(void)
{
	switch(StateUnderTest)
	{
		
		/* Transition from Initial State to S_BLINK_1S */
		case S_BLINK_1S:
			On(); Blink(1);
			break;

		/* Transition from Initial State to S_BLINK_2S */
		case S_BLINK_2S:
			On(); Blink(2);
			break;

		/* Transition from Initial State to S_OFF */
		case S_OFF:
			/* No method call needed */
			break;

		/* Transition from Initial State to S_ON */
		case S_ON:
			On();
			break;

		default:
			break;
	}
}

void TEST_LED::TestCode_CallMethod(unsigned int m)
{
	switch(m)
	{
		
		case 0:
			Blink(1);
			break;

		case 1:
			Blink(2);
			break;

		case 2:
			Off();
			break;

		case 3:
			On();
			break;

		default:
			break;
	}
}

TEST(LED_TEST_OPTION_GEN, all)
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
			EXPECT_EQ(Test.ValidNewState[s][m], Test.TESTCODE_GET_CURRENT_STATE());
		}
	}
}

