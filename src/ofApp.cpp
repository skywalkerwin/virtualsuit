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
	
	//ofPushMatrix();
	//mybody.testimus();
	//ofPopMatrix();
	//ofTranslate(500, 500, 0);
	//ofDrawBox(50);
	//mat4 viewm = ofGetCurrentViewMatrix();
	//mat4 normalm = ofGetCurrentNormalMatrix();
	//mat4 om = ofGetCurrentOrientationMatrix();
	//ofLog() <<"v"<< viewm << endl;
	//ofLog() <<"n"<< normalm << endl;
	//ofLog() <<"o"<< om << endl;
	ofPushMatrix();
	ofTranslate(100, 200);
	//ofDrawBox(50);
	ofSetColor(0, 255, 0);
	ofRect(0, 0, 100, 100);
	//ofMatrix4x4 currentMatrix = ofGetCurrentMatrix(ofMatrixMode::OF_MATRIX_MODELVIEW);
	//auto currentMatrix = ofGetCurrentMatrix(ofMatrixMode::OF_MATRIX_PROJECTION) * ofGetCurrentMatrix(ofMatrixMode::OF_MATRIX_MODELVIEW);
	//auto modelMatrix = ofGetCurrentMatrix(OF_MATRIX_MODELVIEW) * ofGetCurrentViewMatrix().getInverse();
	vec4 origin(0, 0, 0, 1); // x = 0, y = 0, z = 0 (1 for homogenous coord)
	mat4 modelMatrix = inverse(ofGetCurrentViewMatrix()) * ofGetCurrentMatrix(OF_MATRIX_MODELVIEW);
	ofPopMatrix();
	//ofVec3f origin(0, 0, 0);
	origin = modelMatrix * origin;
	ofTranslate((vec3)origin);
	ofSetColor(255, 0, 0);
	//ofDrawBox(25);
	ofRect(0, 0, 50, 50);
	ofLog() << "Translated origin" << origin; // should give you the new origin [100,200]
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
