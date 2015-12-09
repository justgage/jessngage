/***********************************************************************
 * Header File:
 *    Velocity: A class of how fast things move
 * Author:
 *    David Brewerton
 * Summary:
 *    Defines physics in the game
 ************************************************************************/
 
#ifndef VELOCITY_H
#define VELOCITY_H

#include "point.h"

class Velocity
{
private:
   float dx;
   float dy;
public:
   Velocity()
   {
      dx = 0;
      dy = 0;
   }
   Velocity (float dx, float dy)
   {
      this->dx = dx;
      this->dy = dy;
   }
   float getDx()
   {
      return dx;
   }
   float getDy()
   {
      return dy;
   }
   void setDx(float dx)
   {
      this-> dx = dx;
   }
   void setDy(float dy)
   {
      this-> dy = dy;
   }
   void add(Velocity velocity);
};

#endif
