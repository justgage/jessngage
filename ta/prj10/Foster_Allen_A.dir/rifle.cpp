/***********************************************************************
* Source File:
*    Rifle : The details of the rifle
* Author:
*    Allen Foster
* Summary:
*    The  information we need for the rifle about how it moves and how 
*    other parts of it function alongside it.
************************************************************************/

#include "uiDraw.h"
#include "uiInteract.h"
#include "rifle.h"
#include "bullet.h"
#include "point.h"


void Rifle::draw()
{
  drawRect(0, 130, 25, 135);
}

void setPoint(point)
{
  point: x(0.0), y(-200.0);

}


void setAngle(angle)
{
   if (int i = 0; i < 180 || i > 90; i = angle)
      cout << drawRect(angle) << endl;
   else
      cout << drawRect(point) << endl;
}
