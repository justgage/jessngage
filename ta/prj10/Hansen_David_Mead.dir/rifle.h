// Rifle class

#ifndef RIFLE_H
#define RIFLE_H

#include "point.h"

class Rifle
{
  public:
   Point center;
   Point barrelTip;
   int width;
   int height;
   int rotation;

  Rifle() : width(10), height(100), rotation(45), center(200,-200) { }
   
   Point getCenter() { return center;}
   void setCenter(Point newCenter) { center = newCenter; }
   Point getBarrelTip() { return barrelTip;}
   void setBarrelTip(Point newTip) { barrelTip = newTip; }

   int getRotation() { return rotation;}
   void setRotation(int dr) { rotation += dr;}
   int getWidth() { return width; }
   int getHeight() { return height; }
   
   void moveRifle(int dr) { rotation += dr;}
   void draw();
};

#endif
