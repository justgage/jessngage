#include "bird.h"
#include "uiDraw.h"

/* Normal Bird
   ####################################*/
int normalBird :: gotHit()
{
   if(life)
   {
      life = false;
      return pointValue;
   }
}

void normalBird :: draw()
{
   if(life)
      drawCircle(getPosition(), radius);
}

// Tough Bird
//  ##################################
int toughBird :: gotHit()
{
   if(life)
   {
      hits--;
      if(hits <= 0)
      {
         life = false;
         return 3;
      }
      else
         return pointValue;
   }
}
void toughBird :: draw()
{
   if(life)
      drawToughBird(getPosition(), radius, hits);
}

// eagleBird
// ##################################

int eagleBird :: gotHit()
{
   if(life)
   {
      life = false;
      return pointValue;
   }
}

void eagleBird :: draw()
{
   if(life)
      drawSacredBird(getPosition(), radius);
}
