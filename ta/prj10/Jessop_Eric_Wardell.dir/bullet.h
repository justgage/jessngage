/*************************
 * File: bullet.h
 ************************/
#ifndef BULLET_H
#define BULLET_H

#include "flyingobject.h"
#include "uiDraw.h"

class Bullet : public FlyingObject
{
  private:
   int damage;
   
  public:
   Bullet()
   {
      setPosition(Point(200, -200));
      setSpeed(10.0);
      damage = -1;
   }

   // getters and setters
   int getDamage() const { return damage; }
   void setDamage(int damage) { this->damage = damage; }
   
   // draw bullet method
   void draw() const { drawDot(getPosition()); }
};

#endif
