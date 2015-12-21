/*
 * test_Led.cpp
 *
 *  Created on: 11.12.2015
 *      Author: rgdsouza
 */

# include "gtest/gtest.h"
# include "Led.h"

/* TODO: Is there any way to know the number of states by referring to the UML class / state diagram?
 * Reading all the states from the XML file can generate this value */
#define NUM_OF_STATES                    4

/* Definition to know the number of function calls to be done in each state
 * Note: A function with 1 argument taking 4 possible values => 4 Methods
 * TODO: Can this information be derived from UML diagram? */
#define NUM_OF_METHODS                   6

/* TODO: Class needs to be generated from the UML diagram
 * Create a test class which is derived from a class belonging to the module under test */
class TEST_LED: public LED
{
public:
	LED_STATE StateUnderTest;		// This is the state that is being tested
	LED_STATE NewState;				// This is the state to which the transition occurs
	static LED_STATE const ValidNewState[NUM_OF_STATES][NUM_OF_METHODS];

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
TEST_LED::LED_STATE const TEST_LED::ValidNewState[NUM_OF_STATES][NUM_OF_METHODS] =
{
	{
		S_OFF,
		S_ON,
		S_OFF,
		S_OFF,
		S_OFF,
		S_OFF
	},

	{
		S_OFF,
		S_ON,
		S_ON,
		S_BLINK_1S,
		S_BLINK_2S,
		S_ON
	},

	{
		S_BLINK_1S,
		S_ON,
		S_BLINK_1S,
		S_BLINK_1S,
		S_BLINK_2S,
		S_BLINK_1S
	},

	{
		S_BLINK_2S,
		S_ON,
		S_BLINK_2S,
		S_BLINK_1S,
		S_BLINK_2S,
		S_BLINK_2S
	},

};

/* TODO: Can this be represented in a sequence diagram */
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

/* TODO: Logic to be changed in this function to optimize it and
 * readable when more states are there in the system
 */
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

				default:
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

				default:
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

				default:
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

				default:
					break;
			}
			break;
	}
}

/* TODO: How to generate this logic using UML diagram?
 * The class contains the function information. Hence this could be generated from the class diagram
 * Probably we would have to add some information into the class diagram about the possible values for
 * parameters
 * */
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
