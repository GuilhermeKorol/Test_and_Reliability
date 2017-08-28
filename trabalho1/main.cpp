// trabalho1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest/gtest.h"

TEST(teste1, teste) {
	Sensor * s = new Sensor(TEMP);
	ASSERT_EQ(0.5, s->getR());
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	printf("tests: %d", RUN_ALL_TESTS());

	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(0, 1);
	double random_number;

	Sensor* temp_sensor = new (nothrow) Sensor(TEMP);
	Sensor* pressure_sensor = new (nothrow) Sensor(PRESSURE);
	Controller* cont = new (nothrow) Controller();

	//srand((unsigned)time(NULL));

	if (cont == NULL || temp_sensor == NULL || pressure_sensor == NULL) {
		printf("Error(s) instantiating sensors or controller\n");
		return 1;
	}

	if (!(cont->enable())) {
		printf("Sensors are already enabled\n");
	}

	temp_sensor->setR(0.7);
	pressure_sensor->setR(0.8);

	while (true) {
		cont->alert(temp_sensor);
		cont->alert(pressure_sensor);

		random_number = distribution(generator);
		temp_sensor->setValue(random_number*(MAX_TEMP - MIN_TEMP) + MIN_TEMP);
		pressure_sensor->setValue(random_number*(MAX_PRESSURE - MIN_PRESSURE) + MIN_PRESSURE);

		Sleep(3000);
	}

	delete cont;
	delete temp_sensor;
	delete pressure_sensor;

    return 0;
}

