// bullet class

#include "bullet.h"
#include "uiDraw.h"
#include <cmath>

void Bullet::draw()
{
   drawDot(middle);
}

void Bullet::fire(int fireAngle)
{  
   speed.setDY(10* (cos(M_PI / 180.0 * (float)fireAngle)));
   speed.setDX(10*(-sin(M_PI / 180.0 * (float)fireAngle)));
}

void Bullet::applyVelocity()
{
   int x = middle.getX();
   int y = middle.getY();
   
   middle.setX(x += speed.getDX());
   middle.setY(y += speed.getDY());
}

void Bullet::reset()
{
      middle.setX(200);
      middle.setY(-200);
      speed.setDX(0);
      speed.setDY(0);      
}
