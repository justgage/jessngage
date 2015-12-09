/****************************************
 * The game of Skeet
 ****************************************/

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "rifle.h"
#include "velocity.h"
#include "bird.h"
#include "bullet.h"
#include "flyingobject.h"
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
      int birdy = random(1,5);
      
      if (birdy == 1)
      {
         bird = new NormalBird;
      }
      else if (birdy == 2)
      {
         bird = new SacredBird;
      }
      else if (birdy == 3)
      {
         bird = new ToughBird;
      }
      else if (birdy == 4)
      {
         bird = new MoonLander;
         bird->setBirdVelX(8.5); //makes moonlander faster
      }
      bird->setAlive(false);
      
      bullet.push_back(new Bullet);
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
   Bird* bird;
   vector <Bullet*> bullet;
   int score;
   int birdType;
  
   // TODO: add any objects or variables that are required
};

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   // TODO: move lander and check for crashed
   if (bird->getAlive())//Add to check if its killed or not
   {
      bird->advance();
   }
   else
   {
      if (bird->getAlive() == false)
      {
         delete bird;
      }
      int birdy = random(1,5);
      birdType = birdy;
      if (birdy == 1)
      {
         bird = new NormalBird;
      }
      else if (birdy == 2)
      {
         bird = new SacredBird;
      }
      else if (birdy == 3)
      {
         bird = new ToughBird;
      }
      else if (birdy == 4)
      {
         bird = new MoonLander;
         bird->setBirdVelX(8.5);
      }
      bird->setAlive(true);
   }
   for (int i = 0; i < bullet.size(); i++)
   {
      bullet[i]->checkAlive(bird->getPosition());
      if (bullet[i]->getKill())
      {
         if (birdType == 1)
         {
            score++;
            bullet.erase(bullet.begin()+i);
            i--;
            bird->setAlive(false);
            
         }
         else if (birdType == 2)
         {
            score = score - 10;
            bullet.erase(bullet.begin()+i);
            i--;
            bird->setAlive(false);
            
         }
         else if (birdType == 3)
         {
            score++;
            bullet.erase(bullet.begin()+i);
            i--;
            bird->addHit(1);
            if (bird->getHit() == 0)
            {
               bird->setAlive(false);
               score = score + 2;
            }
         }
         else if (birdType == 4)
         {
            score = score + 10;
            bullet.erase(bullet.begin()+i);
            i--;
            bird->setAlive(false);
         }
      }
      else
      {
         bullet[i]->advance();
         float x = bullet[i]->getCurX();
         float y = bullet[i]->getCurY();
         if (x < -200 || y > 200)
         {
            bullet.erase(bullet.begin()+i);
            i--;
         }
      }
   }
}

/***************************************
 * GAME :: input
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // TODO: handle user input
   if (ui.isDown() || ui.isLeft())
   {
      rifle.changeAngle(3);
   }
   else if (ui.isUp() || ui.isRight())
   {
      rifle.changeAngle(-3);
   }
   else if (ui.isSpace())
   {
      Bullet* bullets = new Bullet;
      bullet.push_back(bullets);
      bullet.back()->drawNew(rifle);
      Point corner(190, -190);
      drawLanderFlames(corner,true,true,true); //draw flames when shot
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   // TODO: Draw the various elements of the game
   Point corner(-195, 195);
   rifle.draw();
   bird->draw();
   for (int i = 0; i < bullet.size(); i++)
   {
      bullet[i]->draw();
      
   }
   drawNumber(corner, score);
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
