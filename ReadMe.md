#ofxInstagram
---
A openFrameworks addon for Instagram API.

ofxInstagram is an addon for openFrameworks (v0.8.0+) that allows users to utilise the Instagram API in C++. The addon lets you pull data from instagram such as image links, like and comments. Aswell as posting comments, liking and finding

If you would like to contribute to the addon feel free to fork, hack and mod the code.
Also drop me a line and let me know how you end up using the addon.

@david_haylock

### Requirements

- openFrameworks v0.8.0+

### What the addon includes

- libcurl library
- jsoncpp library
- Example Applications

### Getting Started
Here are a couple of helper guides to get started with ofxInstagram.

#### Instagram API
To start using the API, you need to get an access_token, which grants you access to the API elements. If you go to [http://instagram.com/developer/authentication/](http://instagram.com/developer/authentication/) you can see how Instagram authorises your app. We'll be simplifying this process slightly.

- First grab yourself an Instagram account.
- Then sign in to [http://instagram.com/developer/](http://instagram.com/developer/)
- Go to **Manage Clients** and **Register a New Client**
- Choose an Name for your Client and fill in the description.
- In the oAuth uri and Website URL, type `http://127.0.0.1`.
- **Uncheck** the Implicit OAuth check box, then **Save**.
- This should generate some keys for you.
- Now in your web browser, goto `https://instagram.com/oauth/authorize/?client_id=CLIENT-ID&redirect_uri=127.0.0.1&response_type=token&scope=likes+comments` changing out the CLIENT ID for your own. This sets the permissions of your API Calls, so you can like and comment on images.
- This will bring up a window asking you give access to the Application, click **Authorize**.
- Then the Window should go white, look at the url bar you should now have something like `http://127.0.0.1#access_token=SOMETHING`
- Copy that access_token and put it some where safe.