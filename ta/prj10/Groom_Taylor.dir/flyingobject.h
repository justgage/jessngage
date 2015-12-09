/***********************************************************************
 * Header File:
 *    flyingbject.h
 * Author:
 *    Taylor Groom
 * Summary:
 *    contains all of the attributes common to all flying objects, such as
 *    position, velocity, and advance and draw functions.
 ************************************************************************/
#ifndef FLYING_OBJECT_H
#define FLYING_OBJECT_H
#include "point.h"
#include "velocity.h"

class FlyingObject
{
  protected:
   Point position;

  public:

//Getters
   Point getPosition() const { return position; }
//Setters
   void setPosition(Point p) { position = p; }
//Member functions
   virtual void advance();
   virtual void draw() const = 0; //All other instances of draw need const too  
   Velocity velocity;
};

#endif
