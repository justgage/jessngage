//
//  rifle.hpp
//  skeet
//
//  Created by Brennan Harris on 11/5/15.
//  Copyright © 2015 Brennan Harris. All rights reserved.
//

#ifndef rifle_hpp
#define rifle_hpp

#include <stdio.h>
#include "point.h"
#include "uiDraw.h"

class Rifle
{
private:
    int length;
    int height;
    int angle;
    Point location;
public:
    Rifle();
    int getLength() { return length; }
    void setLength(int length) { this -> length = length; }
    int getHeight() { return height; }
    void setHeight(int height) { this -> height = height; }
    int getAngle() { return angle; }
    void setAngle(int angle) { this -> angle = angle; }
    Point getLocation() { return location; }
    void setLocation(Point location) { this -> location = location; }
    void rotateUp();
    void rotateDown();
    void draw();
};

#endif /* rifle_h */
