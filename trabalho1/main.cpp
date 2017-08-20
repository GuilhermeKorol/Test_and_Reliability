// trabalho1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

float rand_value(int max, int min) {
	return (float)rand() / (RAND_MAX + 1) * (max - min)
		+ min;
}

int main()
{
	Sensor* temp_sensor = new (nothrow) Sensor(TEMP);
	Sensor* pressure_sensor = new (nothrow) Sensor(PRESSURE);
	Controller* cont = new (nothrow) Controller();

	srand((unsigned)time(NULL));

	if (cont == NULL || temp_sensor == NULL || pressure_sensor == NULL) {
		printf("Error(s) instantiating sensors or controller\n");
		return 1;
	}

	cont->enable();

	while (true) {
		cont->alert(temp_sensor);
		cont->alert(pressure_sensor);

		temp_sensor->setValue( rand_value(MAX_TEMP, MIN_TEMP) );
		pressure_sensor->setValue( rand_value(MAX_PRESSURE, MIN_PRESSURE) );

		Sleep(3000);
	}

	delete cont;
	delete temp_sensor;
	delete pressure_sensor;

    return 0;
}

