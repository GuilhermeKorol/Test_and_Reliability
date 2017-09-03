#pragma once
#include "stdafx.h"
#include "defines.h"
#include "sensor.h"

using namespace std;

class Controller
{
public:
	Controller(Sensor * temp, Sensor * pres);
	~Controller();

	bool enable();
	bool disable();
	bool alert(int type);
	bool reset(int type);
	bool getV(int type);

private:
	states_ctrl ps;

	bool status;
	bool valve_temp;
	bool valve_pressure;

	Sensor * sensor_temp;
	Sensor * sensor_pressure;

	void close(int type);
	void open(int type);
	void init();

};