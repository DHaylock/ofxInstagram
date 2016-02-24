#pragma once

#include "ofMain.h"
#include "ofxInstagram.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
        void mouseScrolled(int x, int y,float scrollX,float scrollY);
		
        ofxInstagram instagram;
        ofImage profilePic;
};
