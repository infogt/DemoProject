/*
 * test_Led.cpp
 *
 *  Created on: 11.12.2015
 *      Author: rgdsouza
 */

# include "gtest/gtest.h"
# include "Led.h"
namespace testled {
	LED Test;
}

TEST(LED_TEST_OPTION_1_a_TC_LED__LED_STATE__S_OFF, negative)
{
	EXPECT_EQ(testled::Test.E_NOT_OK, testled::Test.Off());
	EXPECT_EQ(testled::Test.S_OFF, testled::Test.GetCurrentState());

	EXPECT_EQ(testled::Test.E_NOT_OK, testled::Test.Blink(0));
	EXPECT_EQ(testled::Test.S_OFF, testled::Test.GetCurrentState());

	EXPECT_EQ(testled::Test.E_NOT_OK, testled::Test.Blink(1));
	EXPECT_EQ(testled::Test.S_OFF, testled::Test.GetCurrentState());

	EXPECT_EQ(testled::Test.E_NOT_OK, testled::Test.Blink(2));
	EXPECT_EQ(testled::Test.S_OFF, testled::Test.GetCurrentState());
}

TEST(LED_TEST_OPTION_1_a_TC_LED__LED_STATE__S_OFF, positive)
{
	EXPECT_EQ(testled::Test.E_OK, testled::Test.On());
	EXPECT_EQ(testled::Test.S_ON, testled::Test.GetCurrentState());
}

TEST(LED_TEST_OPTION_1_a_TC_LED__LED_STATE__S_ON, negative)
{
	EXPECT_EQ(testled::Test.E_NOT_OK, testled::Test.On());
	EXPECT_EQ(testled::Test.S_ON, testled::Test.GetCurrentState());
	// Current state remains as S_ON

	EXPECT_EQ(testled::Test.E_NOT_OK, testled::Test.Blink(0));
	EXPECT_EQ(testled::Test.S_ON, testled::Test.GetCurrentState());
	// Current state remains as S_ON

	EXPECT_EQ(testled::Test.E_NOT_OK, testled::Test.Blink(3));
	EXPECT_EQ(testled::Test.S_ON, testled::Test.GetCurrentState());
	// Current state remains as S_ON
}

TEST(LED_TEST_OPTION_1_a_TC_LED__LED_STATE__S_ON, positive)
{
	EXPECT_EQ(testled::Test.E_OK, testled::Test.Off());
	EXPECT_EQ(testled::Test.S_OFF, testled::Test.GetCurrentState());
	// Current state is now S_OFF

	testled::Test.On(); // Make current state as S_ON
	EXPECT_EQ(testled::Test.E_OK, testled::Test.Blink(1));
	EXPECT_EQ(testled::Test.S_BLINK_1S, testled::Test.GetCurrentState());
	// Current state is now S_BLINK_1S

	testled::Test.On(); // Make current state as S_ON
	EXPECT_EQ(testled::Test.E_OK, testled::Test.Blink(2));
	EXPECT_EQ(testled::Test.S_BLINK_2S, testled::Test.GetCurrentState());
	// Current state is now S_BLINK_2S
}

TEST(LED_TEST_OPTION_1_a_TC_LED__LED_STATE__S_BLINK_2S, negative)
{
	EXPECT_EQ(testled::Test.E_NOT_OK, testled::Test.Off());
	EXPECT_EQ(testled::Test.S_BLINK_2S, testled::Test.GetCurrentState());
	// Current state remains as S_BLINK_2S

	EXPECT_EQ(testled::Test.E_NOT_OK, testled::Test.Blink(0));
	EXPECT_EQ(testled::Test.S_BLINK_2S, testled::Test.GetCurrentState());
	// Current state remains as S_BLINK_2S

	EXPECT_EQ(testled::Test.E_NOT_OK, testled::Test.Blink(3));
	EXPECT_EQ(testled::Test.S_BLINK_2S, testled::Test.GetCurrentState());
	// Current state remains as S_BLINK_2S
}

TEST(LED_TEST_OPTION_1_a_TC_LED__LED_STATE__S_BLINK_2S, positive)
{
	EXPECT_EQ(testled::Test.E_OK, testled::Test.On());
	EXPECT_EQ(testled::Test.S_ON, testled::Test.GetCurrentState());
	// Current state remains as S_ON

	testled::Test.Blink(2); // Make current state as S_BLINK_2S
	EXPECT_EQ(testled::Test.E_OK, testled::Test.Blink(1));
	EXPECT_EQ(testled::Test.S_BLINK_1S, testled::Test.GetCurrentState());
	// Current state is now S_BLINK_1S
}

TEST(LED_TEST_OPTION_1_a_TC_LED__LED_STATE__S_BLINK_1S, negative)
{
	EXPECT_EQ(testled::Test.E_NOT_OK, testled::Test.Off());
	EXPECT_EQ(testled::Test.S_BLINK_1S, testled::Test.GetCurrentState());
	// Current state remains as S_BLINK_1S

	EXPECT_EQ(testled::Test.E_NOT_OK, testled::Test.Blink(0));
	EXPECT_EQ(testled::Test.S_BLINK_1S, testled::Test.GetCurrentState());
	// Current state remains as S_BLINK_1S

	EXPECT_EQ(testled::Test.E_NOT_OK, testled::Test.Blink(3));
	EXPECT_EQ(testled::Test.S_BLINK_1S, testled::Test.GetCurrentState());
	// Current state remains as S_BLINK_1S
}

TEST(LED_TEST_OPTION_1_a_TC_LED__LED_STATE__S_BLINK_1S, positive)
{
	EXPECT_EQ(testled::Test.E_OK, testled::Test.Blink(2));
	EXPECT_EQ(testled::Test.S_BLINK_2S, testled::Test.GetCurrentState());
	// Current state is now S_BLINK_2S

	testled::Test.Blink(1); // Make current state as S_BLINK_1S
	EXPECT_EQ(testled::Test.E_OK, testled::Test.On());
	EXPECT_EQ(testled::Test.S_ON, testled::Test.GetCurrentState());
	// Current state remains as S_ON
}




