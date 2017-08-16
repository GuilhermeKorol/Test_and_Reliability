// trabalho1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "controller.h"

int main()
{
	Controller* c = new Controller();

	printf("Controller instantiated\n");

	c->enable();
	printf("Controller enabled\n");

	while (true) {
	}

	delete c;

    return 0;
}

