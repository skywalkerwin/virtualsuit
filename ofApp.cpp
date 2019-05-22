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
	mybody.bodySetup(cycle.core);
	//saber.setupSword();
	myorb.setupOrb();
	//cam.setUpAxis(-cam.getYAxis());
	//cam.setGlobalPosition(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	//cam.rotateDeg(120, cam.getXAxis());

	//cam.lookAt(mybody.torso);
	//cam.lookAt(cycle.core);
	cam.setFarClip(200000);
	//cam.setAspectRatio(1.78);

}

//--------------------------------------------------------------
void ofApp::update(){
	mybody.bodyUpdate();
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

	ofDrawBitmapString(mybody.rarm.yaw[2], 20, 80);
	ofDrawBitmapString(mybody.rarm.pitch[2], 20, 100);
	ofDrawBitmapString(mybody.rarm.roll[2], 20, 120);

	cam.begin();
	ofScale(1, -1, 1);
	//cam.lookAt(cycle.core);
	//cam.setTarget(cycle.core);
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight(), 0);
	ofRotateZDeg(-90);

	ofSetLineWidth(5);
	ofSetColor(24, 202, 230);
	ofDrawGridPlane(500, 2000);
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
	vec3 p=cycle.drawCycle();

	mybody.bodyDraw(p);
	ofDrawAxis(200);
	ofPopMatrix();
	//saber.drawSword(mybody.rarm.handquat, mybody.rarm.handpos, mybody.rarm.switchbinary);
	vec3 midpoint = (mybody.rarm.handpos + mybody.larm.handpos)/2;
	myorb.drawOrb(midpoint);

	ofPopMatrix();

	cam.end();
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
	float accel = 0;
	if (mybody.rarm.switchbinary == 1) {
		accel = mybody.rarm.pitch[2];
		cycle.accelerate(accel);
	}
	cycle.update();
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
