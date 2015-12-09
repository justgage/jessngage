/***********************************************************************
 * Header File:
 *    Bullet: My projectile fired from the gun
 * Author:
 *    David Brewerton
 * Summary:
 *    Moves through the air into birds
 ************************************************************************/
 
#ifndef BULLET_H
#define BULLET_H

#include "point.h"
#include "velocity.h"
#include <iostream>

class Bullet
{
private:
   Point point;
   Velocity velocity;
public:
   Bullet()
   {
      point.setX(180);
      point.setY(-180);
      velocity;
   }
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
   void fire(Velocity v);
   void draw();
   void advance();
};

#endif