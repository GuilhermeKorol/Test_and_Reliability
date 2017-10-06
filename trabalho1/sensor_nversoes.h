#pragma once
#include "stdafx.h"
#include "defines.h"

using namespace std;

// class Sensor_nver : public Sensor
class Sensor_nver
{
public:
	Sensor_nver(Sensor * s1, Sensor * s2, Sensor * s3);
	~Sensor_nver();

	bool	setH();
	bool	resetH();
	bool	getH();
	bool	setValue(float v);
	bool	getAlert();

	int		getType();

private:
	Sensor * s1;
	Sensor * s2;
	Sensor * s3;
};