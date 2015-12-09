/****************************************
 * The game of Skeet
 ****************************************/

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "rifle.h"
#include "bullet.h"
#include "bird.h"
#include "velocity.h"

/*****************************************
 * GAME
 * The main game class containing all the states
 *****************************************/
class Game
{
public:
   Game(Point tl, Point br) : topLeft(tl), bottomRight(br), rifle(br)
   {
     bird = new NormalBird;
     bird = new SacredBird;
     bird = new ToughBird;
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

   // TODO: add any objects or variables that are required
   Rifle rifle;
   Bird* bird;
};

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   // TODO: move stuff and check for collisions
   bird->advance(double random(double min, double max););
   if (bird.point = bullet.point || bird = isDead) //collision
   {
   delete bird;
   delete bullet;
   }
}

/***************************************
 * GAME :: input
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
 
Point point;
   // TODO: handle user input
   if (ui.isLeftPress())
   {
      rifle.isLeft(-1);
   }
   if (ui.isRightPress())
   {
      rifle.isRight(1);
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
  
  int score = 0;
  {if bullet.isDead && bird.isDead)
  {
  score = bird.pointValue;
  score++;
  }
  void drawDigit(const score & topRight, char score)
{
   score start;
      start.setX(topRight.getX() + score[x][y]);
      start.setY(topRight.getY() - score[x][y + 1]);
      score end == bullet = isDead;
      end.setX(topRight.getX() + score[x][y + 2]);
      end.setY(topRight.getY() - score[x][y + 3]);
         
      drawDigit(score);
   }
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

   Interface ui(argc, argv, "Skeet", topLeft, bottomRight);
   Game game(topLeft, bottomRight);
   ui.run(callBack, &game);
   
   return 0;
}
