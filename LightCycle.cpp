#include "LightCycle.h"


void LightCycle::setupCycle() {
	wheel1.set(150, 150, 40, 1, 2, true);
	wheel2.set(150, 150, 40, 1, 2, true);
	//wheel1.setCylinderColor(ofColor(24, 202, 230));
	//wheel1.setTopCapColor(ofColor(24, 202, 230));
	//wheel2.setCylinderColor(ofColor(24, 202, 230));
	//wheel2.setTopCapColor(ofColor(24, 202, 230));

	wheel1.setCylinderColor(ofColor(255));
	wheel1.setTopCapColor(ofColor(255));
	wheel1.setBottomCapColor(ofColor(255));
	wheel2.setCylinderColor(ofColor(155));
	wheel2.setTopCapColor(ofColor(155));
	wheel2.setBottomCapColor(ofColor(155));
	core.set(150, 600, 140);
	for(int i=0; i<6;i++){
		core.setSideColor(i, ofColor(50));
	}
	wheel1.setParent(core);
	wheel2.setParent(core);
}

vec3 LightCycle::drawCycle() {
	core.setGlobalPosition(0, 0, ofGetHeight()/2-140);
	vec3 p = core.getGlobalPosition();
	//core.rotateDeg(50, core.getZAxis());
	core.draw();
	wheel1.boom(-300);
	wheel2.boom(300);
	wheel1.rotateDeg(90, core.getZAxis());
	wheel2.rotateDeg(90, core.getZAxis());

	wheel1.draw();
	wheel2.draw();
	core.resetTransform();
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
