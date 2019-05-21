#include "Body.h"


void Body::bodySetup(ofNode &c) {
	//torso.set(100, 100, 100);
	larm.armSetup(leftcom, torso, -1);
	rarm.armSetup(rightcom, torso, 1);
	lcycle = c;
	torso.setParent(c);
}

void Body::bodyDraw(vec3 v) {
	vec3 offset(0, 0, -160);
	torso.setGlobalPosition(v+offset);
	torsopos = torso.getGlobalPosition();
	//neckpos = torso.getGlobalPosition();
	larm.armDraw(torsopos);
	rarm.armDraw(torsopos);
	ofSetColor(255,0,0);
	//ofSetLineWidth(5);
	ofDrawLine(larm.handpos, rarm.handpos);
	//ofSetColor(255);
	torso.draw();

}

void Body::bodyUpdate() {
	//larm.armUpdate();
	//rarm.armUpdate();
	curLine++;
	if (curLine == maxLines) {
		curLine = 0;
	}
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
