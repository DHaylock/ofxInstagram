#include "ofxInstagram.h"

//--------------------------------------------------------------
void ofxInstagram::setup(string auth_token, string clientID)
{
    // Set the Tokens
    _auth_token = auth_token;
    _clientID = clientID;

}
//--------------------------------------------------------------
void ofxInstagram::getUserInformation(string who)
{
    response = ofLoadURL("https://api.instagram.com/v1/users/"+who+"/?access_token="+_auth_token);
}
//--------------------------------------------------------------
void ofxInstagram::getUserFeed(int count)
{
    response = ofLoadURL("https://api.instagram.com/v1/users/self/feed?access_token="+_auth_token+"&count="+ofToString(count));
   
    json.parse(response.data);
}
//--------------------------------------------------------------
string ofxInstagram::getJSONString()
{
//    return json.toString(string);
    return response.data;
}
//--------------------------------------------------------------
deque <string> ofxInstagram::parseJSONElement(string element)
{
    deque<string>elements;
    for(unsigned int i = 0; i < json["data"].size(); ++i)
    {
        std::string title  = json["data"][i]["images"]["standard_resolution"]["url"].asString();
        cout << title << endl;
        elements.push_front(title);
    }
    return elements;
}