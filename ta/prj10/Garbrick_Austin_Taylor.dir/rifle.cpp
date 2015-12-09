#include "rifle.h"
#include <cmath>

void Rifle :: draw()
{
   drawRect(p, 50, 10, angle);
   
}

Bullet* Rifle :: shoot()
{
   float deltaX = 10.0*cos(float(angle)* 3.1415926/180.0);
   float deltaY = 10.0*sin(float(angle)* 3.1415926/180.0);

   Point pTemp(200,-200);
   Velocity vTemp(deltaX, deltaY);

   return new Bullet(vTemp, pTemp);
   
   
}

void Rifle :: left()
{
   if (angle <= 177)
   {
   angle += 3;
   }
}

void Rifle :: right()
{
   if (angle >= 93)
   {
   angle -= 3;
   }
}



