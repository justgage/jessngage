//
//  bird.cpp
//  skeet
//
//  Created by Brennan Harris on 11/14/15.
//  Copyright © 2015 Brennan Harris. All rights reserved.
//

#include "bird.h"

Point Bird :: randomStartPoint()
{
    int y = rand() % 400 - 200;
    Point point = Point(-200,y);
    return point;
}

Velocity Bird :: randomResponsiveVelocity(Point point)
{
    int dx;
    int dy;
    dx = rand() % 3 + 3;
    if (point.getY() > 0)
    {
        dy = rand() % 5 - 6;
    }
    else
    {
        dy = rand() % 5 + 1;
    }
    Velocity velocity = Velocity(dx,dy);
    return velocity;
}

Velocity Bird :: randomToughVelocity(Point point)
{
    int dx;
    int dy;
    dx = rand() % 4 + 3;
    if (point.getY() > 0)
    {
        dy = rand() % 5 - 4;
    }
    else
    {
        dy = rand() % 5;
    }
    Velocity velocity = Velocity(dx,dy);
    return velocity;
}

StandardBird :: StandardBird()
{
    Point point = randomStartPoint();
    setLocation(point);
    setVelocity(randomResponsiveVelocity(point));
    setLife(true);
    setRadius(20.0);
}

void StandardBird :: draw()
{
    drawCircle(getLocation(),(int)getRadius());
}

int StandardBird :: collide()
{
    setLife(false);
    return 1;
}

StrongBird :: StrongBird()
{
    Point point = randomStartPoint();
    setLocation(point);
    setVelocity(randomToughVelocity(point));
    setLife(true);
    setHits(3);
    setRadius(20.0);
}

void StrongBird :: draw()
{
    drawToughBird(getLocation(),(int)getRadius(),getHits());
}

int StrongBird :: collide()
{
    int hits = getHits();
    setHits(hits - 1);
    if (getHits() > 0)
    {
        return 1;
    }
    else
    {
        setLife(false);
        return 3;
    }
}

SacredBird :: SacredBird()
{
    Point point = randomStartPoint();
    setLocation(point);
    setVelocity(randomResponsiveVelocity(point));
    setLife(true);
    setRadius(20.0);
}

void SacredBird :: draw()
{
    drawSacredBird(getLocation(),(int)getRadius());
}

int SacredBird :: collide()
{
    setLife(false);
    return -10;
}