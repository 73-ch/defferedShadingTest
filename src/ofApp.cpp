#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // gl&oF setup
    ofSetVerticalSync(false);
    
    // shader
    shader.load("default_vert.glsl", "default_frag.glsl");
    
    //model
    loader.setScale(2.0,2.0,2.0);
    loader.loadModel("train_shadow.stl");
    
    mesh = loader.getMesh(0);
    
    // osc
    receiver.setup(PORT);
}

//--------------------------------------------------------------
void ofApp::update(){
    // osc
    while (receiver.hasWaitingMessages()) {
        ofxOscMessage m;
        receiver.getNextMessage(m);
        if (m.getAddress() == "/") {
            cout << m.getArgAsString(0);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    shader.begin();
    cam.begin();
    mesh.draw();
    cam.end();
    shader.end();
    
    
    // fps
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 5, 10);
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
