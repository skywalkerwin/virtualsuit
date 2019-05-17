#pragma once

#include "ofMain.h"

#include "ofxXmlPoco.h"
#include "ofxIO.h"
#include "ofxSerial.h"
#include "Body.h"
#include "Arm.h"
#include "Sword.h"
#include "Orb.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void exit();
		
		Body mybody;
		Sword saber;
		Orb myorb;
		ofEasyCam cam;
};
