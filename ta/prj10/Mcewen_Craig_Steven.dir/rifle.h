/***********************************************************************
 * Header File:
 *    Rifle
 * Author:
 *    Craig McEwen
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/


#ifndef RIFLE_H
#define RIFLE_H

#include <iostream>
#include "point.h"

class Rifle
{
  private:
   Point base;
   Point muzzle;
   int angle;
   
  public:
   Rifle()
   {
      angle = 45;
   }
   //getters
   float getBaseX() const {return base.getX();}
   float getBaseY() const {return base.getY();}
   float getMuzzleX() const {return muzzle.getX();}
   float getMuzzleY() const {return muzzle.getY();}
   int getAngle() const {return angle;}
   //setters
   void setMuzzleX(float newX) {muzzle.setX(newX);}
   void setMuzzleY(float newY) {muzzle.setY(newY);}
   void setBaseX(float baseX) {base.setX(baseX);}
   void setBaseY(float baseY) {base.setY(baseY);}

   Point getLocation();
   void draw();
   void changeAngle(int input);
};

#endif
