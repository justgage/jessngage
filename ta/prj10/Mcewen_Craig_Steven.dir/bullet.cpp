#include "bullet.h"
#include "uiDraw.h"
#include "rifle.h"
#include "flyingobject.h"
#include "bird.h"
#include <iostream>
#include <math.h>
#define PI 3.141592
using namespace std;

//Draws bullet if space is hit
void Bullet :: draw() const
{
   if (spaceHit == true)
   {
      drawDot(starting);
   }
}

//advances bullet at angle shot at
void Bullet :: advance()
{
  
   if(spaceHit)
   {
      starting.addX(-totalVelocity * sin(bulletAngle*PI/180));
      starting.addY(totalVelocity * cos(bulletAngle*PI/180));
   }
   if(starting.getX() < -200 || starting.getY() > 200)
   {
      spaceHit = false;
      shot = false;
   }
   shot = false;
}

//sends new bullet at angle
void Bullet :: drawNew(Rifle gameRifle)
{
   if (!shot)
   {
      bulletAngle = gameRifle.getAngle();
      shot = true;
   }
   spaceHit = true;
}

//See if its alive or hit by the bullet
void Bullet :: checkAlive(Point newPoint)
{
   if (starting.getX() < newPoint.getX()+20 &&
      starting.getX() > newPoint.getX()-20 &&
       starting.getY() < newPoint.getY()+20 &&
       starting.getY() > newPoint.getY()-20)
   {
      kill = true;
   }
}
