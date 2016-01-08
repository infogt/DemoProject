/*
 * test_Led.cpp
 *
 *  Created on: 11.12.2015
 *      Author: rgdsouza
 */

# include "gtest/gtest.h"
# include "Led.h"


TEST(LED_TEST_OPTION_3_TC_LED_SID1_1_2_POS, 01)
{
	LED Test;

	EXPECT_EQ(Test.E_OK, Test.On());
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
}

TEST(LED_TEST_OPTION_3_TC_LED_SID1_1_0_1_NEG, 02)
{
	LED Test;

	EXPECT_EQ(Test.E_NOT_OK, Test.Off());
	EXPECT_EQ(Test.S_OFF, Test.GetCurrentState());
}

TEST(LED_TEST_OPTION_3_TC_LED_SID1_1_0_1_NEG, 03)
{
	LED Test;

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(0));
	EXPECT_EQ(Test.S_OFF, Test.GetCurrentState());
}

TEST(LED_TEST_OPTION_3_TC_LED_SID1_1_0_1_NEG, 04)
{
	LED Test;

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(1));
	EXPECT_EQ(Test.S_OFF, Test.GetCurrentState());
}

TEST(LED_TEST_OPTION_3_TC_LED_1_0_1_NEG, 05)
{
	LED Test;

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(2));
	EXPECT_EQ(Test.S_OFF, Test.GetCurrentState());
}

TEST(LED_TEST_OPTION_3_TC_LED_1_0_1_NEG, 24)
{
	LED Test;

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(3));
	EXPECT_EQ(Test.S_OFF, Test.GetCurrentState());
}

TEST(LED_TEST_OPTION_3_TC_LED_2_1_POS, 06)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	EXPECT_EQ(Test.E_OK, Test.Off());
	EXPECT_EQ(Test.S_OFF, Test.GetCurrentState());
	// Current state is now S_OFF
}

TEST(LED_TEST_OPTION_3_TC_LED_2_3_POS, 07)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	EXPECT_EQ(Test.E_OK, Test.Blink(1));
	EXPECT_EQ(Test.S_BLINK_1S, Test.GetCurrentState());
	// Current state is now S_BLINK_1S
}

TEST(LED_TEST_OPTION_3_TC_LED_2_4_POS, 08)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	EXPECT_EQ(Test.E_OK, Test.Blink(2));
	EXPECT_EQ(Test.S_BLINK_2S, Test.GetCurrentState());
	// Current state is now S_BLINK_2S
}

TEST(LED_TEST_OPTION_3_TC_LED_2_0_2_NEG, 09)
{
	LED Test;

	Test.On(); // Make current state as S_ON

	EXPECT_EQ(Test.E_NOT_OK, Test.On());
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
	// Current state remains as S_ON
}

TEST(LED_TEST_OPTION_3_TC_LED_2_0_2_NEG, 10)
{
	LED Test;

	Test.On(); // Make current state as S_ON

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(0));
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
	// Current state remains as S_ON

}

TEST(LED_TEST_OPTION_3_TC_LED_2_0_2_NEG, 11)
{
	LED Test;

	Test.On(); // Make current state as S_ON

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(3));
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
	// Current state remains as S_ON
}

TEST(LED_TEST_OPTION_3_TC_LED_3_2_POS, 12)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	Test.Blink(1); // Make current state as S_BLINK_1S

	EXPECT_EQ(Test.E_OK, Test.Blink(2));
	EXPECT_EQ(Test.S_BLINK_2S, Test.GetCurrentState());
	// Current state is now S_BLINK_2S
}

TEST(LED_TEST_OPTION_3_TC_LED_3_4_POS, 13)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	Test.Blink(1); // Make current state as S_BLINK_1S

	EXPECT_EQ(Test.E_OK, Test.On());
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
	// Current state remains as S_ON
}

TEST(LED_TEST_OPTION_3_TC_LED_3_0_3_NEG, 14)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	Test.Blink(1); // Make current state as S_BLINK_1S

	EXPECT_EQ(Test.E_NOT_OK, Test.Off());
	EXPECT_EQ(Test.S_BLINK_1S, Test.GetCurrentState());
	// Current state remains as S_BLINK_1S
}

TEST(LED_TEST_OPTION_3_TC_LED_3_0_3_NEG, 15)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	Test.Blink(1); // Make current state as S_BLINK_1S

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(0));
	EXPECT_EQ(Test.S_BLINK_1S, Test.GetCurrentState());
	// Current state remains as S_BLINK_1S
}

TEST(LED_TEST_OPTION_3_TC_LED_3_0_3_NEG, 16)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	Test.Blink(1); // Make current state as S_BLINK_1S

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(1));
	EXPECT_EQ(Test.S_BLINK_1S, Test.GetCurrentState());
	// Current state remains as S_BLINK_1S
}

TEST(LED_TEST_OPTION_3_TC_LED_3_0_3_NEG, 17)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	Test.Blink(1); // Make current state as S_BLINK_1S

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(3));
	EXPECT_EQ(Test.S_BLINK_1S, Test.GetCurrentState());
	// Current state remains as S_BLINK_1S
}


TEST(LED_TEST_OPTION_3_TC_LED_4_2_POS, 18)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	Test.Blink(2); // Make current state as S_BLINK_2S

	EXPECT_EQ(Test.E_OK, Test.Blink(1));
	EXPECT_EQ(Test.S_BLINK_1S, Test.GetCurrentState());
	// Current state is now S_BLINK_1S
}

TEST(LED_TEST_OPTION_3_TC_LED_4_3_POS, 19)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	Test.Blink(2); // Make current state as S_BLINK_2S

	EXPECT_EQ(Test.E_OK, Test.On());
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
	// Current state is now S_ON
}


TEST(LED_TEST_OPTION_3_TC_LED_4_0_4_NEG, 20)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	Test.Blink(2); // Make current state as S_BLINK_2S

	EXPECT_EQ(Test.E_NOT_OK, Test.Off());
	EXPECT_EQ(Test.S_BLINK_2S, Test.GetCurrentState());
	// Current state remains as S_BLINK_2S
}

TEST(LED_TEST_OPTION_3_TC_LED_4_0_4_NEG, 21)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	Test.Blink(2); // Make current state as S_BLINK_2S

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(0));
	EXPECT_EQ(Test.S_BLINK_2S, Test.GetCurrentState());
	// Current state remains as S_BLINK_2S
}

TEST(LED_TEST_OPTION_3_TC_LED_4_0_4_NEG, 22)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	Test.Blink(2); // Make current state as S_BLINK_2S

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(2));
	EXPECT_EQ(Test.S_BLINK_2S, Test.GetCurrentState());
	// Current state remains as S_BLINK_2S
}

TEST(LED_TEST_OPTION_3_TC_LED_4_0_4_NEG, 23)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	Test.Blink(2); // Make current state as S_BLINK_2S

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(3));
	EXPECT_EQ(Test.S_BLINK_2S, Test.GetCurrentState());
	// Current state remains as S_BLINK_2S
}

