#include "ofxInstagram.h"

//--------------------------------------------------------------
void ofxInstagram::setup(string auth_token, string clientID)
{
    // Set the Tokens
    _auth_token = auth_token;
    _clientID = clientID;
}
#pragma mark - User Endpoints
//--------------------------------------------------------------
// *
// *                        USER ENDPOINTS
// *  GET Info
// *  GET User Feed
// *  GET User Recent Media
// *  GET User Like Media
// *  GET User Search Users
// *
//--------------------------------------------------------------
void ofxInstagram::getUserInformation(string who)
{
    stringstream url;
    url << "https://api.instagram.com/v1/users/" << who << "/?access_token=" << _auth_token;
    
    cout << "This is your request: " << url.str()  <<endl;
    response = ofLoadURL(url.str());
}
//--------------------------------------------------------------
void ofxInstagram::getUserFeed(int count,string minID,string maxID)
{
    stringstream url;
    url << "https://api.instagram.com/v1/users/self/feed?access_token=" << _auth_token << "&count="<< ofToString(count);

    if (minID.length() != 0) {
        url << "&minID=" << minID;
    }
    
    if (maxID.length() != 0) {
        url << "&maxID=" << maxID;
    }

    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
}
//--------------------------------------------------------------
void ofxInstagram::getUserRecentMedia(string who,int count,string max_timestamp,string min_timestamp,string minID,string maxID)
{
    stringstream url;
    url << "https://api.instagram.com/v1/users/" << who << "/media/recent?access_token=" << _auth_token << "&count="<< ofToString(count);
    
    if (minID.length() != 0) {
        url << "&minID=" << minID;
    }
    
    if (maxID.length() != 0) {
        url << "&maxID=" << maxID;
    }
    
    if (min_timestamp.length() != 0) {
        url << "&min_timestamp=" << min_timestamp;
    }
    
    if (max_timestamp.length() != 0) {
        url << "&max_timestamp=" << max_timestamp;
    }
    
    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
}
//--------------------------------------------------------------
void ofxInstagram::getUserLikedMedia(int count,string maxLikeID)
{
    stringstream url;
    url << "https://api.instagram.com/v1/users/self/media/liked?access_token=" << _auth_token << "&count="<< ofToString(count);
    
    if (maxLikeID.length() != 0) {
        url << "&max_like_ID=" << maxLikeID;
    }
    
    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
}
//--------------------------------------------------------------
void ofxInstagram::getSearchUsers(string query,int count)
{
    stringstream url;
    url << "https://api.instagram.com/v1/users/search?access_token=" << _auth_token << "&count="<< ofToString(count);
    
    if (query.length() != 0) {
        url << "&q=" << query;
    }
    
    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    cout << response.data <<endl;
}
#pragma mark - Relationship Endpoints
//--------------------------------------------------------------
// *
// *                        MEDIA ENDPOINTS
// *  GET who User Follows
// *  GET who User is Followed By
// *  GET get who User has Requested to Follow
// *  GET relationship to User
// *  POST change Relationship to User
// *
//--------------------------------------------------------------
void ofxInstagram::getWhoUserFollows(string who)
{
    
}
//--------------------------------------------------------------
void ofxInstagram::getWhoUserIsFollowedBy(string who)
{
    
}
//--------------------------------------------------------------
void ofxInstagram::getWhoHasRequestedToFollow(string who)
{
    
}
//--------------------------------------------------------------
void ofxInstagram::getRelationshipToUser(string who)
{
    
}
//--------------------------------------------------------------
void ofxInstagram::changeRelationshipToUser(string who,string action)
{
    
}
#pragma mark - Media Endpoints
//--------------------------------------------------------------
// *
// *                        MEDIA ENDPOINTS
// *  GET Info about Media
// *  GET Info using Shortcode
// *  GET Search Media
// *  GET Popular Media
// *
//--------------------------------------------------------------
void ofxInstagram::getMediaInformation(string mediaID)
{
    
}
//--------------------------------------------------------------
void ofxInstagram::getMediaInfoUsingShortcode(string shortcode)
{
    
}
//--------------------------------------------------------------
void ofxInstagram::searchMedia(string lat, string lng,string min_timestamp,string max_timestamp,int distance)
{
    
}
//--------------------------------------------------------------
void ofxInstagram::getPopularMedia()
{
    
}
#pragma mark - Comments Endpoints
//--------------------------------------------------------------
// *
// *                        COMMENT ENDPOINTS
// *  GET Comments on Media Object
// *  POST Comment on Media Object
// *  DELETE Comment on Media Object
// *
//--------------------------------------------------------------
void ofxInstagram::getCommentsForMedia(string mediaID)
{
    
}
//--------------------------------------------------------------
void ofxInstagram::postCommentOnMedia(string mediaID, string comment)
{
    
}
//--------------------------------------------------------------
void ofxInstagram::deleteCommentOnMedia(string mediaID)
{
    
}
#pragma mark - Like Endpoints
//--------------------------------------------------------------
// *
// *                        LIKE ENDPOINTS
// *  GET List of Likes on Media Object
// *  POST Like Media
// *  POST unlike Media
// *
//--------------------------------------------------------------
void ofxInstagram::getListOfUsersWhoLikedMedia(string mediaID)
{
    
}
//--------------------------------------------------------------
void ofxInstagram::likeMedia(string mediaID)
{
    
}
//--------------------------------------------------------------
void ofxInstagram::unlikeMedia(string mediaID)
{
    
}
#pragma mark - Tag Endpoints
//--------------------------------------------------------------
// *
// *                        TAG ENDPOINTS
// *  GET Info about Tags
// *  GET List of Tagged Objects
// *  GET Search for Tag Objects
// *
//--------------------------------------------------------------
void ofxInstagram::getInfoForTags(string tagname)
{
    
}
//--------------------------------------------------------------
void ofxInstagram::getListOfTaggedObjects(string tagname, int count, string min_tagID,string max_tagID)
{
    
}
//--------------------------------------------------------------
void ofxInstagram::searchForTags(string query)
{
    
}
#pragma mark - Locations Endpoints
//--------------------------------------------------------------
// *
// *                        LOCATIONS ENDPOINTS
// *  GET Info about Locations
// *  GET Recent Media from Location
// *  GET Search for Locations by LAT,LNG
// *
//--------------------------------------------------------------
void ofxInstagram::getInfoAboutLocation(string location)
{
    
}
//--------------------------------------------------------------
void ofxInstagram::getRecentMediaFromLocation(string location, string min_timestamp,string max_timestamp,string minID,string maxID)
{
    
}
//--------------------------------------------------------------
void ofxInstagram::searchForLocations(string distance, string lat, string lng,string facebook_PlacesID,string foursquareID)
{
    
}
#pragma mark - Geography Endpoints
//--------------------------------------------------------------
// *
// *                      GEOGRAPHY ENDPOINTS
// *  GET Media from Custom GeoID
// *
//--------------------------------------------------------------
void ofxInstagram::getRecentMediaFromGeoID(string geoID,int count,string minID)
{
    
}
//--------------------------------------------------------------
string ofxInstagram::getJSONString() const
{
    return ofxJSONElement(response.data).toStyledString();
}
//--------------------------------------------------------------
deque <string> ofxInstagram::parseJSONElement(string element)
{
    deque<string>elements;
    for(unsigned int i = 0; i < json["data"].size(); ++i)
    {
        std::string title  = json["data"][i]["images"]["standard_resolution"]["url"].asString();
        cout << title << endl;
        elements.push_back(title);
    }
    return elements;
}
//--------------------------------------------------------------
deque <string> ofxInstagram::getImageURL()
{
    deque<string>elements;
    for(unsigned int i = 0; i < json["data"].size(); ++i)
    {
        std::string title  = json["data"][i]["images"]["standard_resolution"]["url"].asString();
        cout << title << endl;
        elements.push_back(title);
    }
    return elements;
}