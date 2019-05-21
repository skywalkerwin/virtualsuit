#pragma once
#include "ofMain.h"
#include "Arm.h"
using namespace std;


class Body
{
public:
	Body();
	void bodySetup(ofNode &c);
	void bodyUpdate();
	void bodyDraw(vec3 v);
	void torsoDraw();


	void testimus();


	~Body();

	string leftcom = "COM4";
	string rightcom = "COM5";

	Arm larm , rarm;
	ofNode torso;
	ofNode lcycle;
	vec3 torsopos;
	static const int maxLines = 180;
	int curLine = 0;
	//vec3 neckpos;
};

