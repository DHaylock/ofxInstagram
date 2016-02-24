#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::exit()
{
    getImages.stopThread();
}
//--------------------------------------------------------------
void ofApp::setup()
{
    instagram.setup("YOUR-ACCESS-TOKEN","self");
    instagram.setCertFileLocation(ofToDataPath("ca-bundle.crt",false));
    scrollValue = 0;
}
//--------------------------------------------------------------
void ofApp::update()
{

}
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    // Can scroll through images using mouse
    ofPushMatrix();
    ofTranslate(0,scrollValue);
    if (!images.empty()) {
        for (int i = 0; i < images.size(); i++) {
            if (images[i].isAllocated()) {
                images[i].draw(10, 10+(i*160), 150,150);
                ofDrawBitmapString("Username: "+instagram.getBasicData()[i].user, 170,20+(i*160));
                ofDrawBitmapString("Created At: "+instagram.getBasicData()[i].created_at, 170,35+(i*160));
                ofDrawBitmapString("Image Url: "+instagram.getBasicData()[i].imageURL, 170,50+(i*160));
                ofDrawBitmapString("Image ID: "+instagram.getBasicData()[i].imageID, 170,65+(i*160));
                ofDrawBitmapString("Caption: "+instagram.getBasicData()[i].caption, 170, 80+(i*160));
            }
        }
    }
    ofPopMatrix();
    
    stringstream info;
    info << "Press 'f' to Find User Data" << endl;
    info << "Press 'S' to Save the Data" << endl;
    info << "Press 'r' to Reset the Scroll" << endl;
    
    ofDrawBitmapStringHighlight(info.str(), 5,ofGetHeight()-50);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch (key) {
        case 'f':
            images.clear();
            images.resize(12);
            instagram.getUserFeed(12);
            if(!instagram.getBasicData().empty())
            {
                for(int i = 0; i < instagram.getBasicData().size(); i++)
                {
                    getImages.loadFromURL(images[i], instagram.getBasicData()[i].imageURL);
                }
            }
            break;
        case 'S':
            instagram.saveJson("myFile");
            break;
        case 'r':
            scrollValue = 0;
            break;
            
        default:
            break;
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

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
    scrollValue += scrollY*50;
}