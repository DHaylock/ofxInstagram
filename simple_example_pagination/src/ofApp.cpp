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
    for (int i = 0; i < paginationIds.size(); i++) {
        ofDrawBitmapStringHighlight(paginationIds[i], 5,10+(i*15));
    }
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
        case 't':
            if (paginationIds.empty()) {
                instagram.getListOfTaggedObjectsNormal("museums", 30);
                paginationIds.push_back(instagram.getMaxIdForPagination());
            }
            else{
                instagram.getListOfTaggedObjectsPagination("museums", 30,paginationIds.back());
                paginationIds.push_back(instagram.getMaxIdForPagination());
            }
            
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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY)
{
    instagram.mouseScroll(scrollY);
}
