/*
 * gtest_main.cpp
 *
 *  Created on: 04.11.2015
 *      Author: sthangavelmurugesa
 */

// gtest_main.cpp
#include <stdio.h>
#include "gtest/gtest.h"

#if 0
GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from gtest_main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
#endif

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from gtest_main.cc\n");
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::GTEST_FLAG(filter) = "*LED_TEST_OPTION_4*";
  return RUN_ALL_TESTS();
}
