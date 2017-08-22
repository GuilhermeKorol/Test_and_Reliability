#include "stdafx.h"
#include "sensor.h"


Sensor::Sensor(int t) : distribution(0, 1) {
	type = t;
	alert = OFF;
	conf = 0.5;
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
					printf("Temperature alarm ON\n");
				}
				value = v;
				return true;
			}
			else if (v < LIMIT_TEMP) {
				if (alert == ON) {
					alert = OFF;
					printf("Temperature alarm OFF\n");
				}
				value = v;
				return true;
			}
			return false;
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
			else if (v < LIMIT_PRESSURE) {
				if (alert == ON) {
					alert = OFF;
					printf("Pressure alarm OFF\n");
				}
				value = v;
				return true;
			}
			return false;
		}
	}
	else {
		printf("Sensor failed :(\n");
	}
}

bool Sensor::getAlert() {
	return alert;
}

int	Sensor::getType() {
	return type;
}