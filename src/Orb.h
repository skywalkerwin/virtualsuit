#pragma once
#include "ofMain.h"
using namespace glm;

class Orb
{
public:
	
	void setupOrb();
	void drawOrb(vec3 pos);
	Orb();
	~Orb();

	ofSpherePrimitive orb;
};

