#include "stdafx.h"
#include "machine_ctrl.h"

Machine_ctrl::Machine_ctrl(Sensor * temp, Sensor * pres) {
	ps = q0;
	ns = q0;

	ctrl = new (nothrow) Controller(temp,pres);
}

void Machine_ctrl::update_state() {
	switch (ps)
	{
	case q0:
		if (ctrl->getV(TEMP) == CLOSED || ctrl->getV(PRESSURE) == CLOSED) {
			ns = q0;
		}
		else if (ctrl->enable() == ENABLED) {
			ns = q3;
		}
		break;
	case q3:
		if (ctrl->disable() == DISABLED) {
			ns = q0;
		}
		else if (ctrl->alert(TEMP) == true) {
			ns = q4;
		}
		else if (ctrl->alert(PRESSURE) == true) {
			ns = q5;
		}
		break;
	case q4:
		if (ctrl->getV(TEMP) == OPENED) {
			ns = q4;
		}
		else if (ctrl->reset(TEMP) == true) {
			ns = q3;
		}
		else if (ctrl->alert(PRESSURE) == true) {
			ns = q6;
		}
		break;
	case q5:
		if (ctrl->getV(PRESSURE) == OPENED) {
			ns = q5;
		}
		else if (ctrl->alert(TEMP) == true) {
			ns = q6;
		}
		else if (ctrl->reset(PRESSURE) == true) {
			ns = q3;
		}
		break;
	case q6:
		if (ctrl->getV(TEMP) == OPENED || ctrl->getV(PRESSURE) == OPENED) {
			ns = q6;
		}
		else if (ctrl->reset(TEMP) == true) {
			ns = q5;
		}
		else if (ctrl->reset(PRESSURE) == true) {
			ns = q4;
		}
		break;
	default:
		printf("Unexpected state...\n");
		break;
	}
	ps = ns;
}

Machine_ctrl::~Machine_ctrl() {
	delete ctrl;
}