#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    instagram.setup("6305138.3bfb194.22fde2570a4e483f932eca948d7bf1e5","self");
    instagram.setCertFileLocation(ofToDataPath("ca-bundle.crt",false));
    
//    ofSetDataPathRoot("../Resources/data/");
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
    if(key == 's')
    {
        
        Json::Reader reader;
        string raw = instagram.getParsedJSONString();
        ofFile file;
        
        file.open("test.json",ofFile::WriteOnly);
        Json::StyledWriter writer;
            file << writer.write(raw) << endl;
       
        
        ofLogVerbose("ofxJSONElement::save") << "JSON saved to " << file.getAbsolutePath() << ".";
        
        file.close();
    }
    
    if(key == 'i')
    {
        
        instagram.likeMedia("912501421079932553_6305138");
    }
    if(key == 'd')
    {
        instagram.unlikeMedia("912501421079932553_6305138");
    }
    if (key == 'c')
    {
        instagram.postCommentOnMedia("912501421079932553_6305138", "test Comments");
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
    instagram.mouseClicked(ofVec2f(x,y));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    instagram.mouseReleased(ofVec2f(x,y));
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
