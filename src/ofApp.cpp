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
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	ofRotateXDeg(-90);

	ofPushMatrix();
	mybody.bodyDraw();
	ofPopMatrix();


	ofSetColor(255, 0, 0);
	vec4 origin(0, 0, 0, 1);
	//vec3 lstart = mybody.larm.modelMatrix * origin;
	//vec3 rstart = mybody.rarm.modelMatrix * origin;
	//vec3 lstart = mybody.larm.elbow;
	//vec3 rstart = mybody.rarm.elbow;
	//ofLog() << "L: " << lstart;
	//ofLog() << "R: " << rstart;
	//ofDrawLine(lstart, rstart);

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
