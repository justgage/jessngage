/****************************************
 * The game of Skeet
 ****************************************/

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "rifle.h"
#include "bullet.h"
#include "bird.h"
#include <iostream>
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
      score = 0;
      misses = 0;
   }
   
   // handle user input
   void handleInput(const Interface & ui);

   // advance the game
   void advance();
         
   // draw stuff
   void draw(const Interface & ui);

    // Draw the hit score
   void drawScore();
   int getScore() const { return score; }
   void addScore(int points) { score += points; }

   // add bullets into game
   void shootBullet();

   // add birds into game
   void launchBird();

   // check for hits
   void isHit();
   
private:
   Point topLeft;
   Point bottomRight;
   int score;
   float misses;

   // TODO: add any objects or variables that are required
   Rifle gun;
   vector<Bullet> bulletVect;
   vector<Bird*> birdVect;
};

/*********************************************
 * GAME :: make bullets
 * add bullets into the game
 *********************************************/
void Game :: shootBullet()
{
   if (gun.getAmmoCount() > 0)
   {
      Bullet bullet;
      gun.shoot(bullet);
      gun.setAmmoCount(gun.getAmmoCount() - 1);
      bulletVect.push_back(bullet);
      //cerr << "bulletVect Size increased to: "
      //<< bulletVect.size() << endl;
   }
   else
   {
      drawText(Point(115, -180), "RELOAD!");
      drawText(Point(105, -193), "- Press down -");
   }
}

/*********************************************
 * GAME :: make birds
 * add birds into the game
 *********************************************/
void Game :: launchBird()
{
   if (birdVect.size() == 0)
   {  
      Bird *pBird;
      int select = random(1, 90);
      // random bird selection
      if (select == 1)
         pBird = new SacredBird;
      else if (select == 2)
         pBird = new ToughBird;
      else if (select == 3)
         pBird = new NormalBird;
      else if (select == 4)
         pBird = new BigBird;
      else if (select == 5)
         pBird = new TinyBird;
      else if (select == 6)
         pBird = new BossBird;
      
      // put bird into vector when a bird is created
      if (select <= 6)
         birdVect.push_back(pBird);
      
      cerr << "birdVect Size increased to: " << birdVect.size() << endl;
      //cerr << "Velocity: " << (*it)->getVelocity().getDX() << ", "
      //<< (*it)->getVelocity().getDY() << endl;
   }
   else
      ;  // delay time for next bird
}

/*********************************************
 * GAME :: make birds
 * add birds into the game
 *********************************************/
void Game :: isHit()
{
   for (vector<Bullet>::iterator B = bulletVect.begin();
        B != bulletVect.end(); ++B)
   { 
      for (vector<Bird*>::iterator A = birdVect.begin();
           A != birdVect.end(); ++A)
      {
         if ((*A)->isHit(B->getPosition(), (*A)->getPosition()))
         {
            (*A)->takeHit(B->getDamage());
            addScore((*A)->getScorePoint());
            bulletVect.erase(B--);
            if ((*A)->getHitPoints() < 1)
            {
               addScore((*A)->getBonusPoint());
               birdVect.erase(A--);
            }
         }
      }
   } 
}

/*********************************************
 * GAME :: drawScore
 * Draw score of hits
 *********************************************/
void Game :: drawScore()
{
   // display score
   drawText(Point(-200, 190), "Score:");
   drawNumber(Point(-160, 200), score);

   // display number of missed birds
   drawText(Point(130, 190), "Missed:");
   drawNumber(Point(180, 200), misses);
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{  
   // move bullets
   for (vector<Bullet>::iterator it = bulletVect.begin();
        it != bulletVect.end(); ++it)
   {
      if (!(it->isOnScreen()))
      {
         bulletVect.erase(it--);
         //cerr << "bulletVect Size decreased to: "
         //<< bulletVect.size() << endl;
      }
      else
         it->advance();
   }

   // send out a bird if one is not present
   launchBird();
  
   // move birds
   for (vector<Bird*>::iterator it = birdVect.begin();
        it != birdVect.end(); ++it)
   {
      if (!((*it)->isOnScreen()))
      {
         birdVect.erase(it--);
         misses += 1;
         cerr << "birdVect Size decreased to: " << birdVect.size() << endl;
      }
      else
      (*it)->advance();
   }

   // check for hits
   isHit();
}

/***************************************
 * GAME :: input
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // TODO: handle user input
   if (ui.isRight())
      gun.aimUp();
   if (ui.isLeft())
      gun.aimDown();
   if (ui.isSpace())
   {
      shootBullet();
   }
   if (ui.isDown())
      gun.reload();
   if (ui.isUp())
      gun.drawLaserSight();
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   // TODO: Draw the various elements of the game
   //draw rifle
   gun.draw();

   // draw bullets
   for (vector<Bullet>::iterator it = bulletVect.begin();
        it != bulletVect.end(); ++it)
      it->draw();

   // draw birds
   for (vector<Bird*>::iterator it = birdVect.begin();
        it != birdVect.end(); ++it)
      (*it)->draw();
 
   // draw score
   drawScore();
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
