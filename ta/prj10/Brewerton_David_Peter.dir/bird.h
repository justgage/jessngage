/***********************************************************************
 * Header File:
 *    Bird: A flying object to be shot
 * Author:
 *    David Brewerton
 * Summary:
 *    Flies until shot
 ************************************************************************/
 
#ifndef BIRD_H
#define BIRD_H

#include "point.h"
#include "velocity.h"
#include <iostream>

class Bird
{
private:
   Point point;
   Velocity velocity;
   int radius;
   int hits;
public:
   Bird()
   {
      point;
      velocity;
      setRadius(10);
      setHits(1);
   }
   Bird(Point point, Velocity velocity, int radius, int hits)
   {
      setPoint(point);
      setVelocity(velocity);
      setRadius(radius);
      setHits(hits);
   }
   ~Bird()
   {
   }
   void advance();
   virtual void draw() = 0;
   virtual int add();
   Point getPoint()
   {
      return point;
   }
   void setPoint(Point p)
   {
      point = p;
   }
   Velocity getVelocity()
   {
      return velocity;
   }
   void setVelocity(Velocity v)
   {
      velocity = v;
   }
   int getRadius()
   {
      return radius;
   }
   void setRadius(int radius)
   {
      this->radius = radius;
   }
   int getHits()
   {
      return hits;
   }
   void setHits(int hits)
   {
      this->hits = hits;
   }
};

#endif