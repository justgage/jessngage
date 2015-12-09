/*************************
 * File: rifle.cpp
 ************************/

#include "rifle.h"
#include "bullet.h"
#include "flyingobject.h"
#include <cmath>
#include <iostream>
using namespace std;

// aim rifle down
void Rifle :: aimUp()
{    
   if ((angle - 3) < 90)
      setAngle(90);
   else
       setAngle(angle - 3);
}

// aim rifle up
void Rifle :: aimDown()
{    
   if ((angle + 3) > 180)
      setAngle(180);
   else
       setAngle(angle + 3);
}

// shoot rifle
void Rifle :: shoot(Bullet &bullet)
{
   bullet.angleToVelocity(angle);
}

// laser sight
void Rifle :: drawLaserSight() const
{
   Point endPoint = Point( (600*(cos(M_PI / 180 * getAngle())) + 200),
                           (600*(sin(M_PI / 180 * getAngle())) - 200) );
   drawLine(getPosition(), endPoint, 1.0, 0.0, 0.0);
}   
