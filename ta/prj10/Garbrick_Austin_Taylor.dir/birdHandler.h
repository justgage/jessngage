#ifndef BIRDHANDLER_H
#define BIRDHANDLER_H

#include "bullet.h"
#include "velocity.h"
#include "point.h"
#include "bird.h"

class BirdHandler
{
  private:
   Birds** birds;
   int numBirds;
   int MAX_NUM_BIRDS;

  public:
   BirdHandler()
   {
      Birds** birds;
   }

   BirdHandler(int MAX_NUM_BIRDS = 5)
   {
       numBirds = 0;
       MAX_NUMB_BIRDS = maxBirds
       birds = new Bird*[MAX_NUM_BIRDS];
   }

   ~BirdHandler()
   {
      for (i = 0; i < numBirds; i ++)
      {
         if (birds[i] != NULL)
         {
            delete birds[i];
         }
      }
      delete[] birds;
   }
         
   

   void createBirds();
   void updateBirds();
   void hitBirds();
   void destroyBirds();

};
#endif

   
