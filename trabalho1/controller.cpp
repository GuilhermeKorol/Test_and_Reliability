#include "stdafx.h"
#include "controller.h"


Controller::Controller() {
	init();
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

bool Controller::getV(Sensor* s) {
	if (s->getType() == TEMP) {
		if (valve_temp == OPENED) {
			return true;
		}
		else return false;
	}
	else if (s->getType() == PRESSURE) {
		if (valve_pressure == OPENED) {
			return true;
		}
		else return false;
	}
}

void Controller::init() {
	status = DISABLED;
}