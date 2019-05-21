#pragma once
#include "ofMain.h"
using namespace glm;

class LightCycle
{
public:
	void setupCycle();
	vec3 drawCycle();
	LightCycle();
	~LightCycle();

	ofCylinderPrimitive wheel1;
	ofCylinderPrimitive wheel2;
	ofBoxPrimitive core;
};

