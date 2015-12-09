/****************************************
 * The game of Skeet
 ****************************************/

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "rifle.h"
#include "bird.h"
#include "bullet.h"
#include <vector>
using namespace std;

#define MOONLANDER_SCORE 10
/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
   int bulletCount;
   int score;
   // create the game
   Game(Point tl, Point br) : topLeft(tl), bottomRight(br)
   {
      score = 0;
      bulletCount = 0;
      int whichBird = random(1,8);
      if(whichBird == 1 || whichBird == 2)
      {
         bird = new NormalBird;
      }
      else if(whichBird == 3 || whichBird == 4)
      {
         bird = new ToughBird;
         bird->changeHitNum(2);
         bird->setVelocityX(2.0);
      }
      else if(whichBird == 5 || whichBird == 6)
      {
         bird = new SacredBird;
      }
      else
      {
         bird = new MoonLander;
      }
      
      bird->setIsAlive(false);
      bullets.push_back(new Bullet);
   }
   
   // handle user input
   void handleInput(const Interface & ui);

   // advance the game
   void advance();
         
   // draw stuff
   void draw(const Interface & ui);
   
private:
   int birdType;
   Point topLeft;
   Point bottomRight;
   Rifle rifle;
   Bird* bird;
   vector <Bullet*> bullets;

// TODO: add any objects or variables that are required
};

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{

// TODO: move lander and check for crashed
   if(bird->getIsAlive() == true)
   {
      bird->advance();
   }
   else
   {
      delete bird;

      int whichBird = random(1,8);
      if(whichBird == 1 || whichBird == 2)
      {
         bird = new NormalBird;
      }
      else if(whichBird == 3 || whichBird == 4)
      {
         bird = new ToughBird;
         bird->changeHitNum(2);
         bird->setVelocityX(2.0);
      }
      else if(whichBird == 5 || whichBird == 6)
      {
         bird = new SacredBird;
      }
      else
      {
         bird = new MoonLander;
      }
      
      bird->setIsAlive(true);
      birdType = whichBird;
   }

   for(int i = 0; i < bullets.size(); i++)
   {
      if(bullets[i]->checkCollide(bird->getPosition()))
      {
         bullets.erase(bullets.begin()+i);
         i--;
         bulletCount--;

         if(birdType == 1 || birdType == 2)
         {
            score++;
            bird->setIsAlive(false);
         }
         else if(birdType == 3 || birdType == 4)
         {
            bird->changeHitNum(-1);
            score++;
            if (bird->getHitNum() == 0)
            {
               score = score + 2;
               bird->setIsAlive(false);
            }
         }
         else if(birdType == 5 || birdType == 6)
         {
            score = score - 10;
            bird->setIsAlive(false);
         }
         else
         {
            score = score + MOONLANDER_SCORE;
            bird-> setIsAlive(false);
         }
      }
      
      bullets[i]->advance();
      float x = bullets[i]->getBulletX();
      float y = bullets[i]->getBulletY();
      if(x < -200 || y > 200)
      {
         bullets.erase(bullets.begin()+i);
         i--;
         bulletCount--;
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
   if (ui.isLeft())
   {
      rifle.changeAngle(3);
   }
   if (ui.isUp())
   {
      rifle.changeAngle(-3);
   }
   if(ui.isSpace())
   {
      Bullet* newBullet = new Bullet;
      bullets.push_back(newBullet);
      bullets.back()->fire(rifle.getAngle());
      bulletCount++;
   }
}


/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   bird->draw();
   rifle.draw();
   Point scoreLocal(-195,195);
   drawNumber(scoreLocal, score);
   for (int i = 0; i < bullets.size(); i++)
   {
         bullets[i]->draw();
   }
// TODO: Draw the various elements of the game
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
