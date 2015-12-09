/****************************************
 * The game of Skeet
 ****************************************/

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "rifle.h"
#include "shot.h"
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
   Game(Point tl, Point br) : topLeft(tl), bottomRight(br) { }
   
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
   vector<Shot> shots;
   int score;
   Bird* bird = new normalBird(false);
   int birdRespawnCounter = 0;
   int missedBirds = 0;

   // TODO: add any objects or variables that are required
};

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   // Move flying objects and check collisons
     for(vector<Shot> :: iterator it = shots.begin(); it != shots.end(); it++)
   {
      //TODO: Collision Detection
      (*it).advance();
   }
     if(bird->getLife())
     {
        bird->advance();
        if(bird->getPosition().getX() > 200
           || bird->getPosition().getX() < -200
           || bird->getPosition().getY() > 200
           || bird->getPostion().getY() < 200)
        {
           bird->setLife(false);
        }
     }
     else
        birdRespawnCounter++;

     if(birdRespawnCounter > 60)
     {
        int randYPos = random(-199, 199);
        float yVel = 0;
        float xVel = random (3.0, 6.0);

        //Set Bird Speed
        if(randYPos > 0)
           yVel = random(0.0, 4.0);
        else if (randYpos < 0)
           yVel = random(-4.0, 0.0);

        //Set Bird Type
        int rand = rand(1,3);
        if(rand == 1)
        {
           bird = new normalBird;

           Point pos(-199,randYPos);
           bird->setPosition(pos);
           bird->setVelocity(xVel,yVel);

           birdRespawnCounter = 0;
        }
        else if (rand == 2)
        {
           bird == new toughBird;

           Point pos(-199,randYPos);
           bird->setPosition(pos);
           bird->setVelocity(xVel,yVel);

           birdRespawnCounter = 0;
        }
        else if (rand == 3)
        {
           bird == new eagleBird;

           Point pos(-199,randYPos);
           bird->setPosition(pos);
           bird->setVelocity(xVel,yVel);
           
           birdRespawnCounter = 0;
        }
     }
}

/***************************************
 * GAME :: input
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface& ui)
{
   // TODO: handle user input
   if(ui.isLeft())
   {
      rifle.rotateLeft();
   }

   if(ui.isRight())
   {
      rifle.rotateRight();
   }

   if(ui.isSpace())
   {
      Shot oneShot(bottomRight, rifle.getAngle());
      oneShot.setVelocity(5,5);

      Point fail(50,50);
      drawNumber(fail, oneShot.getVelocity().getDx());
      
      shots.push_back(oneShot);
   }
   
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   // TODO: Draw the various elements of the game

   rifle.drawRifle(bottomRight);

   //Shots fired counter
   Point hud(-195,185);
   drawText(hud, "Shots fired:");
   hud.setX(-127);
   hud.setY(194);
   drawNumber(hud, shots.size());

   //Score Board
   hud.setX(160);
   hud.setY(185);
   drawText(hud, "Score:");
   hud.setX(190);
   hud.setY(194);
   drawNumber(hud, score);
   
   //shots moving?
   Point middle(0,0);
   if(shots.size() > 1)
   drawNumber(middle, shots[0].getVelocity().getDx());

   //Draw shots
   for(vector<Shot> :: iterator it = shots.begin(); it != shots.end(); it++)
   {
      (*it).drawShot();
   

   //Draw Bird
      if(birdRespawnCounter == 0)
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
