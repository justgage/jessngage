#ifndef FLYING_OBJECT_H
#define FLYING_OBJECT_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class FlyingObject
{
  protected:
   Point position;

  public:
   Point getPosition() const {return position;}
   void setPosition(Point p) {position =p;}

  virtual void advance();
  virtual void draw() const = 0;
};

#endif
