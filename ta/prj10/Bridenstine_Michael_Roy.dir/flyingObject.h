#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include "velocity.h"
#include "point.h"

class flyingObject
{
  protected:
   Point position;
   Velocity speed;

  public:
   Point getPosition() {return position;}
   Velocity getVelocity() {return speed;}
   float getX() {return position.getX();}
   float getY() {return position.getY();}
   
   void setPosition(Point pos) { position = pos;}
   void setVelocity(float x, float y)
   {
      speed.setDx(x);
      speed.setDy(y);
   }
   void setAngledVelocity(float magnitude, float angle)
   {
      speed.angleToMovement(magnitude, angle);
   }

   void advance()
   {
      position.addX(speed.getDx());
      position.addY(speed.getDy());
   }
   
};
#endif
