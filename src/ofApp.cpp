#include "ofApp.h"
using namespace glm;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(false);
	ofSetFrameRate(200);
	//ofSetFrameRate(60);
	ofSetColor(0, 255, 0);
	ofBackground(0);
	ofEnableDepthTest();
	cycle.setupCycle();
	cycle.trail.push_back(cycle.core.getGlobalPosition());
	cycle.mtrail.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	cycle.mtrail.addColor(ofColor(255, 0, 0, 150));
	cycle.mtrail.addVertex(cycle.core.getGlobalPosition() + vec3(0, 0, -1000));
	cycle.mtrail.addColor(ofColor(255, 0, 0, 150));
	cycle.mtrail.addVertex(cycle.core.getGlobalPosition());
	mybody.bodySetup(cycle.core.getGlobalPosition());
	//saber.setupSword();
	myorb.setupOrb();
	cam.setFov(90);
	cam.setFarClip(200000);
	cam.setGlobalPosition(980, 1000, 3000);
	//cam.lookAt(cycle.core);
	//cam.setOrientation(vec3(-22, 0, 0));
	//cam.tiltDeg(-22);

}

//--------------------------------------------------------------
void ofApp::update(){
	std::stringstream strm;
	strm << "fps: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());
	updatePos();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	ofDrawBitmapString(cam.getX(), 20, 20);
	ofDrawBitmapString(cam.getY(), 20, 40);
	ofDrawBitmapString(cam.getZ(), 20, 60);

	ofDrawBitmapString(cam.getHeadingDeg(), 20, 100);
	ofDrawBitmapString(cam.getPitchDeg(), 20, 120);
	ofDrawBitmapString(cam.getRollDeg(), 20, 140);
	ofDrawBitmapString(cam.getLookAtDir(), 20, 160);

	ofDrawBitmapString(mybody.rarm.yaw[2], 20, 180);
	ofDrawBitmapString(mybody.rarm.pitch[2], 20, 200);
	ofDrawBitmapString(mybody.rarm.roll[2], 20, 220);

	ofDrawBitmapString(cycle.core.getGlobalPosition(), 1700, 240);
	ofDrawBitmapString(mybody.torso.getGlobalPosition(), 1700, 260);

	ofDrawBitmapString(cycle.dir, 20, 280);
	ofDrawBitmapString(cycle.core.getHeadingDeg(), 20, 300);
	ofDrawBitmapString(cycle.core.getPitchDeg(), 20, 320);
	ofDrawBitmapString(cycle.core.getRollDeg(), 20, 340);

	cam.setGlobalPosition(cycle.core.getX(), 2000, -cycle.core.getY());
	cam.rotateDeg(cycle.core.getRollDeg(), 0, 1, 0);
	cam.move(cam.getZAxis() * 4000);
	//cam.lookAt(cycle.core);

	cam.tiltDeg(-25);

	cam.begin();
	ofScale(1, -1, 1);
	//cam.lookAt(cycle.core);
	//cam.setTarget(cycle.core);
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight(), 0);
	ofRotateZDeg(-90);

	ofSetLineWidth(5);
	ofSetColor(24, 202, 230);
	ofDrawGridPlane(2000, 500);
	ofSetLineWidth(7);
	ofTranslate(0, .5, 0);
	ofSetLineWidth(5);
	ofPopMatrix();

	//ofDrawBitmapString(mybody.rarm.switchbinary, 20, 20);

	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	ofRotateXDeg(-90);
	ofSetLineWidth(1);
	ofPushMatrix();
	cycle.drawCycle();

	mybody.bodyDraw();
	ofDrawAxis(200);
	ofPopMatrix();
	//saber.drawSword(mybody.rarm.handquat, mybody.rarm.handpos, mybody.rarm.switchbinary);
	vec3 midpoint = (mybody.rarm.handpos + mybody.larm.handpos)/2;
	myorb.drawOrb(midpoint);

	ofPopMatrix();

	cam.end();
	cam.resetTransform();
	ofScale(1, 1, 1);
	ofPushMatrix();
	ofRotateXDeg(-90);
	ofTranslate(ofGetWidth() / 4, ofGetHeight() / 2, 0);
	mybody.larm.handtilt();
	ofTranslate(ofGetWidth() / 2, 0, 0);
	mybody.rarm.handtilt();
	ofPopMatrix();
	//cam.resetTransform();



}

void ofApp::updatePos() {
	ofLog() << distance(cycle.core.getGlobalPosition(), cycle.trail.back()) << endl;
	if (distance(cycle.core.getGlobalPosition(), cycle.trail.back()) > 1000) {
		cycle.trail.push_back(cycle.core.getGlobalPosition());
		cycle.mtrail.addColor(ofColor(255, 0, 0, 150));
		cycle.mtrail.addVertex(cycle.core.getGlobalPosition() + vec3(0, 0, -1000));
		cycle.mtrail.addColor(ofColor(255, 0, 0, 150));
		cycle.mtrail.addVertex(cycle.core.getGlobalPosition());
		//ofSetColor(255);
		//ofDrawBox(vec3(cycle.core.getGlobalPosition()), 1000);
		//ofLog() << "BOX" << endl;
	}
	float accel = 0;
	if (mybody.rarm.switchbinary == 1) {
		accel = mybody.rarm.pitch[2];
		cycle.accelerate(accel);
	}
	cycle.update();
	cycle.steer(mybody.rarm.roll[2]);

	mybody.bodyUpdate(cycle.core.getGlobalPosition());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	vec3 v;
	int move = 50;
	switch (key) {
	case 'a':
		v = vec3(-move, 0, 0);
		cam.setGlobalPosition(cam.getGlobalPosition() + v);
		break;
	case 'q':
		v = vec3(0, move, 0);
		cam.setGlobalPosition(cam.getGlobalPosition() + v);
		break;
	case 'd':
		v = vec3(move, 0, 0);
		cam.setGlobalPosition(cam.getGlobalPosition() + v);
		break;
	case 'e':
		v = vec3(0, -move, 0);
		cam.setGlobalPosition(cam.getGlobalPosition() + v);
		break;
	case 's':
		v = vec3(0, 0, move);
		cam.setGlobalPosition(cam.getGlobalPosition() + v);
		break;
	case 'w':
		v = vec3(0, 0, -move);
		cam.setGlobalPosition(cam.getGlobalPosition() + v);
		break;
	case 'l':
		//v = vec3(0, 0, -move);
		cam.lookAt(cycle.core);
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::exit() {
	//mybody.~Body();
}
