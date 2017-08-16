#pragma once
#include "stdafx.h"
#include "defines.h"
#include "Sensor.h"

using namespace std;

class Controller
{
public:
	Controller();
	~Controller();

	void enable();
	void disable();

private:
	bool status;
	Sensor * temp_sensor;
	Sensor * pressure_sensor;
	bool valve_temp;
	bool valve_pressure;

	void alert(Sensor* s);
	void close(Sensor* s);
	void open(Sensor* s);
	void reset(Sensor* s);
	void init();

};