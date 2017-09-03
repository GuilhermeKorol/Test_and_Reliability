// ====================================================== //
//
// T1 - Teste e Confiabilidade de Sistemas - FACIN - PUCRS
// Guilherme Korol & Matheus Strock
//
// ====================================================== //
#include "stdafx.h"
#include "gtest/gtest.h"

#define RUN_TESTS false

// Walks trhough the controller FSM q0 - q3 - q4 - q6 - q4 - q3 - q0
TEST_F(test_fixture_ctrl, unit_test_ctrl_q6_up_and_back) {
	// Q0 -> Q3
	ASSERT_TRUE(ctrl_ut->enable());
	// Q3 -> Q4
	temp_sensor->setValue(LIMIT_TEMP + 1); // Should set temperature alarm ON
	EXPECT_TRUE(ctrl_ut->alert(TEMP));
	// Q4 -> Q4
	EXPECT_TRUE(ctrl_ut->getV(TEMP));
	// Q4 -> Q6
	pressure_sensor->setValue(LIMIT_PRESSURE + 1); // Should set pressure alarm ON
	EXPECT_TRUE(ctrl_ut->alert(PRESSURE));
	// Q6 -> Q6
	EXPECT_TRUE(ctrl_ut->getV(TEMP));
	EXPECT_TRUE(ctrl_ut->getV(PRESSURE));
	// Q6 -> Q4
	pressure_sensor->setValue(LIMIT_PRESSURE - 1); // Should set pressure alarm OFF
	EXPECT_TRUE(ctrl_ut->reset(PRESSURE));
	// Q4 -> Q3
	temp_sensor->setValue(LIMIT_TEMP - 1); // Should set temperature alarm OFF
	EXPECT_TRUE(ctrl_ut->reset(TEMP));
	// Q3 -> Q0
	EXPECT_TRUE(ctrl_ut->disable());
	// Q0 -> Q0
	EXPECT_FALSE(ctrl_ut->getV(TEMP));
	EXPECT_FALSE(ctrl_ut->getV(PRESSURE));
}

// Walks trhough the controller FSM q0 - q3 - q5 - q6
TEST_F(test_fixture_ctrl, unit_test_ctrl_q6_down) {
	// Q0 -> Q3
	ASSERT_TRUE(ctrl_ut->enable());
	// Q3 -> Q5
	pressure_sensor->setValue(LIMIT_PRESSURE + 1);
	EXPECT_TRUE(ctrl_ut->alert(PRESSURE));
	// Q5 -> Q6
	temp_sensor->setValue(LIMIT_TEMP + 1); // Should set temperature alarm ON
	EXPECT_TRUE(ctrl_ut->alert(TEMP));
}

// Walks trhough the sensor FSM s0 - s1 - s2 - s1 - s0
TEST_F(test_fixture_sensor, unit_test_sensor_s3_and_back) {
	// S0 -> S1
	EXPECT_TRUE(sensor_ut->setH());
	// S1 -> S1
	EXPECT_FALSE(sensor_ut->getAlert());
	// S1 -> S2
	EXPECT_TRUE(sensor_ut->setValue(LIMIT_TEMP + 1)); // Test is using sensor as TEMP type
	// S2 -> S2
	EXPECT_TRUE(sensor_ut->getAlert());
	// S2 -> S1
	EXPECT_TRUE(sensor_ut->setValue(LIMIT_TEMP - 1));
	// S1 -> S1
	EXPECT_FALSE(sensor_ut->getAlert());
	// S1 -> S0
	EXPECT_TRUE(sensor_ut->resetH());
	// S0 -> S0
	EXPECT_FALSE(sensor_ut->getAlert());

}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	printf("tests: %d", RUN_ALL_TESTS());

	if (RUN_TESTS) {

		std::default_random_engine generator;
		std::uniform_real_distribution<double> distribution(0, 1);
		double random_number;

		Sensor* temp_sensor = new (nothrow) Sensor(TEMP);
		Sensor* pressure_sensor = new (nothrow) Sensor(PRESSURE);
		// Machine_ctrl* fsm_ctrl = new (nothrow) Machine_ctrl(temp_sensor, pressure_sensor);
		Controller* ctrl = new (nothrow) Controller(temp_sensor, pressure_sensor);

		if (ctrl == NULL || temp_sensor == NULL || pressure_sensor == NULL) {
			printf("Error(s) instantiating sensors or controller\n");
			return 1;
		}

		temp_sensor->setR(0.7);
		pressure_sensor->setR(0.8);

		while (true) {
			random_number = distribution(generator);
			temp_sensor->setValue(random_number*(MAX_TEMP - MIN_TEMP) + MIN_TEMP);
			pressure_sensor->setValue(random_number*(MAX_PRESSURE - MIN_PRESSURE) + MIN_PRESSURE);

			//fsm_ctrl->update_state();

			Sleep(3000);
		}

		delete ctrl;
		delete temp_sensor;
		delete pressure_sensor;
	}

	for (;;);

    return 0;
}

