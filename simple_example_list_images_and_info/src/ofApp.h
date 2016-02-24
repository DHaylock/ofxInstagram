#pragma once

#include "ofMain.h"
#include "ofxThreadedImageLoader.h"
#include "ofxInstagram.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        void exit();
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
        void mouseScrolled(int x, int y, float scrollX, float scrollY);

        ofxInstagram instagram;
        ofxThreadedImageLoader getImages;
        deque<ofImage> images;
    
        ofVec2f scrollAmount;
        int scrollValue;
};
