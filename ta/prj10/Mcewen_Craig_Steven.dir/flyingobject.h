#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H
#include "point.h"
#include "velocity.h"

class FlyingObject
{
  protected:
   Point position;
   
   Velocity velocity;
   
  public:
   Point getPosition() const { return position; }
   void setPosition(Point newPoint) {position = newPoint;}

   virtual void advance();
   virtual void draw() const = 0;
   
   
};

#endif
