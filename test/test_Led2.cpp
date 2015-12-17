/*
 * test_Led.cpp
 *
 *  Created on: 11.12.2015
 *      Author: rgdsouza
 */

# include "gtest/gtest.h"
# include "Led.h"

TEST(LED_TEST_OPTION_2, TEST_CASES)
{
	printf("\n---------------------------------------------------------------");
	printf("\n                   OPTION 2                                    ");
	printf("\n---------------------------------------------------------------");
	printf("\n");
}

TEST(LED__LED_STATE, all)
{
	LED Test;

	// Current state = Initial state = S_OFF
    // -------- Negative test cases for S_OFF state ----------

	EXPECT_EQ(Test.E_NOT_OK, Test.Off());
	EXPECT_EQ(Test.S_OFF, Test.GetCurrentState());

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(0));
	EXPECT_EQ(Test.S_OFF, Test.GetCurrentState());

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(1));
	EXPECT_EQ(Test.S_OFF, Test.GetCurrentState());

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(2));
	EXPECT_EQ(Test.S_OFF, Test.GetCurrentState());

	// Current state = S_OFF
    // -------- Positive test cases for S_OFF state ----------

	EXPECT_EQ(Test.E_OK, Test.On());
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());

	// Current state = S_ON
	// -------- Negative test cases for S_ON state ----------
	EXPECT_EQ(Test.E_NOT_OK, Test.On());
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
	// Current state remains as S_ON

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(0));
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
	// Current state remains as S_ON

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(3));
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
	// Current state remains as S_ON

	// Current state = S_ON
	// -------- Positive test cases for S_ON state ----------

	EXPECT_EQ(Test.E_OK, Test.Off());
	EXPECT_EQ(Test.S_OFF, Test.GetCurrentState());
	// Current state is now S_OFF, bring state back to S_ON
	Test.On();

	EXPECT_EQ(Test.E_OK, Test.Blink(1));
	EXPECT_EQ(Test.S_BLINK_1S, Test.GetCurrentState());
	// Current state is now S_BLINK_1S, bring state back to S_ON
	Test.On();

	EXPECT_EQ(Test.E_OK, Test.Blink(2));
	EXPECT_EQ(Test.S_BLINK_2S, Test.GetCurrentState());

	// Current state = S_BLINK_2S
	// -------- Negative test cases for S_BLINK_2S state ----------

	EXPECT_EQ(Test.E_NOT_OK, Test.Off());
	EXPECT_EQ(Test.S_BLINK_2S, Test.GetCurrentState());
	// Current state remains as S_BLINK_2S

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(0));
	EXPECT_EQ(Test.S_BLINK_2S, Test.GetCurrentState());
	// Current state remains as S_BLINK_2S

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(3));
	EXPECT_EQ(Test.S_BLINK_2S, Test.GetCurrentState());
	// Current state remains as S_BLINK_2S

	// Current state = S_BLINK_2S
	// -------- Positive test cases for S_BLINK_2S state ----------

	EXPECT_EQ(Test.E_OK, Test.On());
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
	// Current state is now S_ON, bring it back to S_BLINK_2S
	Test.Blink(2);

	EXPECT_EQ(Test.E_OK, Test.Blink(1));
	EXPECT_EQ(Test.S_BLINK_1S, Test.GetCurrentState());

	// Current state = S_BLINK_1S
	// -------- Negative test cases for S_BLINK_1S state ----------

	EXPECT_EQ(Test.E_NOT_OK, Test.Off());
	EXPECT_EQ(Test.S_BLINK_1S, Test.GetCurrentState());
	// Current state remains as S_BLINK_1S

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(0));
	EXPECT_EQ(Test.S_BLINK_1S, Test.GetCurrentState());
	// Current state remains as S_BLINK_1S

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(3));
	EXPECT_EQ(Test.S_BLINK_1S, Test.GetCurrentState());
	// Current state remains as S_BLINK_1S


	// Current state = S_BLINK_1S
	// -------- Positive test cases for S_BLINK_1S state ----------

	EXPECT_EQ(Test.E_OK, Test.Blink(2));
	EXPECT_EQ(Test.S_BLINK_2S, Test.GetCurrentState());
	// Current state is now S_BLINK_2S, bring state back to S_BLINK_1S
	Test.Blink(1);

	EXPECT_EQ(Test.E_OK, Test.On());
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
	// Current state is now S_ON

}



