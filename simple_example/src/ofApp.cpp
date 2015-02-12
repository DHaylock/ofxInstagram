#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    instagram.setup("YOUR-ACCESS-TOKEN","self");
    instagram.setCertFileLocation(ofToDataPath("ca-bundle.crt",false));
}
//--------------------------------------------------------------
void ofApp::update()
{

}
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(255, 255, 255);
    instagram.drawJSON(10);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch (key) {
        case 'i':
            instagram.getUserInformation("self");
            break;
        case 'p':
            instagram.getPopularMedia();
            break;
        case 's':
            instagram.getUserRecentMedia("self");
            break;
        case 'l':
            instagram.getUserLikedMedia();
            break;
        case 'f':
            instagram.getUserFeed();
            break;
        default:
            break;
    }
}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    // Gives the ability to scroll through the JSON
    instagram.mouseClicked(ofVec2f(x,y));
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    // Gives the ability to scroll through the JSON
    instagram.mouseReleased(ofVec2f(x,y));
}
