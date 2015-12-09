#ifndef RIFLE_H
#define RIFLE_H

#include "bullet.h"
#include "uiDraw.h"
#include <cmath>



class Rifle
{
  private:
   Point p;
   int angle;
 
   

  public:
   Rifle()
   {
      p = Point(200,-200);
      angle = 135;
   }
   
   void draw();
   Bullet* shoot();
   void left();
   void right();
   

   
};


#endif
