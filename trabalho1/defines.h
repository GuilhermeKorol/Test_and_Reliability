#pragma once

// States of the Controller FSM
enum states_ctrl { q0, q3, q4, q5, q6 };

//	Types of sensors
#define	TEMP		1
#define	PRESSURE	2

// Type of valves
#define VALVE_TEMP 1
#define	VALVE_PRESSURE 2

//  Status of valves
#define	OPENED	true
#define CLOSED	false

//	Controller/Sensor status
#define ENABLED		true
#define DISABLED	false

//	Valid values of temperature and pressure
#define VALID_TEMP		20
#define VALID_PRESSURE	800

//	Limit values for temperatue and pressure
#define	LIMIT_TEMP		40
#define LIMIT_PRESSURE	1013

//	Alert status
#define ON	true
#define OFF false

//  Range for randomic values of temperature and pressure
#define MAX_TEMP 80
#define MIN_TEMP 1
#define MAX_PRESSURE 2026
#define MIN_PRESSURE 1


