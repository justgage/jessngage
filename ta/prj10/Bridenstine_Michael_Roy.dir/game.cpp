/****************************************
 * The game of Skeet
 ****************************************/

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "rifle.h"
#include "shot.h"
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
      bird = new normalBird(false);
      score = 0;
      shotsFired = 0;
      missedShots = 0;
      shotsHit = 0;
      birdRespawnCounter = 0;
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
   vector<Shot> shots;
   Bird* bird;
   int score;
   int birdRespawnCounter;
   int missedShots;
   int shotsHit;
   int shotsFired;

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
      //Shot
      //See if shot hits edge of screen
      if( (*it).getX() < -200 || (*it).getX() > 200
          || (*it).getY() > 200  )
      {
         shots.erase(it--);
         missedShots++;
      }

      //See if shot hits a bird
      else if ( (*it).getX() < (bird->getX() + 12)  &&
                (*it).getX() > (bird->getX() - 12)  &&
                (*it).getY() < (bird->getY() + 12) &&
                (*it).getY() > (bird->getY() - 12)                 
              )
      {
         if(bird->getLife())
         {

            score += bird->gotHit();
            shots.erase(it--);
            shotsHit++;
         }
         else
            (*it).advance();
      }
      //Shot didn't hit anything, so move on
      else
      {
         (*it).advance();
      }      
   }
   
     
     //Bird
   if(bird->getLife())
   {
      bird->advance();
      birdRespawnCounter = 0;
        
      if(bird->getX() > 200
         || bird->getY() > 200
         || bird->getY() < -200)
      {
         bird->setLife(false);
      }
   }
   else
   {
      birdRespawnCounter = random(1,60);
   }
    
     //make a new bird.
   if(birdRespawnCounter >= 58)
   {
      int randYPos = random(-180, 180);
      float yVel = 0;
      float xVel = random (3.0, 6.0);

        //Set Bird Speed
      if(randYPos < 0)
         yVel = random(0.0, 4.0);
      else if (randYPos > 0)
         yVel = random(-4.0, 0.0);

      //Hard Mode: Starts after 50 points gained
      if(score > 35)
      {
         xVel = xVel * 1.25;
         yVel = yVel * 1.25;
      }
      
        //Set Bird Type
      int rand = random(1,4);
      if(rand == 1)
      {
         delete bird;
         bird = new normalBird;

         Point pos(-180,randYPos);
         bird->setPosition(pos);
         bird->setVelocity(xVel,yVel);

         birdRespawnCounter = 0;
      }
      else if (rand == 2)
      {
         delete bird;
         bird = new toughBird;
         
         xVel = random (2.0, 4.0);
         if(randYPos > 0)
            yVel = random (-3.0, 0.0);
         else
            yVel = random (0.0, 3.0);

         //Hard Mode:
         if(score > 35)
         {
            xVel = xVel * 1.25;
            yVel = yVel * 1.25;
         }

         Point pos(-180,randYPos);
         bird->setPosition(pos);
         bird->setVelocity(xVel,yVel);

         birdRespawnCounter = 0;
      }
      else if (rand == 3)
      {
         delete bird;
         bird = new eagleBird;

         Point pos(-180,randYPos);
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
      
      Shot oneShot;
      oneShot.setPosition(bottomRight);
      oneShot.setAngledVelocity(10, rifle.getAngle());
      
      shots.push_back(oneShot);
      shotsFired++;
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
   drawNumber(hud, shotsFired);

   //Accuracy
   if(missedShots > 0 || shotsHit > 0)
   {
      hud.setX(-30);
      hud.setY(185);
      drawText(hud, "Accuracy:");
      hud.setX(35);
      hud.setY(194);
      int accuracy = 100 * (shotsHit) / (shotsHit + missedShots);
      drawNumber(hud, accuracy);
   }
   
   //Score Board
   hud.setX(110);
   hud.setY(185);
   drawText(hud, "Score:");
   hud.setX(155);
   hud.setY(194);
   drawNumber(hud, score);

   //Draw shots
   for(vector<Shot> :: iterator it = shots.begin(); it != shots.end(); it++)
   {
      (*it).drawShot();
   }

   //Draw Bird
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
