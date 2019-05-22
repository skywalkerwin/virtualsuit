#pragma once
#include "ofMain.h"
using namespace glm;

class LightCycle
{
public:
	void setupCycle();
	void update();
	void brake();
	void accelerate(float a);
	vec3 drawCycle();
	LightCycle();
	~LightCycle();

	ofCylinderPrimitive wheel1;
	ofCylinderPrimitive wheel2;
	ofBoxPrimitive core;
	float acceleration;
	float vel;
};

