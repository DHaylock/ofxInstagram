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
        // Setup Tokens Etc...
        void setup(string auth_token, string clientID);
        void setAuthToken(string auth_token);

        //--------------------------- ENDPOINTS ----------------------\\
        //--------------------------------------------------------------
        // *
        // *                        USER ENDPOINTS
        // GET User Info
        void getUserInformation(string who);
    
        // GET User Feed use count to limit number of returns
        void getUserFeed(int count = 20,string minID = "",string maxID = "");
    
        // GET User recent images from user pass the who as the user ID number
        void getUserRecentMedia(string who = "self",int count = 20,string max_timestamp = "",string min_timestamp= "",string minID = "",string maxID = "");
    
        // GET User Liked Media
        void getUserLikedMedia(int count = 20,string maxLikeID = "");
    
        // GET User Search for users
        void getSearchUsers(string query = "",int count = 20);
    
        //--------------------------------------------------------------
        // *
        // *                        RELATIONSHIP ENDPOINTS
        // GET User Follows
        void getWhoUserFollows(string who = "self");
    
        // GET User Followed By
        void getWhoUserIsFollowedBy(string who = "self");
    
        // GET User Requested-by
        void getWhoHasRequestedToFollow(string who = "self");

        // GET User Relationship
        void getRelationshipToUser(string who = "self");

        // POST User Modify Relationship
        void changeRelationshipToUser(string who = "self",string action = "");

        //--------------------------------------------------------------
        // *
        // *                        MEDIA ENDPOINTS
        // GET Info about Media Object
        void getMediaInformation(string mediaID);
    
        // GET Info about Media using Shortcode
        void getMediaInfoUsingShortcode(string shortcode = "");
    
        // GET Media Search
        void searchMedia(string lat = "",string lng = "",string min_timestamp = "",string max_timestamp = "",int distance = 1000);
    
        // GET Popular Media
        void getPopularMedia();
    
        //--------------------------------------------------------------
        // *
        // *                        COMMENTS ENDPOINTS
        // GET Comments on Media Object
        void getCommentsForMedia(string mediaID);
    
        // POST Comment on Media Object
        void postCommentOnMedia(string mediaID,string comment);
    
        // DELETE Comment on Media Object
        void deleteCommentOnMedia(string mediaID);
    
        //--------------------------------------------------------------
        // *
        // *                        LIKE ENDPOINTS
        // GET List of Users who have Liked a Media Object
        void getListOfUsersWhoLikedMedia(string mediaID);
        
        // POST Like a Media Object
        void likeMedia(string mediaID);
        
        // DELETE Comment on Media Object
        void unlikeMedia(string mediaID);
    
        //--------------------------------------------------------------
        // *
        // *                        TAG ENDPOINTS
    
    
    
    
        deque <string> parseJSONElement(string element);
        string getJSONString();
    
    private:
        ofxJSONElement json;
        ofHttpResponse response;
        string _auth_token;
        string _clientID;
        string _responseData;
};