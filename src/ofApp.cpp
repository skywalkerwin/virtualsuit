#include "ofApp.h"
using namespace glm;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(false);
	ofSetFrameRate(200);
	//ofSetFrameRate(60);
	ofSetColor(0, 255, 0);
	ofBackground(0);
	mybody.bodySetup();
	ofEnableDepthTest();
	saber.setupSword();
	//cam.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 500);
	//cam.lookAt(mybody.torso);
	//cam.setFarClip(10000);
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
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight(), 0);
	ofRotateZDeg(-90);
	ofSetLineWidth(5);
	ofSetColor(24, 202, 230);
	ofDrawGridPlane(500, 2000);
	ofSetLineWidth(7);
	//ofSetColor(216, 218, 231);
	ofTranslate(0, .5, 0);
	//ofDrawGridPlane(1000, 100);
	ofSetLineWidth(5);
	ofPopMatrix();

	ofDrawBitmapString(mybody.rarm.switchbinary, 20, 20);
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	ofRotateXDeg(-90);
	//cam.setGlobalPosition(vec3(0,0,0));
	//cam.setGlobalPosition(vec3(0, 200, 200));
	//cam.begin();

	ofSetLineWidth(1);
	ofPushMatrix();
	mybody.bodyDraw();

	ofPopMatrix();
	saber.drawSword(mybody.rarm.handquat, mybody.rarm.handpos, mybody.rarm.switchbinary);
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

	//cam.end();
	//cam.resetTransform();

	ofPopMatrix();



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
