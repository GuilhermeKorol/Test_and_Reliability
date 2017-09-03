#include "stdafx.h"
#include "controller.h"


Controller::Controller(Sensor * temp, Sensor * pres) : sensor_temp(temp), sensor_pressure(pres) {
	init();
}

Controller::~Controller() {

}

bool Controller::enable() {
	if (ps == q0) {
		if (status == DISABLED) {
			printf("Controller ENABLED\n");
			status = ENABLED;
			ps = q3;
			return true;
		}
	}
	return false;
}

bool Controller::disable() {
	if (ps == q3) {
		if (status == ENABLED) {
			printf("Controller DISABLED\n");
			status = DISABLED;
			ps = q0;
			return true;
		}
	}
	return false;
}

bool Controller::alert(int type) {
	if (type == TEMP) {
		if (sensor_temp->getAlert() == ON && (ps == q3 || ps == q5) ) {
			valve_temp = OPENED;
			printf("Temperature valve OPENED\n");
			if (ps == q3) {
				ps = q4;
			}
			else {
				ps = q6;
			}
			return true;
		}
	}
	else {
		if (sensor_pressure->getAlert() == ON && (ps == q3 || ps == q4) ) {
			valve_pressure = OPENED;
			printf("Pressure valve OPENED\n");
			if (ps == q3) {
				ps = q5;
			}
			else {
				ps = q6;
			}
			return true;
		}
	}
	return false;
}

bool Controller::reset(int type) {
	if (type == TEMP) {
		if (sensor_temp->getAlert() == OFF && (ps == q4 || ps == q6) ) {
			close(type);
			if (ps == q4) {
				ps = q3;
			}
			else {
				ps = q5;
			}
			return true;
		}
	}
	else {
		if (sensor_pressure->getAlert() == OFF && (ps == q5 || ps == q6) ) {
			close(type);
			if (ps == q5) {
				ps = q3;
			}
			else {
				ps = q4;
			}
			return true;
		}
	}
	return false;
}

void Controller::close(int type) {
	if (type == TEMP) {
		valve_temp = CLOSED;
		printf("Temperature valve CLOSED\n");
	}
	else {
		valve_pressure = CLOSED;
		printf("Pressure valve CLOSED\n");
	}
}

void Controller::open(int type) {
	if (type == TEMP) {
		valve_temp = OPENED;
		printf("Temperature valve OPENED\n");
	}
	else {
		valve_pressure = OPENED;
		printf("Pressure valve OPENED\n");
	}
}

bool Controller::getV(int type) {
	if (ps == q0 || ps == q6) {
		if (type == TEMP) {
			return valve_temp;
		}
		else {
			return valve_pressure;
		}
	}
}

void Controller::init() {
	status = DISABLED;
	open(TEMP);
	open(PRESSURE);
	ps = q0;
}