//
//  bird.hpp
//  skeet
//
//  Created by Brennan Harris on 11/14/15.
//  Copyright © 2015 Brennan Harris. All rights reserved.
//

#ifndef bird_h
#define bird_h

#include <stdio.h>
#include <stdlib.h>
#include "flyingObject.h"

class Bird : public FlyingObject
{
private:
    float radius;
public:
    float getRadius() { return radius; }
    void setRadius(float radius) { this->radius = radius; }
    Point randomStartPoint();
    Velocity randomResponsiveVelocity(Point);
    Velocity randomToughVelocity(Point);
    virtual void draw() = 0;
};

class StandardBird : public Bird
{
public:
    StandardBird();
    void draw();
    int collide();
};

class StrongBird : public Bird
{
private:
    int hits;
public:
    StrongBird();
    int getHits() { return hits; }
    void setHits(int hits) { this->hits = hits; }
    void draw();
    int collide();
};

class SacredBird : public Bird
{
public:
    SacredBird();
    void draw();
    int collide();
};
#endif /* bird_h */
