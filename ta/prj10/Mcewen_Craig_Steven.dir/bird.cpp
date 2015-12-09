#include "bird.h"
#include "uiDraw.h"
#include "flyingobject.h"

//Draws the Normal Bird Circle

void NormalBird :: draw() const
{
   drawCircle(position, 20);
}

//Draws the tough bird with amount of life left
void ToughBird::draw() const
{
   drawToughBird(position, 20, hitCount);
}

//Draws the sacred Bird
void SacredBird::draw() const
{
   drawSacredBird(position, 20);
}

//Draws the moonLander as an extra bird
void MoonLander::draw() const
{
   drawLander(position);
   drawLanderFlames(position,true,false,false);
}

//tells you how much life is left in the tough bird
void ToughBird::addHit(int hit)
{
   if (hitCount != 0)
   {
     hitCount = hitCount - hit;
   }
}
//advances the bird and if off screen, throws another one

void Bird :: advance()
{

   if (position.getX() > -220 && position.getX() < 220 &&
       position.getY() > -220 && position.getY() < 220)
   {
      position.addX(birdVelocity.getDx());
      position.addY(birdVelocity.getDy());
      onScreen = true;
   }
   else
   {
      onScreen = false;
      position.setX(-220);
      position.setY(0);
   }
   
}

