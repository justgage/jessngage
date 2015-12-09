/****************************************
 * The game of Skeet
 ****************************************/

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "rifle.h"
#include "bullet.h"
#include "bird.h"
#include "sacredBird.h"
#include "toughBird.h"
#include "standardBird.h"
#include <vector>

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
   void drawBird();
   // advance the game
   void advance();
         
   // draw stuff
   void draw(const Interface & ui);
   int getScore()
   {
      return score;
   }
   void setScore(int score)
   {
      this->score = score;
   }
private:
   Point topLeft;
   Point bottomRight;
   Rifle rifle;
   Bullet bullet;
   int score;
   int birdCount;
   std::vector<Bullet> bullets;
   std::vector<Bird*> birds;
   // TODO: add any objects or variables that are required
};

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   int i = 0;
   bullet.advance();
   rifle.draw();
   if (bullets.empty() == true)
   {
   bullets.push_back(bullet);
   setScore(0);
   }
   for (std::vector<Bullet>::iterator it = bullets.begin() ; it != bullets.end(); ++it)
   {
      it->advance();
      if (birds.empty() != true)
      {
         if ((it->getPoint().getX() < (birds[0]->getPoint().getX() + birds[0]->getRadius()) 
             && it->getPoint().getX() > (birds[0]->getPoint().getX() - birds[0]->getRadius())) &&
             (it->getPoint().getY() < (birds[0]->getPoint().getY() + birds[0]->getRadius()) 
             && it->getPoint().getY() > (birds[0]->getPoint().getY() - birds[0]->getRadius())))
             {
                int add = (birds[0]->add() + getScore());
                setScore(add);
                birds.pop_back();
                drawBird();
             }
      }
    }
   for (std::vector<Bird*>::iterator it = birds.begin() ; it != birds.end(); ++it)
   {
      i++;
      if ((*it)->getPoint().getX() < topLeft.getX() ||
      (*it)->getPoint().getY() < bottomRight.getY() ||
      (*it)->getPoint().getX() > bottomRight.getX())
      {
         birds.pop_back();
         drawBird();
      }
      if (birds.empty() != true)
      {
         (*it)->advance();
      }
   }
   // TODO: move lander and check for crashed
}

/***************************************
 * GAME :: input
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   if (ui.isUp())
   {
      rifle.rotateUp();
   }
   if (ui.isDown())
   {
      rifle.rotateDown();
   }
   if (ui.isRight())
   {
      Bullet great;
      Velocity v;
      v.setDx(3/-cos(rifle.getAngle()*M_PI/180));
      v.setDy(3/sin(rifle.getAngle()*M_PI/180));
      bullets.push_back(great);
      for (std::vector<Bullet>::iterator it = bullets.begin() ; it != bullets.end(); ++it)
      {
         if (it->getVelocity().getDx() == 0)
         it->fire(v);
      }
   }
   // TODO: handle user input
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   rifle.draw();
   if (bullets.empty() == true)
   {
   bullets.push_back(bullet);
   }
   for (std::vector<Bullet>::iterator it = bullets.begin() ; it != bullets.end(); ++it)
   {
      it->draw();
   }
   drawBird();
   Point y;
   y.setX(-200);
   y.setY(190);
   drawNumber(y, getScore());
   // TODO: Draw the various elements of the game
}

void Game :: drawBird()
{
   Point p;
   p.setX(-190);
   p.setY(random(-150,180));
   int myNumber = random(2, 4);
   if (birds.size() == 0)
   {
   if(myNumber == 2)
   {
      Velocity v;
      if (p.getY() > 0)
      {
         v.setDx(3);
         v.setDy(-1);
      }
      else
      {
         v.setDx(3);
         v.setDy(1);
      }
      ToughBird* tBird = new ToughBird;
      tBird->setVelocity(v);
      tBird->setPoint(p);
      tBird->draw();
      birdCount++;
      birds.push_back(tBird);
   }
   if(myNumber == 3)
   {
      Velocity v;
      if (p.getY() > 0)
      {
         v.setDx(3);
         v.setDy(-1);
      }
      else
      {
         v.setDx(3);
         v.setDy(1);
      }
      SacredBird* scBird = new SacredBird;
      scBird->setVelocity(v);
      scBird->setPoint(p);
      scBird->draw();
      birdCount++;
      birds.push_back(scBird);

   }
   if (myNumber == 4);
   {
      Velocity v;
      if (p.getY() > 0)
      {
         v.setDx(3);
         v.setDy(-1);
      }
      else
      {
         v.setDx(3);
         v.setDy(1);
      }
      StandardBird* sBird = new StandardBird;
      sBird->setVelocity(v);
      sBird->setPoint(p);
      sBird->draw();
      birdCount++;
      birds.push_back(sBird);
   }
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

   Interface ui(argc, argv, "Moon Lander", topLeft, bottomRight);
   Game game(topLeft, bottomRight);
   ui.run(callBack, &game);
   
   return 0;
}
