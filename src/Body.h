#pragma once
#include "ofMain.h"
#include "Arm.h"
using namespace std;


class Body
{
public:
	Body();
	void bodySetup();
	void testimus(Arm &a);
	void bodyDraw();

	~Body();

	string leftcom = "COM4";
	string rightcom = "COM5";

	Arm larm, rarm;
};

