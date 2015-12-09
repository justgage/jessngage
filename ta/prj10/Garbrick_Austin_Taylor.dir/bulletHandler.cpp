#include "bulletHandler.h"

BulletHandler :: BulletHandler()
{
   xMin = yMin = -200;
   xMax = yMax = 200;

   maxNumbBullets = 30; 
   
}

BulletHandler :: BulletHandler(int maxNumbBullets, Point tl, Point br)
{
   xMin = tl.getX();
   xMax = br.getX();
   yMin = tl.getX();
   yMax = br.getX();

   this-> maxNumbBullets = maxNumbBullets;
}

BulletHandler :: ~BulletHandler()
{
   for (vector<Bullet*> :: iterator it = bullets.begin(); it != bullets.end(); it++)
   {
      if (*it != NULL)
      {
         Bullet* temp = (*it);
         bullets.erase(it);
         it--;
         delete temp;
      }
   }
}

int BulletHandler :: updateBullets(Bird* bird)
{
   int score = 0;
   
   for (vector<Bullet*> :: iterator it = bullets.begin(); it != bullets.end(); it++)
   {
      (*it)-> update();

      if (bird == NULL)
      {
         continue;
      }

      float pX = (*it)->getPoint().getX();
      float pY = (*it)->getPoint().getY();

      Point pBird = bird->getPoint();
      float radius = bird->getRadius();

      Point hitboxTL(pBird.getX() - radius, pBird.getY() + radius);
      Point hitboxBR(pBird.getX() + radius, pBird.getY() - radius);

      if ((pX >= hitboxTL.getX() && pX <= hitboxBR.getX()) &&
          (pY >= hitboxBR.getY() && pY <= hitboxTL.getY()))
      {
         Bullet* temp = (*it);
         bullets.erase(it);
         it --;
         delete temp;

         score += bird->hurtBird();
      }
   }

   
   return score; 
}

void BulletHandler :: drawBullets()
{
  for (vector<Bullet*> :: iterator it = bullets.begin(); it != bullets.end(); it++)
   {
      (*it)-> draw();
   }
}

void BulletHandler :: removeExpiredBullets()
{
  for (vector<Bullet*> :: iterator it = bullets.begin(); it != bullets.end(); it++)
   {
      int x = (*it)->getPoint().getX();
      int y = (*it)->getPoint().getY();

      if (x < xMin || x > xMax || y < yMin || y > yMax)
      {
         Bullet* temp = (*it);
         bullets.erase(it);
         it--;
         delete temp;
      }
   }
   
}

void BulletHandler :: addBullets(Bullet *b)
{
   bullets.push_back(b);
   
}
