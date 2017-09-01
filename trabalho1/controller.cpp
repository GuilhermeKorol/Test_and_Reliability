#include "stdafx.h"
#include "controller.h"


Controller::Controller(Sensor * temp, Sensor * pres) : sensor_temp(temp), sensor_pressure(pres) {
	init();
	enable();
}

Controller::~Controller() {

}

bool Controller::enable() {
	if(status == DISABLED) {
		printf("Controller ENABLED\n");
		status = ENABLED;
		return true;
	}
else return false;
}

bool Controller::disable() {
	if (status == ENABLED) {
		printf("Controller DISABLED\n");
		status = DISABLED;
		return true;
	}
	else return false;
}

bool Controller::alert(int type) {
	if (type == TEMP) {
		if (sensor_pressure->getAlert() == ON) {
			valve_temp = OPENED;
			printf("Temperature valve OPENED\n");
			return true;
		}
	}
	else {
		if (sensor_pressure->getAlert() == ON) {
			valve_pressure = OPENED;
			printf("Pressure valve OPENED\n");
			return true;
		}
	}
	return false;
}

bool Controller::reset(int type) {
	if (type == TEMP) {
		if (sensor_temp->getAlert() == OFF) {
			valve_temp = CLOSED;
			printf("Temperature valve CLOSED\n");
			return true;
		}
	}
	else {
		if (sensor_pressure->getAlert() == OFF) {
			valve_pressure = CLOSED;
			printf("Pressure valve CLOSED\n");
			return true;
		}
	}
	return false;
}

void Controller::close(Sensor* s) {
	if (s->getType() == TEMP) {
		valve_temp = CLOSED;
		printf("Temperature valve CLOSED\n");
	}
	else if (s->getType() == PRESSURE) {
		valve_pressure = CLOSED;
		printf("Pressure valve CLOSED\n");
	}
}

void Controller::open(Sensor* s) {
	if (s->getType() == TEMP) {
		valve_temp = OPENED;
		printf("Temperature valve OPENED\n");
	}
	else if (s->getType() == PRESSURE) {
		valve_pressure = OPENED;
		printf("Pressure valve OPENED\n");
	}
}

bool Controller::getV(int type) {
	if (type == VALVE_TEMP) {
		return valve_temp;
	}
	else {
		return valve_pressure;
	}
}

void Controller::init() {
	status = DISABLED;
}