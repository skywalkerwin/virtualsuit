#include "LightCycle.h"


void LightCycle::setupCycle() {
	wheel1.set(200, 200, 40, 1, 2, true);
	wheel2.set(200, 200, 40, 1, 2, true);
	//wheel1.setCylinderColor(ofColor(24, 202, 230));
	//wheel1.setTopCapColor(ofColor(24, 202, 230));
	//wheel2.setCylinderColor(ofColor(24, 202, 230));
	//wheel2.setTopCapColor(ofColor(24, 202, 230));

	wheel1.setCylinderColor(ofColor(255));
	wheel1.setTopCapColor(ofColor(255));
	wheel1.setBottomCapColor(ofColor(255));
	wheel2.setCylinderColor(ofColor(0,0,255));
	wheel2.setTopCapColor(ofColor(0,0,255));
	wheel2.setBottomCapColor(ofColor(0,0,255));
	core.set(180, 800, 180);
	core.setGlobalPosition(0, 0, ofGetHeight() / 2 - 190);

	for(int i=0; i<6;i++){
		core.setSideColor(i, ofColor(50));
	}
	wheel1.setParent(core);
	wheel2.setParent(core);
}

void LightCycle::update() {
	vel += acceleration;
	vel *= 0.9;
	acceleration *= 0.99;
	// here we are defining the vector that contains the direction
	// in which the car should move, that is defined by the z-axis of the car and the velocity
	auto velVector = core.getYAxis() * vel;
	core.move(velVector);
}

void LightCycle::brake() {
	acceleration -= 0.1;
}

void LightCycle::accelerate(float a) {
	acceleration += 0.005*a;
}

vec3 LightCycle::drawCycle() {
	vec3 p = core.getGlobalPosition();
	//core.rotateDeg(50, core.getZAxis());
	core.draw();
	wheel1.boom(400);
	wheel2.boom(-400);
	wheel1.rotateDeg(90, core.getZAxis());
	wheel2.rotateDeg(90, core.getZAxis());

	wheel1.draw();
	wheel2.draw();
	//core.resetTransform();
	wheel1.resetTransform();
	wheel2.resetTransform();
	return p;
}

LightCycle::LightCycle()
{
}


LightCycle::~LightCycle()
{
}
