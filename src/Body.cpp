#include "Body.h"


void Body::bodySetup() {
	larm.armSetup(leftcom, -1);
	rarm.armSetup(rightcom, 1);
	//larm.start();
	//rarm.start();
}

void Body::bodyDraw() {
	larm.armDraw();
	rarm.armDraw();
}

void Body::bodyUpdate() {
	//larm.armUpdate();
	//rarm.armUpdate();
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
	larm.~Arm();
	rarm.~Arm();
}
