# All variables and this file are optional, if they are not present the PG and the
# makefiles will try to parse the correct values from the file system.
#
# Variables that specify exclusions can use % as a wildcard to specify that anything in
# that position will match. A partial path can also be specified to, for example, exclude
# a whole folder from the parsed paths from the file system
#
# Variables can be specified using = or +=
# = will clear the contents of that variable both specified from the file or the ones parsed
# from the file system
# += will add the values to the previous ones in the file or the ones parsed from the file 
# system
# 
# The PG can be used to detect errors in this file, just create a new project with this addon 
# and the PG will write to the console the kind of error and in which line it is

meta:
	ADDON_NAME = ofxInstagram
	ADDON_DESCRIPTION = Instagram access
	ADDON_AUTHOR = David Haylock
	ADDON_TAGS = "instagram, access"
	ADDON_URL = https://github.com/DHaylock/ofxInstagram

common:
	# dependencies with other addons, a list of them separated by spaces 
	# or use += in several lines
	# ADDON_DEPENDENCIES =
	
	OFXINSTAGRAM_ROOT = $(OF_ROOT)/addons/ofxInstagram
	
	# include search paths, this will be usually parsed from the file system
	# but if the addon or addon libraries need special search paths they can be
	# specified here separated by spaces or one per line using +=
	ADDON_INCLUDES = $(OFXINSTAGRAM_ROOT)/src $(OFXINSTAGRAM_ROOT)/libs/libcurl/include 
		
	# any special flag that should be passed to the compiler when using this
	# addon
	ADDON_CFLAGS = -I$(OFXINSTAGRAM_ROOT)/src -I$(OFXINSTAGRAM_ROOT)/libs/libcurl/include -lcurl

	# any special flag that should be passed to the linker when using this
	# addon, also used for system libraries with -lname
	
	LIBCURL_LIBS = $(OFXOMXPLAYER_ROOT)/libs/libcurl/lib
	ADDON_LDFLAGS=-L$(LIBCURL_LIBS) -libcurl
