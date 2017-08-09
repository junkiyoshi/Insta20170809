#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(0);
	//ofSetBackgroundAuto(false);
	ofSetWindowTitle("Insta");
	
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	int angle_step = 20;

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	ofPushMatrix();

	ofSetLineWidth(0.3);
	ofSetColor(32);
	for (int i = 0; i < 360; i += angle_step / 2) {
		ofRotate(angle_step / 2);
		ofLine(ofVec2f(0, 0), ofVec2f(ofGetWidth(), 0));
	}

	ofPopMatrix();

	if (ofGetMousePressed()) {
		float mouseX = ofGetMouseX() - ofGetWidth() / 2;
		float mouseY = ofGetMouseY() - ofGetHeight() / 2;

		this->logs.push_back(ofVec2f(mouseX, mouseY));
	} 

	ofSetLineWidth(3);
	ofColor c;
	for (int a = 0; a < 360; a += angle_step) {
		ofRotate(angle_step);
		for (int i = logs.size() - 1; i > 1; i--) {
			c.setHsb((ofGetFrameNum() * 2 + i) % 255, 255, 255);
			ofSetColor(c);

			ofLine(ofVec3f(logs[i].x, logs[i].y, 0), ofVec3f(logs[i-1].x, logs[i-1].y, 0));
			ofLine(ofVec3f(-logs[i].x, logs[i].y, 0), ofVec3f(-logs[i - 1].x, logs[i - 1].y, 0));
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'c') {
		ofBackground(0);
		this->logs.clear();
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
