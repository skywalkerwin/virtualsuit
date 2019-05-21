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
	cam.setGlobalPosition(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	cam.rotateDeg(120, cam.getXAxis());

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
}

//--------------------------------------------------------------
void ofApp::draw(){
	//cam.setGlobalPosition(ofGetWidth() / 2, ofGetHeight() / 2, 1000);
	//cam.setGlobalPosition(vec3(0, 500, 500));
	//cam.rotateDeg(-90, cam.getXAxis());
	ofDrawBitmapString(cam.getX(), 20, 20);
	ofDrawBitmapString(cam.getY(), 20, 40);
	ofDrawBitmapString(cam.getZ(), 20, 60);
	cam.begin();

	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight(), 0);
	ofRotateZDeg(-90);

	ofSetLineWidth(5);
	ofSetColor(24, 202, 230);
	//ofSetColor(254, 1, 154);
	ofDrawGridPlane(500, 2000);
	ofSetLineWidth(7);
	//ofSetColor(216, 218, 231);
	ofTranslate(0, .5, 0);
	//ofDrawGridPlane(1000, 100);
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
	//ofSetColor(255, 0, 100);
	//ofSetLineWidth(1);
	//for (int i = mybody.curLine + 1; i < mybody.maxLines-2; i++) {
	//	ofDrawLine(mybody.larm.handpoint[i], mybody.rarm.handpoint[i]);
	//	ofDrawLine(mybody.larm.handpoint[i], mybody.larm.handpoint[i+1]);
	//	ofDrawLine(mybody.rarm.handpoint[i], mybody.rarm.handpoint[i+1]);
	//}
	//ofDrawLine(mybody.larm.handpoint[mybody.maxLines - 1], mybody.rarm.handpoint[mybody.maxLines - 1]);
	//ofDrawLine(mybody.larm.handpoint[mybody.maxLines - 1], mybody.larm.handpoint[0]);
	//ofDrawLine(mybody.rarm.handpoint[mybody.maxLines - 1], mybody.rarm.handpoint[0]);
	//for (int i = 0; i < mybody.curLine-1; i++) {
	//	ofDrawLine(mybody.larm.handpoint[i], mybody.rarm.handpoint[i]);
	//	ofDrawLine(mybody.larm.handpoint[i], mybody.larm.handpoint[i+1]);
	//	ofDrawLine(mybody.rarm.handpoint[i], mybody.rarm.handpoint[i+1]);
	//}

	//ofDrawLine(mybody.larm.handpoint[mybody.curLine - 1], mybody.larm.handpoint[mybody.curLine]);
	//ofDrawLine(mybody.rarm.handpoint[mybody.curLine - 1], mybody.rarm.handpoint[mybody.curLine]);

	ofPopMatrix();

	//ofPushMatrix();
	//ofTranslate(ofGetWidth() / 2, ofGetHeight(), 0);
	//ofRotateZDeg(-90);
	//ofSetLineWidth(5);
	//ofSetColor(24, 202, 230);
	//ofDrawGridPlane(500, 2000);
	//ofSetLineWidth(7);
	////ofSetColor(216, 218, 231);
	//ofTranslate(0, .5, 0);
	////ofDrawGridPlane(1000, 100);
	//ofSetLineWidth(5);
	//ofPopMatrix();
	cam.end();
	//cam.resetTransform();



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
