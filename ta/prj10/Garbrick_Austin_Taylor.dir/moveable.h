#ifndef MOVEABLE_H
#define MOVEABLE_H

#include "point.h"
#include "velocity.h"

class Moveable
{
  protected:
   Point p;
   Velocity v;
  public:
   Point getPoint() const {return p;}
   void setPoint(Point p) {this-> p = p;}

   Velocity getVelocity() const {return v;}
   void setVelocity(Velocity v) {this-> v = v;}
   virtual void update()
   {
      p.setX(p.getX() + v.getDeltaX());
      p.setY(p.getY() + v.getDeltaY());
   };

   virtual void draw() = 0;
   
   
   

   
   
   
};

#endif
