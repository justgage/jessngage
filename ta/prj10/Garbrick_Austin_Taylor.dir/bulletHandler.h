#ifndef BULLETHANDLER_H
#define BULLETHANDLER_H

#include "bullet.h"
#include "velocity.h"
#include "point.h"
#include "bird.h"

#include <vector>
using std :: vector;


class BulletHandler
{
  private:
   vector<Bullet*> bullets;
   int maxNumbBullets;

   float xMin, xMax, yMin, yMax;

  public:
   BulletHandler();
   BulletHandler(int maxNumbBullets, Point tl, Point br);
   ~BulletHandler();

   int updateBullets(Bird* bird);
   void drawBullets();
   void removeExpiredBullets();
   void addBullets(Bullet *b);
   
   
   
   


};

#endif
