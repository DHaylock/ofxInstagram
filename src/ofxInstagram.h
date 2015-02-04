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
        void getUserFeed(int count = 20,string minID = "",string maxID = "");
        // Get User recent images from user pass the who as the user ID number
        void getUserRecentMedia(string who = "self",int count = 20,string max_timestamp = "",string min_timestamp= "",string minID = "",string maxID = "");
        // Get User Liked Media
        void getUserLikedMedia(int count = 20,string maxLikeID = "");
        // Get User Search for users
        void getSearchUsers(string query = "",int count = 20);
    
    
        deque <string> parseJSONElement(string element);
    

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