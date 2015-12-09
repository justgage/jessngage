//
//  flyingObject.hpp
//  skeet
//
//  Created by Brennan Harris on 11/6/15.
//  Copyright © 2015 Brennan Harris. All rights reserved.
//

#ifndef flyingObject_h
#define flyingObject_h

#include <stdio.h>
#include "uiDraw.h"
#include "point.h"
#include "velocity.h"

class FlyingObject
{
private:
    Point location;
    Velocity velocity;
    bool life;
public:
    Point getLocation() { return location; }
    Velocity getVelocity() { return velocity; }
    bool getLife() { return life; }
    
    void setLocation(Point location) { this->location = location; }
    void setVelocity(Velocity velocity) { this->velocity = velocity; }
    void setLife(bool life) { this->life = life; }
    
    void advance();
    
    virtual int collide()
    {
        setLife(false);
        return 0;
    }
};

#endif /* flyingObject_h */
