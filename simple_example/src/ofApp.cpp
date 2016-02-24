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
    ofBackground(0);
    instagram.drawJSON(10);
    
    stringstream info;
    info << "Press 'f' to Find User Feed" << endl;
    info << "Press 's' to Get Recent Media" << endl;
    info << "Press 'l' to Get Liked Media" << endl;
    info << "Press 'p' to Get Popular Media" << endl;
    ofDrawBitmapStringHighlight(info.str(), 5,ofGetHeight()-50);
    
    if (profilePic.isAllocated()) {
        profilePic.draw(0,0);
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch (key) {
        case 'i':
            instagram.getUserInformation("self");
            profilePic.clear();
            profilePic.allocate(320, 320, OF_IMAGE_COLOR);
            profilePic.load(instagram.getJSON()["data"]["profile_picture"].asString());
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

}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY )
{
    instagram.mouseScroll(scrollY);
}