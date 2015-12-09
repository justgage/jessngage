/****************************************
 * The game of Skeet
 ****************************************/

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "bullet.h"
#include "rifle.h"
#include "bird.h"
#include <vector>

using namespace std;



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
		birdsize = random(0, 3);
		if (birdsize == 0)
		{
			bird = new NormalBird;
			bird->birdAngle();
		}
		else if (birdsize == 1)
		{
			bird = new ToughBird;
			bird->birdAngle();
		}
		else if (birdsize == 2)
		{
			bird = new SacredBird;
			bird->birdAngle();
		}

		scoreP.setX(-150);
		scoreP.setY(190);
		score = 0;
	}
   
   // handle user input
   void handleInput(const Interface & ui);

   // advance the game
   void advance();
         
   // draw stuff
   void draw(const Interface & ui);
   
private:
	int birdsize;
   Point topLeft;
   Point bottomRight;
   Point scoreP;

   Rifle rifle;
   Bullet bullet;
   Bird* bird;
   vector<Bullet> bullets;

   float score; 
   // TODO: add any objects or variables that are required
};

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game::advance()
{
	if (random (0, 15) == 2)
	{
		if (!bird->isAlive())
		{
			birdsize = random(0, 3);
			if (birdsize == 0)
			{
				bird = new NormalBird;
				bird->birdAngle();
			}
			else if (birdsize == 1)
			{
				bird = new ToughBird;
				bird->birdAngle();
			}
			else if (birdsize == 2)
			{
				bird = new SacredBird;
				bird->birdAngle();
			}
		}
	}
	for (int i = 0; i < bullets.size(); i++)
 	{
		if (bullets[i].isAlive())
		{  
			bullets[i].advance();
			
			if (abs(bullets[i].getX() - bird->getX()) < 20
				&& abs(bullets[i].getY() - bird->getY()) < 20)
			{
				bullets.erase(bullets.begin() + i);
				
				if (birdsize == 0)
				{
					score += 1;
					bird->kill();
				}
				else if (birdsize == 1)
				{
 					bird->hit();
					
					if (bird->hitcounter == 0)
					{
						score += 3;
						bird->kill();
					}
					else
					{
						score += 1;
					}
				}
				else if (birdsize == 2)
				{
					bird->kill();
					score -= 10;
				}
			}
		}
		else
		{
			bullets.erase(bullets.begin() + i);
		}
	}

	if (bird->isAlive())
	{
		bird->advance();
	}
	
}

/***************************************
 * GAME :: input
 * accept input from the user
 ***************************************/
void Game::handleInput(const Interface & ui)
{
	// TODO: handle user input

	if (ui.isLeft())
	{
		rifle.anglePos();
	}

	if (ui.isRight())
	{
		rifle.angleNeg();
	}

	if (ui.isSpace())
	{
		bullet = Bullet();
		bullets.push_back(bullet);

		for (int i = 0; i < bullets.size(); i++)
		{
			if (!bullets[i].isAlive())
			{
				bullets[i].fire(rifle.getAngle());
			}
		}
	}
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   // TODO: Draw the various elements of the game
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			bullets[i].drawBullet();
		}
	}

	rifle.draw();

	if (bird->isAlive())
	{
 		bird->draw();		
	}

	drawNumber(scoreP, score);
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
