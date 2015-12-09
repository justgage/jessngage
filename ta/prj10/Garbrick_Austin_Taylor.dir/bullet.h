#ifndef BULLET_H
#define BULLET_H

#include "uiDraw.h"
#include "velocity.h"
#include "point.h"
#include "moveable.h"

class Bullet : public Moveable 
{
 
  public:
   Bullet()
   {
      p = Point(50,-50);
      v = Velocity(0.0,0.0);
   }
   Bullet(Velocity velocity, Point p)
   {
      this-> v = velocity;
      this-> p = p;
   }

 
   virtual void draw();
  
   

   
   
   
};

#endif
