/***********************************************************************
 * Header File:
 *    flyingbject.cpp
 * Author:
 *    Taylor Groom
 * Summary:
 *    contains all of the attributes common to all flying objects, such as
 *    position, velocity, and advance and draw functions.
 ************************************************************************/
#include "flyingobject.h"

void FlyingObject :: advance()
{
      position.addX(velocity.getdx());
      position.addY(velocity.getdy());
}
