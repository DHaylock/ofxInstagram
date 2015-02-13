//
//  ImageExtension.h
//  simple_example_savingJson
//
//  Created by David Haylock on 13/02/2015.
//
//

#include "ofMain.h"

class ofImageExtension : public ofImage
{
    public:
        //--------------------------------------------------------------
        void setImageID(string id)
        {
            _imageName = id;
        }
        //--------------------------------------------------------------
        void setImageOrigin(int x, int y, int w,int h)
        {
            _x = x;
            _y = y;
            _w = w;
            _h = h;
        }
        //--------------------------------------------------------------
        void isClicked(int x, int y)
        {
            if (((x >= _x)&&(x <= _x+_w))&&((y >= _y)&&( y <= _y+_h)))
            {
                ofImage::saveImage(_imageName+".jpg");
            }
        
        }
        //--------------------------------------------------------------
        void draw()
        {
            ofImage::draw(_x,_y,_w,_h);
        }
    protected:
        int _x;
        int _y;
        int _w;
        int _h;
        string _imageName;
};