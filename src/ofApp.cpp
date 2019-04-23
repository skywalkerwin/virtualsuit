#include "ofApp.h"

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
	std::stringstream strm;
	strm << "fps: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());
}

//--------------------------------------------------------------
void ofApp::draw(){
	//mybody.bodyDraw();
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
