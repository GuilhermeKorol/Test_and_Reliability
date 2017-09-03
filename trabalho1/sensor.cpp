#include "stdafx.h"
#include "sensor.h"


Sensor::Sensor(int t) : distribution(0, 1) {
	type = t;
	alert = OFF;
	status = DISABLED;
	conf = 0.5;
	ps = s0;
	if (t == TEMP) {
		value = VALID_TEMP;
	}
	else {
		value = VALID_PRESSURE;
	}
	printf("Sensor initialized with valid value\n");
}

Sensor::~Sensor()
{
}

bool Sensor::setH() {
	if (ps == s0) {
		if (status == ENABLED) {
			return false;
		}
		else {
			status = ENABLED;
			ps = s1;
			return true;
		}
	}
}

bool Sensor::resetH() {
	if (ps == s1) {
		if (status == DISABLED) {
			return false;
		}
		else {
			status = DISABLED;
			ps = s0;
			return true;
		}
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
	printf("Confiability set to %f\n", r);
}

float Sensor::getR() {
	return conf;
}

bool Sensor::setValue(float v) {
	double random_number = distribution(generator);
	
	if (random_number < conf) {	// Confiability -> as conf grows, higher are the chances of success
		if (type == TEMP) {
			printf("Value set to %f\n", v);
			if (v >= LIMIT_TEMP) {
				if (alert == OFF) {
					alert = ON;
					if (ps == s1) {
						ps = s2;
					}
					printf("Temperature alarm ON\n");
				}
				value = v;
				return true;
			}
			else {
				if (alert == ON) {
					alert = OFF;
					printf("Temperature alarm OFF\n");
				}
				if (ps == s2) {
					ps = s1;
				}
				value = v;
				return true;
			}
		}
		else {	//type == pressure
			printf("Value set to %f\n", v);
			if (v >= LIMIT_PRESSURE) {
				if (alert == OFF) {
					alert = ON;
					printf("Pressure alarm ON\n");
				}
				value = v;
				return true;
			}
			else {
				if (alert == ON) {
					alert = OFF;
					printf("Pressure alarm OFF\n");
				}
				value = v;
				return true;
			}
		}
	}
	else {
		printf("Sensor failed :(\n");
		return false;
	}
}

bool Sensor::getAlert() {
	return alert;
}

int	Sensor::getType() {
	return type;
}