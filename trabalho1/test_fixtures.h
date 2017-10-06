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
		temp_sensor->setR(0.85);
		pressure_sensor->setR(0.85);
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
		sensor_ut->setR(0.85);
	}

	void TearDown() {
		delete sensor_ut;
	}

	~test_fixture_sensor() {
	}

	Sensor* sensor_ut; // Sensor Under Test
};

class test_fixture_sensor_nver : public ::testing::Test {
public:
	test_fixture_sensor_nver() {
		s1 = new (nothrow) Sensor(TEMP);
		s2 = new (nothrow) Sensor(TEMP);
		s3 = new (nothrow) Sensor(TEMP);

		//sensor_ut_s = new (nothrow) Sensor(PRESSURE);
		sensor_ut_nver = new (nothrow) Sensor_nver(s1,s2,s3);
	}

	void SetUp() {
		//sensor_ut_s->setR(0.85);

		s1->setR(0.5);
		s2->setR(0.75);
		s3->setR(1);
	}

	void TearDown() {
		//delete sensor_ut_s;
		delete sensor_ut_nver;
	}

	~test_fixture_sensor_nver() {
	}

	Sensor_nver* sensor_ut_nver; // Sensor Under Test N-version
	//Sensor* sensor_ut_s;			 // Simple sensor under test

	Sensor* s1;
	Sensor* s2;
	Sensor* s3;
};