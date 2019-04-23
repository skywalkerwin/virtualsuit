#include "ofApp.h"
using namespace glm;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(false);
	ofSetFrameRate(500);
	//ofSetFrameRate(60);
	ofSetColor(0, 255, 0);
	ofBackground(0);
	mybody.bodySetup();
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
	//mybody.bodyDraw();
	//ofPushMatrix();
	//ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	//ofRotateXDeg(45);
	//ofDrawRotationAxes(100, 1, 10);
	//vec3 endx(100, 0, 0);
	//vec3 endy(0, 100, 0);
	//vec3 endz(0, 0, 100);
	//vec3 start(0, 0, 0);
	//ofSetColor(255, 0, 0);
	//ofDrawArrow(start, endx, 10);
	//ofSetColor(0, 255, 0);
	//ofDrawArrow(start, endy, 10);
	//ofSetColor(0, 0, 255);
	//ofDrawArrow(start, endz, 10);
	//ofPopMatrix();

	ofPushMatrix();
	ofTranslate(1 * ofGetWidth() / 4, 0, 0);
	mybody.testimus(mybody.larm);
	ofPopMatrix();
	ofPushMatrix();
	ofTranslate(3 * ofGetWidth() / 4, 0, 0);
	mybody.testimus(mybody.rarm);
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
	mybody.~Body();
}
