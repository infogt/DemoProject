/*
 * test_Led.cpp
 *
 *  Created on: Thu Jan 14 14:32:32 2016
 *      Author: Tool Generated
 */

# include "gtest/gtest.h"
# include "Led.h"

/* Method to read the current state */
#define TestCode_GetCurrentState       Test.GetCurrentState


/*
 Test case no.     : TC0001
 Test case category: Negative
 State under test  : S_BLINK_1S
 Method under test : Blink
*/
TEST(LED_State_S_BLINK_1S, Method_Blink_Negative_TC0001)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On(); Test.Blink(1);
  
  /* Call method and check for expected return value */
  Test.Blink(0);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_BLINK_1S, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0002
 Test case category: Negative
 State under test  : S_BLINK_1S
 Method under test : Blink
*/
TEST(LED_State_S_BLINK_1S, Method_Blink_Negative_TC0002)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On(); Test.Blink(1);
  
  /* Call method and check for expected return value */
  Test.Blink(1);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_BLINK_1S, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0003
 Test case category: Positive
 State under test  : S_BLINK_1S
 Method under test : Blink
*/
TEST(LED_State_S_BLINK_1S, Method_Blink_Positive_TC0003)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On(); Test.Blink(1);
  
  /* Call method and check for expected return value */
  Test.Blink(2);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_BLINK_2S, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0004
 Test case category: Negative
 State under test  : S_BLINK_1S
 Method under test : Blink
*/
TEST(LED_State_S_BLINK_1S, Method_Blink_Negative_TC0004)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On(); Test.Blink(1);
  
  /* Call method and check for expected return value */
  Test.Blink(3);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_BLINK_1S, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0005
 Test case category: Negative
 State under test  : S_BLINK_1S
 Method under test : Blink
*/
TEST(LED_State_S_BLINK_1S, Method_Blink_Negative_TC0005)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On(); Test.Blink(1);
  
  /* Call method and check for expected return value */
  Test.Blink(4);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_BLINK_1S, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0006
 Test case category: Negative
 State under test  : S_BLINK_1S
 Method under test : Off
*/
TEST(LED_State_S_BLINK_1S, Method_Off_Negative_TC0006)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On(); Test.Blink(1);
  
  /* Call method and check for expected return value */
  Test.Off();
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_BLINK_1S, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0007
 Test case category: Positive
 State under test  : S_BLINK_1S
 Method under test : On
*/
TEST(LED_State_S_BLINK_1S, Method_On_Positive_TC0007)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On(); Test.Blink(1);
  
  /* Call method and check for expected return value */
  Test.On();
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_ON, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0008
 Test case category: Negative
 State under test  : S_BLINK_2S
 Method under test : Blink
*/
TEST(LED_State_S_BLINK_2S, Method_Blink_Negative_TC0008)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On(); Test.Blink(2);
  
  /* Call method and check for expected return value */
  Test.Blink(0);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_BLINK_2S, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0009
 Test case category: Positive
 State under test  : S_BLINK_2S
 Method under test : Blink
*/
TEST(LED_State_S_BLINK_2S, Method_Blink_Positive_TC0009)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On(); Test.Blink(2);
  
  /* Call method and check for expected return value */
  Test.Blink(1);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_BLINK_1S, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0010
 Test case category: Negative
 State under test  : S_BLINK_2S
 Method under test : Blink
*/
TEST(LED_State_S_BLINK_2S, Method_Blink_Negative_TC0010)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On(); Test.Blink(2);
  
  /* Call method and check for expected return value */
  Test.Blink(2);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_BLINK_2S, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0011
 Test case category: Negative
 State under test  : S_BLINK_2S
 Method under test : Blink
*/
TEST(LED_State_S_BLINK_2S, Method_Blink_Negative_TC0011)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On(); Test.Blink(2);
  
  /* Call method and check for expected return value */
  Test.Blink(3);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_BLINK_2S, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0012
 Test case category: Negative
 State under test  : S_BLINK_2S
 Method under test : Blink
*/
TEST(LED_State_S_BLINK_2S, Method_Blink_Negative_TC0012)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On(); Test.Blink(2);
  
  /* Call method and check for expected return value */
  Test.Blink(4);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_BLINK_2S, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0013
 Test case category: Negative
 State under test  : S_BLINK_2S
 Method under test : Off
