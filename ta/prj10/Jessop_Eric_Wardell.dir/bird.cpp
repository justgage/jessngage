/*************************
 * File: bird.cpp
 ************************/
 
#include "bird.h"
#include "uiDraw.h"

// Give birds a randon start position on left side
Point Bird :: getRanPosition() const
{
   return Point(-210, random(-200, 200));
}

// find a random angle between -35 and 35 degrees
int Bird :: getRanAngle() const
{
   if (position.getY() > 190)
      random(-35, 0);
   else if (position.getY() > 150)
      random(-35, 5);
   else if (position.getY() > 80)
      random(-35, 15);
   else if (position.getY() > 30)
      random(-25, 15);
   else if (position.getY() > -30)
      random(-15, 25);
   else if (position.getY() > -80)
      random(-15, 35);
   else if (position.getY() > -150)
      random(-10, 35);
   else
      random(0, 35);
}
