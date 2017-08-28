// unit_test_trabalho1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
//int main()
//{
//   return 0;
//}
#include "gtest/gtest.h"
#include "sensor.h"
#include "defines.h"

TEST(teste1, teste) {
	Sensor * s = new Sensor(TEMP);
	ASSERT_EQ(0.5, s->getR());
}