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
	void torsoDraw();


	void testimus();


	~Body();

	string leftcom = "COM4";
	string rightcom = "COM5";

	Arm larm , rarm;
	ofNode torso;
	vec3 torsopos;
	static const int maxLines = 180;
	int curLine = 0;
	//vec3 neckpos;
};

