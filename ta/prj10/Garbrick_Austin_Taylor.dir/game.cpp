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
#include "bulletHandler.h"
#include <cstdlib>



/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
const Point birdStart (-200, 0);
const Velocity birdConstVelocity(5,0);

class Game
{
public:
   // create the game
   Game(Point tl, Point br) : topLeft(tl), bottomRight(br), scorePoint(-195,195), missedBirdsPoint(180,195)
   {
      bird = NULL ;
      rotator = 0;
      score = 0;
      missedBirds = 0; 
   }

   ~Game()
   {
      if (bird != NULL)
         delete bird;
   }
   
   // handle user input
   void handleInput(const Interface & ui);

   // advance the game
   void advance();
         
   // draw stuff
   void draw(const Interface & ui);
   
private:
   Point topLeft;
   Point bottomRight;
   Rifle rifle;
   Bird *bird;
   int rotator;
   BulletHandler bullets;
   int score;
   Point scorePoint;
   int missedBirds;
   Point missedBirdsPoint;
   

   // TODO: add any objects or variables that are required
};

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   int oldScore = score;
   score += bullets.updateBullets(bird);
   bullets.removeExpiredBullets();
   if (bird != NULL && bird->getLife() == 0)
   {
      delete bird;
      bird = NULL;
   }

   // generate vector for the bird
   
   
   if (bird == NULL)
   {
      
      int num = rand()%3;
    
      switch(num)
      {
         case 0:
            bird = new Bird();
            break;

         case 1:
            bird = new StrongBird();
            break;

         case 2:
            bird = new SacredBird();
            break;
      }
   }
   else
   {
      bird-> update();
      int x = bird-> getPoint().getX();
      int y = bird-> getPoint().getY();
      if (x>= 200 || y>= 200 || y<=-200)
      {
         delete bird;
         bird = NULL;
         missedBirds ++;
      }
   
   }
}

/***************************************
 * GAME :: input
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   if (ui.isLeft())
   {
      rifle.left();
   }
   if (ui.isRight())
   {
      rifle.right();
   }
   if (ui.isSpace())
   {
      bullets.addBullets(rifle.shoot());
      
   }
           
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   drawNumber (scorePoint, score);
   drawNumber (missedBirdsPoint, missedBirds); 
   rifle.draw();
   if (bird != NULL)
   {
      bird->draw();
   }

   bullets.drawBullets();
                            


   
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
