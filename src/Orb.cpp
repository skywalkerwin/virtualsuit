#include "Orb.h"

void Orb::setupOrb() {
	orb.set(40, 20);
}

void Orb::drawOrb(vec3 pos) {
	orb.setGlobalPosition(pos);
	ofSetColor(0, 255, 0);
	orb.draw();
	orb.resetTransform();
}

Orb::Orb()
{
}


Orb::~Orb()
{
}
