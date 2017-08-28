#pragma once
#include "stdafx.h"
#include "defines.h"
#include "sensor.h"

using namespace std;

class Controller
{
public:
	Controller();
	~Controller();

	bool enable();
	bool disable();
	void alert(Sensor* s);
	void reset(Sensor* s);
	bool getV(Sensor* s);

private:
	bool status;
	bool valve_temp;
	bool valve_pressure;

	void close(Sensor* s);
	void open(Sensor* s);
	void init();

};