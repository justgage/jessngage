#include "bird.h"
#include <iostream>

void randomBird::draw() const
{
NormalBird::draw() const;
SacredBird::draw() const
ToughBird::draw() const
}

void NormalBird::draw() const
{
int pointValue = 1;
drawCircle(position, 20);
point->pointX (-250);
point->pointY (int i=0; i < 50 > 200);
if ((NormalBird.point = bullet.point) * 1) //collision
   {
   return isDead;
   }
}

void SacredBird::draw() const
{
int pointValue = -10;
drawSacredBird(position, 20);
point->pointX (-250);
point->pointY (int i=0; i < 50 > 200);

if ((SacredBird.point = bullet.point) * 1) //collision
   {
   return isDead;
   }
}

void ToughBird::draw() const
{
int pointValue = 1;
drawToughBird(position, 20);
point->pointX (-250);
point->pointY (int i=0; i < 50 > 200);

 if ((ToughBird.point = bullet.point) * 3) //collision
   {
   return isDead;
   }
}
