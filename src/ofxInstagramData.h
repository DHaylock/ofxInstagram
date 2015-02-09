//
//  ofxInstagramData.h
//
//  Created by David Haylock on 06/02/2015.
//
//
#include "ofMain.h"

struct userfeed
{
    int howManyObjects;
    deque <string> mediaURL;
    deque <string> mediaID;
    deque <string> mediaCaption;
    deque <int> howManyLikes;
    deque <string> username;
    deque <string> userID;
};