*/
TEST(LED_State_S_BLINK_2S, Method_Off_Negative_TC0013)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On(); Test.Blink(2);
  
  /* Call method and check for expected return value */
  Test.Off();
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_BLINK_2S, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0014
 Test case category: Positive
 State under test  : S_BLINK_2S
 Method under test : On
*/
TEST(LED_State_S_BLINK_2S, Method_On_Positive_TC0014)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On(); Test.Blink(2);
  
  /* Call method and check for expected return value */
  Test.On();
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_ON, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0015
 Test case category: Negative
 State under test  : S_OFF
 Method under test : Blink
*/
TEST(LED_State_S_OFF, Method_Blink_Negative_TC0015)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  /* No method call needed */
  
  /* Call method and check for expected return value */
  Test.Blink(0);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_OFF, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0016
 Test case category: Negative
 State under test  : S_OFF
 Method under test : Blink
*/
TEST(LED_State_S_OFF, Method_Blink_Negative_TC0016)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  /* No method call needed */
  
  /* Call method and check for expected return value */
  Test.Blink(1);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_OFF, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0017
 Test case category: Negative
 State under test  : S_OFF
 Method under test : Blink
*/
TEST(LED_State_S_OFF, Method_Blink_Negative_TC0017)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  /* No method call needed */
  
  /* Call method and check for expected return value */
  Test.Blink(2);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_OFF, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0018
 Test case category: Negative
 State under test  : S_OFF
 Method under test : Blink
*/
TEST(LED_State_S_OFF, Method_Blink_Negative_TC0018)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  /* No method call needed */
  
  /* Call method and check for expected return value */
  Test.Blink(3);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_OFF, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0019
 Test case category: Negative
 State under test  : S_OFF
 Method under test : Blink
*/
TEST(LED_State_S_OFF, Method_Blink_Negative_TC0019)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  /* No method call needed */
  
  /* Call method and check for expected return value */
  Test.Blink(4);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_OFF, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0020
 Test case category: Negative
 State under test  : S_OFF
 Method under test : Off
*/
TEST(LED_State_S_OFF, Method_Off_Negative_TC0020)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  /* No method call needed */
  
  /* Call method and check for expected return value */
  Test.Off();
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_OFF, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0021
 Test case category: Positive
 State under test  : S_OFF
 Method under test : On
*/
TEST(LED_State_S_OFF, Method_On_Positive_TC0021)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  /* No method call needed */
  
  /* Call method and check for expected return value */
  Test.On();
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_ON, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0022
 Test case category: Negative
 State under test  : S_ON
 Method under test : Blink
*/
TEST(LED_State_S_ON, Method_Blink_Negative_TC0022)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On();
  
  /* Call method and check for expected return value */
  Test.Blink(0);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_ON, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0023
 Test case category: Positive
 State under test  : S_ON
 Method under test : Blink
*/
TEST(LED_State_S_ON, Method_Blink_Positive_TC0023)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On();
  
  /* Call method and check for expected return value */
  Test.Blink(1);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_BLINK_1S, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0024
 Test case category: Positive
 State under test  : S_ON
 Method under test : Blink
*/
TEST(LED_State_S_ON, Method_Blink_Positive_TC0024)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On();
  
  /* Call method and check for expected return value */
  Test.Blink(2);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_BLINK_2S, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0025
 Test case category: Negative
 State under test  : S_ON
 Method under test : Blink
*/
TEST(LED_State_S_ON, Method_Blink_Negative_TC0025)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On();
  
  /* Call method and check for expected return value */
  Test.Blink(3);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_ON, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0026
 Test case category: Negative
 State under test  : S_ON
 Method under test : Blink
*/
TEST(LED_State_S_ON, Method_Blink_Negative_TC0026)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On();
  
  /* Call method and check for expected return value */
  Test.Blink(4);
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_ON, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0027
 Test case category: Positive
 State under test  : S_ON
 Method under test : Off
*/
TEST(LED_State_S_ON, Method_Off_Positive_TC0027)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On();
  
  /* Call method and check for expected return value */
  Test.Off();
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_OFF, TestCode_GetCurrentState());
}

/*
 Test case no.     : TC0028
 Test case category: Negative
 State under test  : S_ON
 Method under test : On
*/
TEST(LED_State_S_ON, Method_On_Negative_TC0028)
{
  /* Create an object to test */
  LED Test;
  
  /* Move from initial state to State under test */
  Test.On();
  
  /* Call method and check for expected return value */
  Test.On();
  
  /* Check if the new state is as expected */
  EXPECT_EQ(Test.S_ON, TestCode_GetCurrentState());
}


