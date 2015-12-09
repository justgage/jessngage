#include "rifle.h"
#include "point.h"
#include "uiDraw.h"

//Gets location of rifle and returns it *Future use*
Point Rifle :: getLocation()
{
   Point located;
   located.setX(200);
   located.setY(-200);
   return located;
}

//Draws the rifle
void Rifle :: draw()
{
   drawRect(getLocation(),8, 35, angle);
}

//changes the angle by input and only allows 0-90 rotation
void Rifle :: changeAngle(int input)
{
   
   if (angle <= 0 && input < 0)
   {
      angle = 0;
   }
   else if (angle >= 90 && input > 0)
   {
      angle = 90;
   }
   else if (angle <= 90 && angle >= 0)
   {
      angle = angle + input;
   }
   
}
