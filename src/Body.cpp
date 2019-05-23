#include "Body.h"


void Body::bodySetup(vec3 v) {
	torso.set(50);
	larm.armSetup(leftcom, torso, -1);
	rarm.armSetup(rightcom, torso, 1);
	//*lcycle = c;
	//torso.setParent(lcycle->core);
	vec3 offset(0, 0, -120);
	torso.setGlobalPosition(v + offset);

}

void Body::bodyDraw() {
	//vec3 offset(0, 0, -120);
	//torso.setGlobalPosition(lcycle->getGlobalPosition()+offset);
	torsopos = torso.getGlobalPosition();
	//neckpos = torso.getGlobalPosition();
	larm.armDraw(torsopos);
	rarm.armDraw(torsopos);
	ofSetColor(255,0,0);
	//ofSetLineWidth(5);
	ofDrawLine(larm.handpos, rarm.handpos);
	//ofSetColor(255);
	torso.draw();
	torso.resetTransform();

}

void Body::bodyUpdate(vec3 v) {
	//larm.armUpdate();
	//rarm.armUpdate();
	curLine++;
	if (curLine == maxLines) {
		curLine = 0;
	}
	//auto velVector = torso.getYAxis() * vel;
	//torso.move(velVector);
	torso.setGlobalPosition(v);
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
