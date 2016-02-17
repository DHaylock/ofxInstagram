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
	ADDON_DESCRIPTION = Instagram access for openFrameworks
	ADDON_AUTHOR = David Haylock and Krisjanis Rijnieks
	ADDON_TAGS = "instagram"
	ADDON_URL = https://github.com/DHaylock/ofxInstagram

common:
	linux64:
	# binary libraries, these will be usually parsed from the file system but some 
	# libraries need to passed to the linker in a specific order 
	ADDON_INCLUDES_EXCLUDE = libs/libcurl/include
	ADDON_PKG_CONFIG_LIBRARIES = libcurl
linux:
        # binary libraries, these will be usually parsed from the file system but some
        # libraries need to passed to the linker in a specific order
        ADDON_INCLUDES_EXCLUDE = libs/libcurl/include
        ADDON_PKG_CONFIG_LIBRARIES = libcurl
win_cb:
linuxarmv6l:
        # binary libraries, these will be usually parsed from the file system but some
        # libraries need to passed to the linker in a specific order
        ADDON_INCLUDES_EXCLUDE = libs/libcurl/include
        ADDON_PKG_CONFIG_LIBRARIES = libcurl
linuxarmv7l:
        # binary libraries, these will be usually parsed from the file system but some
        # libraries need to passed to the linker in a specific order
        ADDON_INCLUDES_EXCLUDE = libs/libcurl/include
        ADDON_PKG_CONFIG_LIBRARIES = libcurl
android/armeabi:	
android/armeabi-v7a: