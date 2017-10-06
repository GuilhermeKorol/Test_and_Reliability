#include "stdafx.h"
#include "sensor_nversoes.h"

Sensor_nver::Sensor_nver(Sensor * s1, Sensor * s2, Sensor * s3):s1(s1),s2(s2),s3(s3)
{
	// Sensor* s1 = new (nothrow) Sensor(TEMP);
	// Sensor* s2 = new (nothrow) Sensor(TEMP);
	// Sensor* s3 = new (nothrow) Sensor(TEMP);
}

Sensor_nver::~Sensor_nver()
{
}

bool Sensor_nver::setH() {
	bool ret1 = s1->setH();
	bool ret2 = s2->setH();
	bool ret3 = s3->setH();

	if (((int)ret1 + (int)ret2 + (int)ret3) >= 2) {
		//printf("NVER-setH: ret1 = %d ret2 = %d ret3 = %d\n", ret1, ret2, ret3);
		return true;
	}
	else {
		//printf("NVER-setH: ret1 = %d ret2 = %d ret3 = %d\n", ret1, ret2, ret3);
		return false;
	}
}

bool Sensor_nver::resetH() {
	bool ret1 = s1->resetH();
	bool ret2 = s2->resetH();
	bool ret3 = s3->resetH();

	if (((int)ret1 + (int)ret2 + (int)ret3) >= 2) {
		//printf("NVER-resetH: ret1 = %d ret2 = %d ret3 = %d\n", ret1, ret2, ret3);
		return true;
	}
	else {
		//printf("NVER-resetH: ret1 = %d ret2 = %d ret3 = %d\n", ret1, ret2, ret3);
		return false;
	}
}
bool Sensor_nver::getH() {
	bool ret1 = s1->getH();
	bool ret2 = s2->getH();
	bool ret3 = s3->getH();

	if (((int)ret1 + (int)ret2 + (int)ret3) >= 2) {
		//printf("NVER-getH: ret1 = %d ret2 = %d ret3 = %d\n", ret1, ret2, ret3);
		return true;
	}
	else {
		//printf("NVER-getH: ret1 = %d ret2 = %d ret3 = %d\n", ret1, ret2, ret3);
		return false;
	}
}

//void Sensor_nver::setR(float r) {
//}
//float Sensor_nver::getR() {
//}

bool Sensor_nver::setValue(float v) {
	bool ret1 = s1->setValue(v);
	bool ret2 = s2->setValue(v);
	bool ret3 = s3->setValue(v);

	if (((int)ret1 + (int)ret2 + (int)ret3) >= 2) {
		//printf("NVER-setValue: ret1 = %d ret2 = %d ret3 = %d\n", ret1, ret2, ret3);
		return true;
	}
	else {
		//printf("NVER-setValue: ret1 = %d ret2 = %d ret3 = %d\n", ret1, ret2, ret3);
		return false;
	}
}
bool Sensor_nver::getAlert() {
	bool ret1 = s1->getAlert();
	bool ret2 = s2->getAlert();
	bool ret3 = s3->getAlert();

	if (((int)ret1 + (int)ret2 + (int)ret3) >= 2) {
		//printf("NVER-getAlert: ret1 = %d ret2 = %d ret3 = %d\n", ret1, ret2, ret3);
		return true;
	}
	else {
		//printf("NVER-getAlert: ret1 = %d ret2 = %d ret3 = %d\n", ret1, ret2, ret3);
		return false;
	}
}

int	Sensor_nver::getType() {
	return TEMP; //testing n-version only for TEMP...
}