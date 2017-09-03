#pragma once
#include "stdafx.h"
#include "gtest/gtest.h"

class test_fixture_ctrl : public ::testing::Test {
public:
	test_fixture_ctrl() {
		temp_sensor = new (nothrow) Sensor(TEMP);
		pressure_sensor = new (nothrow) Sensor(PRESSURE);
		ctrl_ut = new (nothrow) Controller(temp_sensor, pressure_sensor);
		//fsm_ctrl_ut = new (nothrow) Machine_ctrl_ut(temp_sensor, pressure_sensor);

	}

	void SetUp() {
		temp_sensor->setR(1.0);
		pressure_sensor->setR(1.0);
	}

	void TearDown() {
		delete temp_sensor;
		delete pressure_sensor;
		delete ctrl_ut;
	}

	~test_fixture_ctrl() {
	}

	Sensor* temp_sensor;
	Sensor* pressure_sensor;
	Controller* ctrl_ut;		// Controller Under Test
	//Machine_ctrl* fsm_ctrl_ut;
};

class test_fixture_sensor : public ::testing::Test {
public:
	test_fixture_sensor() {
		sensor_ut = new (nothrow) Sensor(TEMP);
	}

	void SetUp() {
		sensor_ut->setR(1.0);
	}

	void TearDown() {
		delete sensor_ut;
	}

	~test_fixture_sensor() {
	}

	Sensor* sensor_ut; // Sensor Under Test
};