/*************************
 * File: flyingobject.h
 ************************/
#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class FlyingObject
{
protected:
   Point position;
   float speed;
   Velocity velocity;

   
public:
   FlyingObject()
   {
      
   }
   
   // getters
   Point getPosition() const { return position; }
   float getSpeed() const { return speed; }
   Velocity getVelocity() const { return velocity; }

   // setters
   void setPosition(Point position) { this->position = position; }
   void setSpeed(float speed) { this->speed = speed; }
   void setVelocity(Velocity velocity) { this->velocity = velocity; }

   // draw bullet method
   virtual void draw() const = 0;

   // check if object is on screen
   virtual bool isOnScreen() const;

   // change angles to velocity
   void angleToVelocity(int angle);

   // advance position of projectile
   virtual void advance();

   // check for collisions
   bool isHit(Point A, Point target) const;
};

#endif
