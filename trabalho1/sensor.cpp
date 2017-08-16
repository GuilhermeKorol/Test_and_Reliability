#include "stdafx.h"
#include "sensor.h"


Sensor::Sensor(int t) {
	type = t;
	alert = OFF;
}

Sensor::~Sensor()
{
}

bool Sensor::setH() {
	if (status == ENABLED) {
		return false;
	}
	else {
		status = ENABLED;
		return true;
	}
}

bool Sensor::resetH() {
	if (status == DISABLED) {
		return false;
	}
	else {
		status = DISABLED;
		return true;
	}
}

bool Sensor::getH() {
	if (status == ENABLED) {
		return true;
	}
	else {
		return false;
	}
}

void Sensor::setR(float	r) {
	conf = r;
}

float Sensor::getR() {
	return conf;
}

bool Sensor::setValue(float v) {
	if (type == TEMP) {
		if (v >= LIMIT_TEMP) {
			if (alert == OFF) {
				alert = ON;
			}
			value = v;
			return true;
		}
		else if (v < LIMIT_TEMP) {
			if (alert == ON) {
				alert = OFF;
			}
			value = v;
			return true;
		}
		// TODO: use confiability value R
		return false;
	}
	else {	//type == pressure
		if (v >= LIMIT_PRESSURE) {
			if (alert == OFF) {
				alert = ON;
			}
			value = v;
			return true;
		}
		else if (v < LIMIT_PRESSURE) {
			if (alert == ON) {
				alert = OFF;
			}
			value = v;
			return true;
		}
		// TODO: use confiability value R
		return false;
	}
}

bool Sensor::getAlert() {
	return alert;
}

int	Sensor::getType() {
	return type;
}