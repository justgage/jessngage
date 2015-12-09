//
//  rifle.cpp
//  skeet
//
//  Created by Brennan Harris on 11/5/15.
//  Copyright © 2015 Brennan Harris. All rights reserved.
//

#include "rifle.h"
Rifle :: Rifle()
{
    angle = 45;
    length = 100;
    height = 15;
    setLocation(Point(200,-200));
}

void Rifle :: rotateDown()
{
    if (angle > 0)
    {
        angle -= 3;
    }
}

void Rifle :: rotateUp()
{
    if (angle < 90)
    {
        angle += 3;
    }
    
}

void Rifle :: draw()
{
    drawRect(getLocation(),getHeight(),getLength(),getAngle());
}