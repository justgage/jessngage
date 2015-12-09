/************************************
 * Velocity Class
 ***********************************/

#ifndef VELOCITY_H
#define VELOCITY_H

#include <cmath>

class Velocity
{
  private:
   float dx;
   float dy;
   
  public:
   Velocity()
   {
      dx = 0;
      dy = 0;
   }
   
   float getDx() {return dx;}
   float getDy() {return dy;}
   void setDx(float newDx) {dx = newDx;}
   void setDy(float newDy) {dy = newDy;}

   void addX(float addedSpeed) {dx += addedSpeed;}
   void addY(float addedSpeed) {dy += addedSpeed;}

   /*####################################################
   #  Given a magnitude and angle in degrees this function
   #  changes the velocity to equatable cartesian values.
   #  Shots are inverted in the y direction when compared
   #  with the rifle. Why this is I do not know but fixing
   #  the problem is simple math.
   ####################################################*/
   void angleToMovement (float magnitude, float degrees)
   {
      //Solve inversion problem.
      if(degrees > 45)
      {
         degrees = degrees - 2*(degrees - 45);
      }
      else if(degrees < 45)
      {
         degrees = degrees + 2*(45 - degrees);
      }

      //Set velocity based on magnitude and direction
      float radians = degrees * 3.14159265359 / 180.0;
      float newDx = -(magnitude * cos(radians));
      float newDy = (magnitude * sin(radians));
      setDx(newDx);
      setDy(newDy);
   }

   
};
#endif
