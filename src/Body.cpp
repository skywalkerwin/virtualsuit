#include "Body.h"


//void Body::setupArm(Arm arm, string com) {
//	arm.setup(com);
//}

void Body::bodySetup() {
	larm.armSetup(leftcom, 0);
	rarm.armSetup(rightcom, 1);
	larm.start();
	rarm.start();
}
void Body::testimus(Arm &aArm) {
	for (int i = 0; i < 8; i++) {
		ofPushMatrix();
		ofTranslate(0, (1 + i) * ofGetHeight() / 9, 0);
		ofRotateXDeg(-90);
		ofRotateZDeg(aArm.yaw[i]);
		ofRotateXDeg(aArm.pitch[i]);
		ofRotateYDeg(-aArm.roll[i]);
		ofSetColor(0, 255, 0);
		ofFill();
		ofDrawBox(50);
		ofPopMatrix();
		ofLog() << i << ": "<< " Yaw: " << aArm.yaw[i] << " Pitch: " << aArm.pitch[i] << "Roll: " << -aArm.roll[i] << endl;
	}
}
void Body::bodyDraw() {
	//ofPushMatrix();
	//ofTranslate(1 * ofGetWidth() / 4, 0, 0);
	//testimus(larm);
	//ofPopMatrix();
	//ofPushMatrix();
	//ofTranslate(3 * ofGetWidth() / 4, 0, 0);
	//testimus(rarm);
	//ofPopMatrix();
}

Body::Body()
{
}


Body::~Body()
{
	larm.~Arm();
	rarm.~Arm();
}
