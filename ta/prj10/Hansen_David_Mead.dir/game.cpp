/****************************************
 * The game of Skeet
 ****************************************/

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "rifle.h"
#include "bullet.h"
#include "bird.h"
#include <vector>

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
   // create the game
   Game(Point tl, Point br) : topLeft(tl), bottomRight(br),
                              deadBird(true), score(0), board(-190, 190),
                              count(180,190), numBirds(0) { }
   
   // handle user input
   void handleInput(const Interface & ui);

   // advance the game
   void advance();
         
   // draw stuff
   void draw(const Interface & ui);

   Rifle rifle;
   Bullet bullet;
   Bird * bird;
   bool deadBird;
   int score;
   Point board;
   int numBirds;
   Point count;
   int type;      
   
private:
   Point topLeft;
   Point bottomRight;
   // TODO: add any objects or variables that are required


};

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   // TODO: move lander and check for crashed
   bullet.applyVelocity();
   
   if (bullet.middle.getX() < -200 || bullet.middle.getY() > 200)
   {
      bullet.reset();
   }

   if(deadBird)
   {
      if(numBirds != 0)
      {
         delete bird;
      }
      
      numBirds++;
      type = bird->getType();

      if(type == 1)
      {
         NormalBird * nBird = new NormalBird;
         bird = nBird;
      }
      else if (type == 2)
      {
         ToughBird * tBird = new ToughBird;
         bird = tBird;
      }
      else if (type == 3)
      {
         SacredBird * sBird = new SacredBird;
         bird = sBird;
      }
   }

   if((-220 <= bird->getMiddleX() && bird->getMiddleX() <= 220) &&
      (-220 <= bird->getMiddleY() && bird->getMiddleY() <= 220))
   {
      if (bird->hit(bullet) != 0)
      {
         if(!deadBird)
         {
            score += bird->hit(bullet);
         }

         if(type != 2)
         {
         deadBird = true;
         bird->reset();
         bullet.reset();
         }
         else if(bird->getHits() > 1)
         {
            bird->minusHits();
            bullet.reset();
         }
         else
         {
            deadBird = true;
         bird->reset();
         bullet.reset();
         }
      }
      else
      {
         deadBird = false;
         bird->move();
      }

   }
   else
   {
      deadBird = true;
      bird->reset();
   }   
      
}

/***************************************
 * GAME :: input
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // TODO: handle user input

   if (ui.isLeft() && rifle.getRotation() > 0)
   {
      rifle.setRotation(3);
   }

   if (ui.isRight() && rifle.getRotation() <= 90)
   {
      rifle.setRotation(-3);
   }

   if (ui.isSpace())
   {
        bullet.fire(rifle.getRotation());
   }

   // keeps the rifle angle between 0 and 90
   
   if(rifle.getRotation() < 0)
   {
      rifle.setRotation(3);
   }
   
   if(rifle.getRotation() > 90)
   {
      rifle.setRotation(-3);
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   // TODO: Draw the various elements of the game
   rifle.draw();
   bullet.draw();
   bird->draw();

   // display score
   drawNumber(board, score);
   // display number of birds spawned
   drawNumber(count, numBirds); 
}


/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void *p)
{
   Game *pGame = (Game *)p;
   
   pGame->advance();
   pGame->handleInput(*pUI);
   pGame->draw(*pUI);
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * the game and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
   Point topLeft(-200, 200);
   Point bottomRight(200, -200);

   Interface ui(argc, argv, "Moon Lander", topLeft, bottomRight);
   Game game(topLeft, bottomRight);
   ui.run(callBack, &game);
   
   return 0;
}
