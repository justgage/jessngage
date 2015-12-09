/***********************************************************************
 * Header File:
 *    Rifle.cpp: The firearm portion of skeet
 * Author:
 *    Taylor Groom
 * Summary:
 *    Everything we need to know about a rifle, including its location
 *    and the angle it is pointed,
 ************************************************************************/
#include "rifle.h"
#include "uiDraw.h"

#define RIFLE_LOCATION_X 200
#define RIFLE_LOCATION_Y -200

/*****************************************************************
 *      getBaseLocation - sets the rifle location to be the bottom
 *      right hand corner and returns this location.
 ****************************************************************/
Point Rifle :: getBaseLocation()
{
   Point rifleLocation;
   rifleLocation.setX(RIFLE_LOCATION_X);
   rifleLocation.setY(RIFLE_LOCATION_Y);
   return rifleLocation;
}

/*****************************************************************
 *      draw - draws the rifle at its current angle and at its
 *      current location
 *
 ****************************************************************/
void Rifle :: draw()
{
   drawRect(getBaseLocation(),8,40,angle);
}

/*****************************************************************
 *      changeAngle - takes a new anglefor the rifle, checks to
 *      make sure this angle is acceptable, and either sets the
 *      rifle to the new angle or to the closest acceptable angle.
 ****************************************************************/
void Rifle :: changeAngle(int newAngle)
{
   if(angle <= 0 && newAngle < 0)
   {
      angle = 0;
   }
   else if ( angle >= 90 && newAngle > 0)
   {
      angle = 90;
   }
   else if (angle <= 90 && angle >=0)
   {
      angle = angle + newAngle;
   }
}

