/***********************************************************************
 * Header File:
 *    Velocity: How fast the ship is moving in the x and y directions
 * Author:
 *    Taylor Groom
 * Summary:
 *    Has getters and setters as well as an add function to work with
 *    the velocity of the ship in the x and y directions
 ************************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H
#include "velocity.h"
#include "point.h"
#include <iostream>

/*********************************************
 * Velocity
 * speed and direction
 *********************************************/
class Velocity
{
  private:
   float dx;
   float dy;

  public:
   
/*************************************************
 * Default Constructor sets the x and y velocities
 * to (0,0)
 ************************************************/
  Velocity()
  {
     dx = 3.0;
     dy = 0.0;
  }
  
/*************************************************
 * Non default constructor sets x and y velocities
 * to the parameters passed
 ************************************************/
  Velocity(float newDx, float newDy)
  {
     setDx(newDx);
     setDy(newDy);
  }
  
/**************************************************
 * Allow other fuctions to use the values contained
 * in private variables
 *************************************************/
  
  float getdx() const { return dx; }
  float getdy() const { return dy; }

/*************************************************
* Accepts a variable of the same type as the
* member variable the setter is to change and
* sets the member variable to that value.
**************************************************/
   void setDx(float newDx);
   void setDy(float newDy);

/*************************************************
 * takes two floats, a change in the x and change
 * in the y velocity and adds them to the current
 * velocity
 ************************************************/
void add(float addX, float addY);
      
};
#endif
