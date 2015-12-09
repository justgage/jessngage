/***********************************************************************
 * Source File:
 *    Velocity: How fast the lander is moving and in what direction
 * Author:
 *    Taylor Groom
 * Summary:
 *    Keeps track of how many pixels the ship should move in the x and y
 *    directions everytime the game iterates. Has getters/setters  
 ************************************************************************/

#include "velocity.h"
#include <cassert>

/*******************************************************************
 * set dx: sets the value of dx to the value of the passed parameter
 *******************************************************************/
void Velocity::setDx(float newDx)
{
   dx = newDx;
}

/*******************************************************************
 * set dy: sets the value of dy to the value of the passed parameter
 *******************************************************************/
void Velocity::setDy(float newDy)
{
   dy = newDy;
}

/*******************************************************************
 * takes two floats, a change in the x and change in the y velocity
 * and adds them to the current velocity
 *******************************************************************/
void Velocity::add(float addX, float addY)
{
   setDx(dx + addX);
   setDy(dy + addY);
}


