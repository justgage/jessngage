/***********************************************************************
 * Header File:
 *    Rifle: My gun to shoot things with
 * Author:
 *    David Brewerton
 * Summary:
 *    Defines the gun
 ************************************************************************/
 
#ifndef RIFLE_H
#define RIFLE_H

#include "point.h"
#include <iostream>
#include "velocity.h"

class Rifle
{
private:
   Point point;
   int angle;
   int height;
   int width;
public:
   Rifle()
   {
      point.setX(180);
      point.setY(-180);
      angle = 45;
      height = 40;
      width = 20;
   }
   int getAngle()
   {
      return angle;
   }
   void setAngle(int a)
   {
      angle = a;
   }
   int getHeight()
   {
      return height;
   }
   void setHeight(int h)
   {
      height = h;
   }
   int getWidth()
   {
      return width;
   }
   void setWidth(int w)
   {
      width = w;
   }
   void draw();
   Point getPoint()
   {
      return point;
   }
   void setPoint(Point p)
   {
      point = p;
   }
   void rotateUp();
   void rotateDown();
};

#endif