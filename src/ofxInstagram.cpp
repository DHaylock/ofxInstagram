#include "ofxInstagram.h"

//--------------------------------------------------------------
void ofxInstagram::setup(string auth_token, string clientID)
{
    // Set the Tokens
    _auth_token = auth_token;
    _clientID = clientID;
}
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

//--------------------------------------------------------------
// *
// *                        RELATIONSHIP ENDPOINTS
// *  GET User Follows
// *  GET User Followed By
// *  GET User Requested-by
// *  GET User Relationship
// *  POST User Modify Relationship
// *
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