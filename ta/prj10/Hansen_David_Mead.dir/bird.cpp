// fly class

#include "bird.h"
#include "uiDraw.h"
#include "point.h"
#include "bullet.h"

void NormalBird::draw()
{
   drawCircle(middle, radius);
}

void ToughBird::draw()
{
   drawToughBird(middle, radius, hits);
}

void SacredBird::draw()
{
   drawSacredBird(middle, radius);
}

int Bird::getType()
{
   return random(1,4);
}

void Bird::move()
{
   moveMiddleX(random(3,6));

   if(start.getY() > 0)
   {
      if(start.getY() > 50)
      {
         moveMiddleY(0);
      }
      else if(start.getY() > 100)
      {
         moveMiddleY(-1);
      }
      else
      {
         moveMiddleY(random(-2,-1));
      }
   }
   else
   {
      moveMiddleY(random(1,4));
   }
}

void ToughBird::move()
{
   moveMiddleX(random(2,4));

   if(start.getY() > 0)
   {
      if(start.getY() > 50)
      {
         moveMiddleY(0);
      }
      else if(start.getY() > 100)
      {
         moveMiddleY(-1);
      }
      else
      {
         moveMiddleY(random(-2,-1));
      }
   }
   else
   {
      moveMiddleY(random(1,3));
   }
}

void Bird::moveMiddleX(float move)
{
   float x = middle.getX();
   middle.setX(x += move);
}

void Bird::moveMiddleY(float move)
{
   float y = middle.getY();
   middle.setY(y += move);
}

int NormalBird::hit(Bullet bullet)
{
   if((bullet.getMiddleX() - 10 <= middle.getX()
       <= bullet.getMiddleX() + 10) &&
      (bullet.getMiddleY() - 10 <= middle.getY()
       <= bullet.getMiddleY() + 10))
   {
      return 1;
   }
   else
      return 0;
}
int SacredBird::hit(Bullet bullet)
{
   if((bullet.getMiddleX() - 5 <= middle.getX()
       <= bullet.getMiddleX() + 5) &&
      (bullet.getMiddleY() - 5 <= middle.getY()
       <= bullet.getMiddleY() + 5))
   {
      return -10;
   }
   else
      return 0;
}

int ToughBird::hit(Bullet bullet)
{
   if((bullet.getMiddleX() - 6 <= middle.getX()
       <= bullet.getMiddleX() + 6) &&
      (bullet.getMiddleY() - 6 <= middle.getY()
       <= bullet.getMiddleY() + 6))
   {
      if(hits == 1)
      {
         return 3;
      }
      else
      {
         hits--;
         return 1;
      }
   }
   else
      return 0;
}
