#pragma once
#include "ofMain.h"
#include "Arm.h"
using namespace std;


class Body
{
public:
	Body();
	void bodySetup();
	void bodyUpdate();
	void bodyDraw();


	void testimus();


	~Body();

	string leftcom = "COM4";
	string rightcom = "COM5";

	Arm larm, rarm;
};

