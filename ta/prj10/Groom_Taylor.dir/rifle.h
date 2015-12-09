/***********************************************************************
 * Header File:
 *    Rifle.h: The firearm portion of skeet
 * Author:
 *    Taylor Groom
 * Summary:
 *    Everything we need to know about a rifle, including its location
 *    and the angle it is pointed, 
 ************************************************************************/

#ifndef RIFLE_H
#define RIFLE_H
#include <iostream>
#include "point.h"

class Rifle
{
  private:
   Point base;
   int angle;   

  public:
//Default Coonstructor
   Rifle()
   {
      angle = 45;
   }
// Getters
   float getBaseX() {return base.getX();}
   float getBaseY() {return base.getY();}
   Point getBaseLocation();
   int getAngle() {return angle;}
// Memeberr variables   
   void setBaseX(float newX) {base.setX(newX);}
   void setBaseY(float newY) {base.setY(newY);}
   void changeAngle(int newAngle); 
   void draw();
};

#endif
