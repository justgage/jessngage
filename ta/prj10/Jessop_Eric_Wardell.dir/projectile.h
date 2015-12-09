/*************************
 * File: projectile.h
 ************************/
#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class Projectile
{
  private:
   Point position;
   float speed;
   Velocity velocity;
   int damage;	

  public:
   Projectile
   {
      position(200.0, -200.0);
      speed = 10;
      damage = 1;
   }

   // getter
   Point getPosition() const { return position; }

   // setter
   void setPosition(Point position) { this->position = position; }

   // change angles to velocity
   void angleToVelocity(int angle);

   // draw bullet method
   void draw() const { drawDot(getPosition)(); }

   // advance position of projectile
   void advance(int angle);

};

#endif
