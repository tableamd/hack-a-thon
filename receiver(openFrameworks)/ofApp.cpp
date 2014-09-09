#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//we run at 60 fps!
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
    ofSetFullscreen(true);

    //port 11999, localhost
	udpConnection.Create();
	udpConnection.Bind(11999);
	udpConnection.SetNonBlocking(true);

	ofSetBackgroundAuto(false);
	ofBackground(255, 255, 255);
    x = 0;
    now_x = ofGetWidth() / 2;
    now_y = ofGetHeight() / 2;
}

//--------------------------------------------------------------
void ofApp::update(){

	char udpMessage[100000];
	udpConnection.Receive(udpMessage,100000);
	string message=udpMessage;
    
    ofSetColor(0, 0, 0);
    if(message != ""){
        //ofDrawBitmapString(message, 100,x);
        //x += 9;
        vector<string> tmp;
        tmp = split(message, ':');
        for(int i=0;i<2;i++){
            stringstream ss(tmp[i]);
            float val;
            ss >> val;
            
            if(i==0)
                //now_x += now_x<0||now_x>ofGetWidth()?0:val*3;
                now_x += val * 3;
            
            if(i==1)
                //now_y -= now_y<0||now_y>ofGetHeight()?0:val*3;
                now_y -= val * 3;
        }
        stroke.push_back(ofPoint(now_x,now_y));
        //printf("now_x:%d now_y:%d", now_x,now_y);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    for(unsigned int i=1;i<stroke.size();i++){
        ofSetColor(0, 0, 0);
		ofLine(stroke[i-1].x,stroke[i-1].y,stroke[i].x,stroke[i].y);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_RETURN)
        stroke.clear();
    if(key == 'c'){
        now_x = ofGetWidth()/2;
        now_y = ofGetHeight()/2;
        stroke.clear();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

vector<string> ofApp::split(const string &str, char delim){
    istringstream iss(str);
    string tmp;
    vector<string> res;
    while(getline(iss, tmp, delim))
        res.push_back(tmp);
    return res;
}
