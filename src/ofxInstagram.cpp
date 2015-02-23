#include "ofxInstagram.h"
#include <unistd.h>
#pragma mark - Setup
//--------------------------------------------------------------
void ofxInstagram::setup(string auth_token, string clientID)
{
    scrollValue = 0;
    // Set the Tokens
    _auth_token = auth_token;
    _clientID = clientID;
}
//--------------------------------------------------------------
void ofxInstagram::setCertFileLocation(std::string path)
{
    _certPath = path;
    cout << _certPath << endl;
}
//--------------------------------------------------------------
void ofxInstagram::drawJSON(int x)
{
    ofPushMatrix();
    ofTranslate(x, scrollValue);
    ofDrawBitmapString(getParsedJSONString(), 0,0);
    ofPopMatrix();
}
#pragma mark - Scroll Stuff
//--------------------------------------------------------------
void ofxInstagram::mouseClicked(ofVec2f origin)
{
    clickOrigin = origin;
}
//--------------------------------------------------------------
void ofxInstagram::mouseReleased(ofVec2f origin)
{
    releasePos = origin;
    scrollAmount = clickOrigin - releasePos;
    scrollValue += scrollAmount.y;
}
//--------------------------------------------------------------
void ofxInstagram::resetScroll()
{
    scrollValue = 0;
}
//--------------------------------------------------------------
void ofxInstagram::saveJson(string filename)
{
    json.toStyledString();
    json.save(filename+".json");
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
    
    cout << "Getting Info about User: This is your request: " << url.str()  <<endl;
    response = ofLoadURL(url.str());
    json.parse(response.data);
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
    
    cout << "Getting Users Feed: This is your request: " << url.str()  <<endl;
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
    cout << response.data << endl;
    cout << "Getting " << who << "'s Feed: This is your request: " << url.str()  <<endl;
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
    json.parse(response.data);
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
    stringstream url;
    url << "https://api.instagram.com/v1/users/" << who << "/follows?access_token=" << _auth_token;

    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
}
//--------------------------------------------------------------
void ofxInstagram::getWhoUserIsFollowedBy(string who)
{
    stringstream url;
    url << "https://api.instagram.com/v1/users/" << who << "/followed-by?access_token=" << _auth_token;
    
    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
}
//--------------------------------------------------------------
void ofxInstagram::getWhoHasRequestedToFollow(string who)
{
    stringstream url;
    url << "https://api.instagram.com/v1/users/" << who << "/requested-by?access_token=" << _auth_token;
    
    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
}
//--------------------------------------------------------------
void ofxInstagram::getRelationshipToUser(string who)
{
    stringstream url;
    url << "https://api.instagram.com/v1/users/" << who << "/relationship?access_token=" << _auth_token;
    
    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
}
//--------------------------------------------------------------
void ofxInstagram::changeRelationshipToUser(string who,string action)
{
    //follow/unfollow/block/unblock/approve/ignore.
    // TO DO
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
    stringstream url;
    url << "https://api.instagram.com/v1/media/" << mediaID << "?access_token=" << _auth_token;
    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
}
//--------------------------------------------------------------
void ofxInstagram::getMediaInfoUsingShortcode(string shortcode)
{
    stringstream url;
    url << "https://api.instagram.com/v1/media/shortcode/" << shortcode << "?access_token=" << _auth_token;
    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
}
//--------------------------------------------------------------
void ofxInstagram::searchMedia(string lat, string lng,string min_timestamp,string max_timestamp,int distance)
{
    stringstream url;
    url << "https://api.instagram.com/v1/media/search?access_token=" << _auth_token;
    
    
    if (lat.length() != 0) {
        url << "&lat=" << lat;
    }
    
    if (lng.length() != 0) {
        url << "&lng=" << lng;
    }
    
    if (min_timestamp.length() != 0) {
        url << "&min_timestamp=" << min_timestamp;
    }
    
    if (max_timestamp.length() != 0) {
        url << "&max_timestamp=" << max_timestamp;
    }
    url << "&distance=" << distance;
    
    response = ofLoadURL(url.str());
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
}
//--------------------------------------------------------------
void ofxInstagram::getPopularMedia()
{
    stringstream url;
    url << "https://api.instagram.com/v1/media/popular?access_token=" << _auth_token;
    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
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
    stringstream url;
    url << "https://api.instagram.com/v1/media/" << mediaID << "/comments?access_token=" << _auth_token;
    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
}
//--------------------------------------------------------------
void ofxInstagram::postCommentOnMedia(string mediaID, string comment)
{
    CURL *curl;
    CURLcode res;
    stringstream url;
    url << "https://api.instagram.com/v1/media/" << mediaID << "/comments";
    
    string acc = "access_token="+_auth_token;
    static const char *token = acc.data();
    static const char *comments = comment.data();
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL,url.str().data());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, token);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(token));
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, comments);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(comments));
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_easy_setopt(curl, CURLOPT_POST,true);
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        
        /* always cleanup */
        curl_easy_cleanup(curl);
    }
}
//--------------------------------------------------------------
void ofxInstagram::deleteCommentOnMedia(string mediaID,string commentID)
{
    CURL *curl;
    CURLcode res;
    stringstream url;
    url << "https://api.instagram.com/v1/media/" << mediaID << "/comments/" << commentID << "?access_token="<<_auth_token;
    
    const char * file = _certPath.data();
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL,url.str().data());
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST , 1L);
        curl_easy_setopt(curl, CURLOPT_CAINFO, file);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST,"DELETE");
        
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        
        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        
        /* always cleanup */
        curl_easy_cleanup(curl);
    }
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
    stringstream url;
    url << "https://api.instagram.com/v1/media/" << mediaID << "/likes?access_token=" << _auth_token;
    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
}
//--------------------------------------------------------------
void ofxInstagram::likeMedia(string mediaID)
{
    CURL *curl;
    CURLcode res;
    stringstream url;
    url << "https://api.instagram.com/v1/media/" << mediaID << "/likes";
    
    string acc = "access_token="+_auth_token;
    static const char *token = acc.data();
    const char * file = _certPath.data();
    const char * chr;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL,url.str().data());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, token);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(token));
        /* SSL Options */
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER , 1L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST , 1L);
        /* Provide CA Certs from http://curl.haxx.se/docs/caextract.html */
        curl_easy_setopt(curl, CURLOPT_CAINFO, file);
        curl_easy_setopt(curl, CURLOPT_POST,true);
        
        /* Perform the request, ¤res will get the return code */
        res = curl_easy_perform(curl);
        
        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
}
//--------------------------------------------------------------
void ofxInstagram::unlikeMedia(string mediaID)
{
    CURL *curl;
    CURLcode res;
    stringstream url;
    url << "https://api.instagram.com/v1/media/" << mediaID << "/likes?access_token="<<_auth_token;
    
    const char * file = _certPath.data();
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL,url.str().data());
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST , 1L);
        curl_easy_setopt(curl, CURLOPT_CAINFO, file);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST,"DELETE");
        
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        
        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        
        /* always cleanup */
        curl_easy_cleanup(curl);
    }
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
    stringstream url;
    url << "https://api.instagram.com/v1/tags/" << tagname << "?access_token=" << _auth_token;
    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
}
//--------------------------------------------------------------
void ofxInstagram::getListOfTaggedObjects(string tagname, int count, string min_tagID,string max_tagID)
{
    stringstream url;
    url << "https://api.instagram.com/v1/tags/" << tagname << "/media/recent?access_token=" << _auth_token;
    
    if (min_tagID.length() != 0) {
        url << "&min_tag_id=" << min_tagID;
    }
    
    if (max_tagID.length() != 0) {
        url << "&max_tag_id=" << max_tagID;
    }
    
    url << "&count=" << count;
    
    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
}
//--------------------------------------------------------------
void ofxInstagram::searchForTags(string query)
{
    stringstream url;
    url << "https://api.instagram.com/v1/tags/search?q=" << query << "&access_token=" << _auth_token;
    
    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
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
    stringstream url;
    url << "https://api.instagram.com/v1/locations/" << location << "?access_token=" << _auth_token;
    
    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
}
//--------------------------------------------------------------
void ofxInstagram::getRecentMediaFromLocation(string location, string min_timestamp,string max_timestamp,string minID,string maxID)
{
    
    stringstream url;
    url << "https://api.instagram.com/v1/locations/" << location << "/media/recent?access_token=" << _auth_token;
    
    if (minID.length() != 0) {
        url << "&min_id=" << minID;
    }
    
    if (maxID.length() != 0) {
        url << "&max_id=" << maxID;
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
void ofxInstagram::searchForLocations(string distance, string lat, string lng,string facebook_PlacesID,string foursquareID)
{
    stringstream url;
    url << "https://api.instagram.com/v1/locations/search?";
    
    if (lat.length() != 0) {
        url << "&lat=" << lat;
    }
    
    if (lng.length() != 0) {
        url << "&lng=" << lng;
    }
    
    if (facebook_PlacesID.length() != 0) {
        url << "&facebook_places_id=" << facebook_PlacesID;
    }
    
    if (foursquareID.length() != 0) {
        url << "&foursquare_id=" << foursquareID;
    }
    
    url << "&distance=" << distance;
    url << "&access_token=" << _auth_token;
    response = ofLoadURL(url.str());
    
    cout << "This is your request: " << url.str()  <<endl;
    json.parse(response.data);
    
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
#pragma mark - Get Elements
//--------------------------------------------------------------
// *
// *                       Get Elements
// *
//--------------------------------------------------------------
//--------------------------------------------------------------
string ofxInstagram::getParsedJSONString() const
{
    if (response.data.size() == 0) {
        return "";
    }
    else{
        return ofxJSONElement(response.data).toStyledString();
    }
}
//--------------------------------------------------------------
string ofxInstagram::getPostMessage(string message)
{
    return message;
}
//--------------------------------------------------------------
string ofxInstagram::getRawJSONString() const
{
    if (response.data.size() == 0) {
        return "";
    }
    else{
        return response.data.getText();
    }
}
//--------------------------------------------------------------
deque <basicData> ofxInstagram::getBasicData()
{
    deque <basicData> data;
    data.resize(json["data"].size());
    
    for(unsigned int i = 0; i < json["data"].size(); ++i)
    {
        data[i].user = json["data"][i]["user"]["username"].asString();
        data[i].imageID = json["data"][i]["caption"]["id"].asString();
        data[i].imageURL = json["data"][i]["images"]["low_resolution"]["url"].asString();
        data[i].created_at = json["data"][i]["created_time"].asString();
        data[i].caption = json["data"][i]["caption"]["text"].asString();
    }
    return data;
}
//--------------------------------------------------------------
deque <string> ofxInstagram::getImageURL()
{
    deque<string>elements;
    for(unsigned int i = 0; i < json["data"].size(); ++i)
    {
        std::string title  = json["data"][i]["images"]["standard_resolution"]["url"].asString();
//        cout << title << endl;
        elements.push_back(title);
    }
    return elements;
}
//--------------------------------------------------------------
deque <string> ofxInstagram::getImageID()
{
    deque<string>elements;
    for(unsigned int i = 0; i < json["data"].size(); ++i)
    {
        std::string title  = json["data"][i]["caption"]["id"].asString();
        //        cout << title << endl;
        elements.push_back(title);
    }
    return elements;
}
