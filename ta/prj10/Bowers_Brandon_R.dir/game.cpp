/****************************************
 * The game of Skeet
 ****************************************/

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "Rifle.h"
#include "Bullet.h"
#include "flyingObject.h"
#include "bird.h"
#include <cmath>

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
   // create the game
   Game(Point tl, Point br) : topLeft(tl), bottomRight(br) 
   {
	   int num = random(1, 3);

	   if (num = 1)
	   {
		   bird = new NormalBird;
	   }
	 
	   else if (num = 2)
	   {
		   bird = new ToughBird;
	   }
	   
	   else if (num = 3)
	   {
		   bird = new SacredBird;
	   }
   
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
   Velocity velocity;
   Bullet bullet;
   Bird* bird;

};

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
	bird->advance();
	//bullet.advance();
}

/***************************************
 * GAME :: input
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // TODO: handle user input

	if (ui.isRight())
	{
		//rotate up 3 degrees
		rifle.rotateUp();
	}

	if (ui.isLeft())
	{
		//rotate down 3 degrees
		rifle.rotateDown();
	}

	if (ui.isSpace());
	{
		bullet.advance();
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

	bullet.drawBullet();

	bird->draw();
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
