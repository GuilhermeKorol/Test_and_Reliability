#include "stdafx.h"
#include "controller.h"


Controller::Controller() {
	temp_sensor = new (nothrow) Sensor(TEMP);
	pressure_sensor = new (nothrow) Sensor(PRESSURE);

	if (temp_sensor == NULL || pressure_sensor == NULL) {
		printf("Error allocating sensors...\n");
	}
	else {
		init();
	}
}

Controller::~Controller() {
	delete temp_sensor;
	delete pressure_sensor;
}

void Controller::enable() {
	status = ENABLED;
}

void Controller::disable() {
	status = DISABLED;
}

void Controller::alert(Sensor* s) {

}

void Controller::reset(Sensor* s) {

}

void Controller::close(Sensor* s) {
	if (s->getType() == TEMP) {
		valve_temp = CLOSED;
	}
	else if (s->getType() == PRESSURE) {
		valve_pressure = CLOSED;
	}
}

void Controller::open(Sensor* s) {
	if (s->getType() == TEMP) {
		valve_temp = OPENED;
	}
	else if (s->getType() == PRESSURE) {
		valve_pressure = OPENED;
	}
}

void Controller::init() {
	status = DISABLED;
	temp_sensor->setValue(VALID_TEMP);
	pressure_sensor->setValue(VALID_PRESSURE);
}