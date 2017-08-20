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
	void alert(Sensor* s);
	void reset(Sensor* s);

private:
	bool status;
	bool valve_temp;
	bool valve_pressure;

	void close(Sensor* s);
	void open(Sensor* s);
	void init();

};