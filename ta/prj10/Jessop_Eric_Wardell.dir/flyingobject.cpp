/*************************
 * File: flyingobject.cpp
 ************************/

#include "flyingobject.h"
#include <cmath>

bool FlyingObject :: isOnScreen() const
{
   if (position.getX() < -220 || position.getX() > 220 ||
       position.getY() < -220 || position.getY() > 220)
      return false;
   else
      return true;
}

// angle to velocity method
void FlyingObject :: angleToVelocity(int angle)
{ 
   velocity.setDX(speed * (cos(M_PI / 180 * angle)));
   velocity.setDY(speed * (sin(M_PI / 180 * angle)));  
}

void FlyingObject :: advance()
{
   if (isOnScreen())
   {
      position.addX(velocity.getDX());
      position.addY(velocity.getDY());
   }
   //cerr << "Position: " << position.getX() << ", " << position.getY() << endl;
}

// check if objects collide
bool FlyingObject :: isHit(Point A, Point target) const
{
   if ((A.getX() >= target.getX() - 10 and A.getX() <= target.getX() + 10) and 
       (A.getY() >= target.getY() - 10 and A.getY() <= target.getY() + 10))
      return true;
   else
      return false;
}
