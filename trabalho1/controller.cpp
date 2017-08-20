#include "stdafx.h"
#include "controller.h"


Controller::Controller() {
	init();
}

Controller::~Controller() {

}

void Controller::enable() {
	printf("Controller ENABLED\n");
	status = ENABLED;
}

void Controller::disable() {
	printf("Controller DISABLED\n");
	status = DISABLED;
}

void Controller::alert(Sensor* s) {
	if( s->getAlert() == ON) {
		if (s->getType() == TEMP) {
			valve_temp = OPENED;
			printf("Temperature valve OPENED\n");
		}
		else {
			valve_pressure = OPENED;
			printf("Pressure valve OPENED\n");
		}
	}
}

void Controller::reset(Sensor* s) {
	if (s->getAlert() == OFF) {
		if (s->getType() == TEMP) {
			valve_temp = CLOSED;
			printf("Temperature valve CLOSED\n");
		}
		else {
			valve_pressure = CLOSED;
			printf("Pressure valve CLOSED\n");
		}
	}
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

void Controller::init() {
	status = DISABLED;
}