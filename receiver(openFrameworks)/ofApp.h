#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        vector<string> split(const string &str, char delim);
        vector<ofPoint> stroke;
		ofxUDPManager udpConnection;
        int x;
        int now_x;
        int now_y;
};

