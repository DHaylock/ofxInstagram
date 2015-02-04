/*
 *  ofxInstagram
 *
 *  David Haylock 2015
 */

#include "ofMain.h"
#include "ofxJSON.h"
#define URL "https://api.instagram.com/v1/"

class ofxInstagram {
    
    public:
        void setup(string auth_token, string clientID);
        void setAuthToken(string auth_token);
        // Get Functions
    
        // USERS
        // Get User Info
        void getUserInformation(string who);
        // Get User Feed use count to limit number of returns
        void getUserFeed(int count = 20);
        deque <string> parseJSONElement(string element);
        // GET/users/user-id/media/recentGet the most recent media published by a user. May return a mix of both image and video types.
        // GET/users/user-id/media/recentThe functionality is the same with the previous one, but use client_id instead of access_token
        // GET/users/self/media/likedSee the authenticated user's list of liked media.
        // GET/users/search
    
    
        void urlResponse(ofHttpResponse & response);
        string getJSONString();
    
    private:
        ofxJSONElement json;
        ofHttpResponse response;
        string _auth_token;
        string _clientID;
        string _responseData;
};