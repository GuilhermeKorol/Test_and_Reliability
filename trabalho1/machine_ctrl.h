#pragma once
#include "stdafx.h"

enum states { q0, q3, q4, q5, q6 };

class Machine_ctrl {
private:
	states ps;
	states ns;
	Controller * ctrl;
public:
	Machine_ctrl(Sensor * temp, Sensor * pres);
	void update_state();
	~Machine_ctrl();
};