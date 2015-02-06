#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    instagram.setup("6305138.3bfb194.22fde2570a4e483f932eca948d7bf1e5","self");
    
}
//--------------------------------------------------------------
void ofApp::update()
{

}
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0, 0, 0);
    instagram.drawJSON();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if(key == 'i')
    {
        instagram.likeMedia("912501421079932553_6305138");
//        instagram.getUserInformation("self");
    }
    if(key == 'd')
    {
        instagram.unlikeMedia("912501421079932553_6305138");
        //        instagram.getUserInformation("self");
    }

    if (key == 'r')
    {
        instagram.getUserRecentMedia("self",20);
    }
    if(key == 'l')
    {
        instagram.getUserInformation("self");
    }
    if(key == 'm')
    {
        instagram.getMediaInformation("912501421079932553_6305138");
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
