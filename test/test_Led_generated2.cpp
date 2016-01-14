/*
 * test_Led.cpp
 *
 *  Created on: Thu Jan 14 08:59:41 2016
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
TEST(LED_TC0001_State_S_BLINK_1S_Method_Blink, Negative)
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
TEST(LED_TC0002_State_S_BLINK_1S_Method_Blink, Negative)
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
TEST(LED_TC0003_State_S_BLINK_1S_Method_Blink, Positive)
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
TEST(LED_TC0004_State_S_BLINK_1S_Method_Blink, Negative)
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
TEST(LED_TC0005_State_S_BLINK_1S_Method_Blink, Negative)
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
TEST(LED_TC0006_State_S_BLINK_1S_Method_Off, Negative)
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
TEST(LED_TC0007_State_S_BLINK_1S_Method_On, Positive)
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
TEST(LED_TC0008_State_S_BLINK_2S_Method_Blink, Negative)
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
TEST(LED_TC0009_State_S_BLINK_2S_Method_Blink, Positive)
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
TEST(LED_TC0010_State_S_BLINK_2S_Method_Blink, Negative)
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
TEST(LED_TC0011_State_S_BLINK_2S_Method_Blink, Negative)
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
TEST(LED_TC0012_State_S_BLINK_2S_Method_Blink, Negative)
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
TEST(LED_TC0013_State_S_BLINK_2S_Method_Off, Negative)
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
TEST(LED_TC0014_State_S_BLINK_2S_Method_On, Positive)
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
TEST(LED_TC0015_State_S_OFF_Method_Blink, Negative)
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
TEST(LED_TC0016_State_S_OFF_Method_Blink, Negative)
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
TEST(LED_TC0017_State_S_OFF_Method_Blink, Negative)
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
TEST(LED_TC0018_State_S_OFF_Method_Blink, Negative)
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
TEST(LED_TC0019_State_S_OFF_Method_Blink, Negative)
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
TEST(LED_TC0020_State_S_OFF_Method_Off, Negative)
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
TEST(LED_TC0021_State_S_OFF_Method_On, Positive)
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
TEST(LED_TC0022_State_S_ON_Method_Blink, Negative)
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
TEST(LED_TC0023_State_S_ON_Method_Blink, Positive)
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
TEST(LED_TC0024_State_S_ON_Method_Blink, Positive)
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
TEST(LED_TC0025_State_S_ON_Method_Blink, Negative)
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
TEST(LED_TC0026_State_S_ON_Method_Blink, Negative)
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
TEST(LED_TC0027_State_S_ON_Method_Off, Positive)
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
TEST(LED_TC0028_State_S_ON_Method_On, Negative)
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


