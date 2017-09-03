#pragma once
#include "stdafx.h"

class Machine_ctrl {
private:
	states_ctrl ps;
	states_ctrl ns;
	Controller * ctrl;
public:
	Machine_ctrl(Sensor * temp, Sensor * pres);
	void update_state();
	states_ctrl getState();
	Controller* get_ctrl();
	~Machine_ctrl();
};