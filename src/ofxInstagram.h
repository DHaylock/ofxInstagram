/*
 *  ofxInstagram
 *
 *  David Haylock 2015
 */

#include "ofMain.h"
#include "ofxJSON.h"
#include <curl/curl.h>

struct basicData
{
    string imageID;
    string imageURL;
    string user;
    string created_at;
    string caption;
};

class ofxInstagram : public Json::Value {
    
    public:
        // Setup Tokens Etc...
        void setup(string auth_token, string clientID);
        void setCertFileLocation(std::string path);
    
        void draw();
        void drawJSON(int x);
    
        void resetScroll();
        void mouseScroll(int scrollY);
    
        void saveJson(string filename);
    
        ofxJSONElement getJSON() const;
        string getParsedJSONString() const;
        string getRawJSONString() const;
        string getErrorMessage();
        string getPostMessage(string message);
    
        string getMaxIdForPagination();
    
        bool isError();
    
        void parseData();
        //--------------------------------------------------------------
        // *
        // *                   Get Data from the JSON
        // *
        //--------------------------------------------------------------
        deque <string> getImageURL();
        deque <string> getImageID();
        deque <string> getImageCaption();
	
		deque <string> getVideoURL();
		deque <string> getProfilePicture();
    
        deque <basicData> getBasicData();
    
        //--------------------------- ENDPOINTS ----------------------\\
        //--------------------------------------------------------------
        // *
        // *                        USER ENDPOINTS
        // *
        //--------------------------------------------------------------
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
        // *
        //--------------------------------------------------------------
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
        // *
        //--------------------------------------------------------------
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
        // *
        //--------------------------------------------------------------
        // GET Comments on Media Object
        void getCommentsForMedia(string mediaID);
    
        // POST Comment on Media Object
        void postCommentOnMedia(string mediaID,string comment);
    
        // DELETE Comment on Media Object
        void deleteCommentOnMedia(string mediaID,string commentID);
    
        //--------------------------------------------------------------
        // *
        // *                        LIKE ENDPOINTS
        // *
        //--------------------------------------------------------------
        // GET List of Users who have Liked a Media Object
        void getListOfUsersWhoLikedMedia(string mediaID);
        
        // POST Like a Media Object
        void likeMedia(string mediaID);
        
        // DELETE Comment on Media Object
        void unlikeMedia(string mediaID);
    
        //--------------------------------------------------------------
        // *
        // *                        TAG ENDPOINTS
        // *
        //--------------------------------------------------------------
        // GET Info about tagged object
        void getInfoForTags(string tagname);
    
        // GET List of recently tagged objects
        void getListOfTaggedObjectsNormal(string tagname,int count,string min_tagID = "",string max_tagID = "");
        // GET List of recently tagged objects
        void getListOfTaggedObjectsPagination(string tagname,int count,string max_tagID = "");
        // GET Search Tags
        void searchForTags(string query);
    
        //--------------------------------------------------------------
        // *
        // *                        LOCATIONS ENDPOINTS
        // *
        //--------------------------------------------------------------
        // GET Info about a Location
        void getInfoAboutLocation(string location);
        
        // GET Recent Media from location
        void getRecentMediaFromLocation(string location,string min_timestamp = "",string max_timestamp = "",string minID = "",string maxID = "");
    
        // GET Find Location ID
        void searchForLocations(string distance,string lat,string lng, string facebook_PlacesID = "",string foursquareID = "");
    
        //--------------------------------------------------------------
        // *
        // *                        GEOGRAPHY ENDPOINTS
        // *
        //--------------------------------------------------------------
        // GET Recent Media from Custom GeoID
        void getRecentMediaFromGeoID(string geoID,int count = 20,string minID = "");
    
    private:
        ofxJSONElement json;
        ofHttpResponse response;

        string _auth_token;
        string _clientID;
        string _responseData;
        string _certPath;
        string _paginationID;
        void clearUrl();
    
        int scrollValue;
        ofVec2f scrollAmount;
        ofVec2f clickOrigin;
        ofVec2f releasePos;
};