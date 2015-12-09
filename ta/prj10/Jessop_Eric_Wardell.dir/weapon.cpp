/*************************
 * File: weapon.cpp
 ************************/

#include "weapon.h"
#include "rifle.h"
#include <iostream>
using namespace std; 

// shoot rifle
void Rifle :: shoot()
{
}

// aim rifle up and down
void Rifle :: addAngle(int angle)
{
   int newAngle = getAngle() + angle;
      
   if(newAngle < 0)
      setAngle(0);
   else if(newAngle > 90)
      setAngle(90);
   else
       setAngle(newAngle);
}

// rifle draw method
void Rifle :: draw() const
{
   drawRect(position, 20, 10, angle);
}
