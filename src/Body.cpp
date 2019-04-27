#include "Body.h"


void Body::bodySetup() {
	larm.armSetup(leftcom, torso, -1);
	rarm.armSetup(rightcom, torso, 1);
	//ofSetIcoSphereResolution(12);

}

void Body::bodyDraw() {
	vec3 origin(0, 0, 0);
	torso.setPosition(origin);
	//neckpos = torso.getGlobalPosition();
	larm.armDraw();
	rarm.armDraw();
	ofSetColor(255);
	ofDrawLine(larm.handpos, rarm.handpos);

}

void Body::bodyUpdate() {
	//larm.armUpdate();
	//rarm.armUpdate();
}
void Body::torsoDraw() {
	vec3 origin(0, 0, 0);
	torso.setPosition(origin);
}

void Body::testimus() {
	ofPushMatrix();
	ofTranslate(1 * ofGetWidth() / 4, 0, 0);
	larm.testimus();
	ofPopMatrix();
	ofPushMatrix();
	ofTranslate(3 * ofGetWidth() / 4, 0, 0);
	rarm.testimus();
	ofPopMatrix();
}

Body::Body()
{
}


Body::~Body()
{
	//larm.~Arm();
	//rarm.~Arm();
	//delete &larm;
	//delete &rarm;
}
