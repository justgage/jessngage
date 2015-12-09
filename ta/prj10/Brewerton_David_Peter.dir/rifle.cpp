/***********************************************************************
 * Header File:
 *    Rifle: My gun to shoot things with
 * Author:
 *    David Brewerton
 * Summary:
 *    Defines the gun
 ************************************************************************/
 
#include "rifle.h"
#include "point.h"
#include <iostream>
#include "velocity.h"
#include "uiDraw.h"

void Rifle :: draw()
{
   drawRect(getPoint(), getWidth(), getHeight(), getAngle());
}

void Rifle :: rotateUp()
{
   if (angle == 90)
   {
      angle -= 5;
   }
   if (angle > 0 && angle < 90)
   {
      angle -= 5;
   }
}

void Rifle :: rotateDown()
{
   if (angle == 0)
   {
      angle += 5;
   }
   if (angle > 0 && angle < 90)
   {
      angle += 5;
   }
}