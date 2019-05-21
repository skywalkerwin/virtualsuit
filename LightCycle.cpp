#include "LightCycle.h"


void LightCycle::setupCycle() {
	wheel1.set(150, 150, 40, 1, 2, true);
	wheel2.set(150, 150, 40, 1, 2, true);
	wheel1.setCylinderColor(ofColor(24, 202, 230));
	wheel1.setTopCapColor(ofColor(24, 202, 230));
	wheel2.setCylinderColor(ofColor(24, 202, 230));
	wheel2.setTopCapColor(ofColor(24, 202, 230));
	core.set(150, 400, 150);
	for(int i=0; i<6;i++){
		core.setSideColor(i, ofColor(200));
	}
	wheel1.setParent(core);
	wheel2.setParent(core);
}

void LightCycle::drawCycle() {
	core.setGlobalPosition(200, 200, 0);
	//core.rotateDeg(50, core.getZAxis());
	core.draw();
	wheel1.boom(220);
	wheel2.boom(-220);
	wheel1.rotateDeg(90, core.getZAxis());
	wheel2.rotateDeg(90, core.getZAxis());

	wheel1.draw();
	wheel2.draw();
	core.resetTransform();
	wheel1.resetTransform();
	wheel2.resetTransform();
}

LightCycle::LightCycle()
{
}


LightCycle::~LightCycle()
{
}
