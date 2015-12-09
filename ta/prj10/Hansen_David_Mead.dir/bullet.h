// Bullet class

#ifndef BULLET_H
#define BULLET_H

#include "point.h"
#include "velocity.h"

class Bullet
{
  public:
   Velocity speed;
   Point middle;

  Bullet() : middle(200,-200), speed(0,0) { }
   
   void fire(int fireAngle);
   void draw();

   Velocity getSpeed() {return speed;}
   void setSpeed(Velocity newSpeed) {speed = newSpeed;}

   Point getMiddle() {return middle;}
   void setMiddle(Point newMiddle) {middle = newMiddle;}

   int getMiddleX() {return middle.getX();}
   int getMiddleY() {return middle.getY();}

   void applyVelocity();
   void reset();
};

#endif
