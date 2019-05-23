#pragma once
#include "ofMain.h"
#include "Arm.h"
//#include "LightCycle.h"
using namespace std;


class Body
{
public:
	Body();
	void bodySetup(vec3 v);
	void bodyUpdate(vec3 v);
	void bodyDraw();
	void torsoDraw();


	void testimus();


	~Body();

	string leftcom = "COM4";
	string rightcom = "COM5";

	Arm larm , rarm;
	ofBoxPrimitive torso;
	//LightCycle* lcycle;
	vec3 torsopos;
	static const int maxLines = 180;
	int curLine = 0;
	//vec3 neckpos;
};

