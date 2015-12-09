/***********************************************************************
 * Header File:
 *    Bird: A flying object to be shot
 * Author:
 *    David Brewerton
 * Summary:
 *    Flies until shot
 ************************************************************************/

#include "standardBird.h"
#include "uiDraw.h"
#include "bird.h"
#include "point.h"
#include "velocity.h"
#include <iostream>

void StandardBird :: draw()
{
   drawCircle(getPoint(), getRadius());
}