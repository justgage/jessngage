/***********************************************************************
 * Header File:
 *    Bullet.h
 * Author:
 *    Craig McEwen
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/


#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include "velocity.h"
#include "rifle.h"
#include "point.h"
#include "flyingobject.h"

class Bullet : public FlyingObject
{
  private:
   float totalVelocity;
   Velocity bulletVelocity;
   int bulletAngle;
   Point starting;
   bool spaceHit;
   int bulletCount;
   bool shot;
   bool kill;
  public:
   Bullet()
   {
      totalVelocity = 10; //Bullet Velocity is 10 pix/s
      starting.setX(200); //start at the base
      starting.setY(-200); //start at the base
      spaceHit = false; //space is not hit
      shot = false; //not shot
      kill = false; //not killed
   }
   float getCurX() {return starting.getX();}
   float getCurY() {return starting.getY();}
   virtual void draw() const;
   void drawNew(Rifle gameRifle);
   virtual void advance();
   
   void checkAlive(Point newPoint);
   bool getKill() {return kill;}
   void setKill(bool newKill) {kill = newKill;}
};

#endif
