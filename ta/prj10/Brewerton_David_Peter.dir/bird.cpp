/***********************************************************************
 * Header File:
 *    Bird: A flying object to be shot
 * Author:
 *    David Brewerton
 * Summary:
 *    Flies until shot
 ************************************************************************/
 
#include "uiDraw.h"
#include "bird.h"
#include "point.h"
#include "velocity.h"
#include <iostream>

void Bird :: advance()
{
   point.addX(velocity.getDx());
   point.addY(velocity.getDy());
   draw();
}

int Bird :: add()
{
   return 1;
}