/*
 * test_Led.cpp
 *
 *  Created on: 11.12.2015
 *      Author: rgdsouza
 */

# include "gtest/gtest.h"
# include "Led.h"

TEST(LED__LED_STATE__S_OFF, positive)
{
	LED Test;
	EXPECT_EQ(Test.E_OK, Test.On());
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
}

TEST(LED__LED_STATE__S_OFF, negative)
{
	LED Test;

	EXPECT_EQ(Test.E_NOT_OK, Test.Off());
	EXPECT_EQ(Test.S_OFF, Test.GetCurrentState());

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(0));
	EXPECT_EQ(Test.S_OFF, Test.GetCurrentState());

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(1));
	EXPECT_EQ(Test.S_OFF, Test.GetCurrentState());

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(2));
	EXPECT_EQ(Test.S_OFF, Test.GetCurrentState());
}

TEST(LED__LED_STATE__S_ON, positive)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	EXPECT_EQ(Test.E_OK, Test.Off());
	EXPECT_EQ(Test.S_OFF, Test.GetCurrentState());
	// Current state is now S_OFF

	Test.On(); // Make current state as S_ON
	EXPECT_EQ(Test.E_OK, Test.Blink(1));
	EXPECT_EQ(Test.S_BLINK_1S, Test.GetCurrentState());
	// Current state is now S_BLINK_1S

	Test.On(); // Make current state as S_ON
	EXPECT_EQ(Test.E_OK, Test.Blink(2));
	EXPECT_EQ(Test.S_BLINK_2S, Test.GetCurrentState());
	// Current state is now S_BLINK_2S
}

TEST(LED__LED_STATE__S_ON, negative)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	EXPECT_EQ(Test.E_NOT_OK, Test.On());
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
	// Current state remains as S_ON

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(0));
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
	// Current state remains as S_ON

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(3));
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
	// Current state remains as S_ON
}

TEST(LED__LED_STATE__S_BLINK_1S, positive)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	Test.Blink(1); // Make current state as S_BLINK_1S

	EXPECT_EQ(Test.E_OK, Test.Blink(2));
	EXPECT_EQ(Test.S_BLINK_2S, Test.GetCurrentState());
	// Current state is now S_BLINK_2S

	Test.Blink(1); // Make current state as S_BLINK_1S
	EXPECT_EQ(Test.E_OK, Test.On());
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
	// Current state remains as S_ON

}

TEST(LED__LED_STATE__S_BLINK_1S, negative)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	Test.Blink(1); // Make current state as S_BLINK_1S

	EXPECT_EQ(Test.E_NOT_OK, Test.Off());
	EXPECT_EQ(Test.S_BLINK_1S, Test.GetCurrentState());
	// Current state remains as S_BLINK_1S

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(0));
	EXPECT_EQ(Test.S_BLINK_1S, Test.GetCurrentState());
	// Current state remains as S_BLINK_1S

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(3));
	EXPECT_EQ(Test.S_BLINK_1S, Test.GetCurrentState());
	// Current state remains as S_BLINK_1S
}

TEST(LED__LED_STATE__S_BLINK_2S, positive)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	Test.Blink(2); // Make current state as S_BLINK_2S

	EXPECT_EQ(Test.E_OK, Test.Blink(1));
	EXPECT_EQ(Test.S_BLINK_1S, Test.GetCurrentState());
	// Current state is now S_BLINK_1S

	Test.Blink(2); // Make current state as S_BLINK_2S
	EXPECT_EQ(Test.E_OK, Test.On());
	EXPECT_EQ(Test.S_ON, Test.GetCurrentState());
	// Current state remains as S_ON


}

TEST(LED__LED_STATE__S_BLINK_2S, negative)
{
	LED Test;

	Test.On(); // Make current state as S_ON
	Test.Blink(2); // Make current state as S_BLINK_2S

	EXPECT_EQ(Test.E_NOT_OK, Test.Off());
	EXPECT_EQ(Test.S_BLINK_2S, Test.GetCurrentState());
	// Current state remains as S_BLINK_2S

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(0));
	EXPECT_EQ(Test.S_BLINK_2S, Test.GetCurrentState());
	// Current state remains as S_BLINK_2S

	EXPECT_EQ(Test.E_NOT_OK, Test.Blink(3));
	EXPECT_EQ(Test.S_BLINK_2S, Test.GetCurrentState());
	// Current state remains as S_BLINK_2S
}



