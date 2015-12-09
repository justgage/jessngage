/****************************************
 * The game of Skeet
 ****************************************/

#include <cmath>
#include <math.h>
#include <vector>
#include <list>
#include <stdlib.h>
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "rifle.h"
#include "flyingObject.h"
#include "bullet.h"
#include "bird.h"

using namespace std;

#define BULLET_VELOCITY 10.0;
#define deg2rad(value) ((M_PI / 180) * (value))

// statically drawn elements
Point pointsWord = Point(100,171);
Point pointsPosition = Point(150,180);
Point roundsWord = Point(95,151);
Point roundsPosition = Point(150,160);
Point instructions1 = Point(-100,0);
Point instructions2 = Point(-100,-20);
Point instructions3 = Point(-100,-40);
Point instructions4 = Point(-100,-60);

// rifle
Rifle rifle = Rifle();

// bullet list
list<Bullet *> bullets;

// bird list
list<Bird *> birds;

// game values
int points = 0;
int rounds = 7;
bool start = true;


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
    
    // collision detection
    bool collidedMuch(Point, Point, int);
   
private:
    // screen parameters
    Point topLeft;
    Point bottomRight;
    
};

// given two points and a buffer zone, have they collided?
bool Game :: collidedMuch(Point point1, Point point2, int dist)
{
    double xDistSq = (point1.getX() - point2.getX()) * (point1.getX() - point2.getX());
    double yDistSq = (point1.getY() - point2.getY()) * (point1.getY() - point2.getY());
    
    float space = sqrt(xDistSq + yDistSq);
    
    if (space < dist)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   // advance bullets forward and set to dead if they hit a wall
    for (list<Bullet *>::iterator it = bullets.begin() ; it != bullets.end(); ++it)
    {
        if ((*it)->getLife())
        {
            (*it)->advance();
            if ((*it)->getLocation().getX() < -200 ||
                (*it)->getLocation().getY() > 200)
            {
                (*it)->setLife(false);
            }
        }
    }
    
    // advance birds forward and set to dead if they hit a wall
    for (list<Bird *>::iterator it = birds.begin() ; it != birds.end(); ++it)
    {
        if ((*it)->getLife())
        {
            (*it)->advance();
            if ((*it)->getLocation().getX() > 200 ||
                (*it)->getLocation().getY() > 200 ||
                (*it)->getLocation().getY() < -200)
            {
                (*it)->setLife(false);
            }
        }
    }
    
    // collision detection between bullets and birds
    for (list<Bullet *>::iterator it = bullets.begin() ; it != bullets.end(); ++it)
    {
        for (list<Bird *>::iterator it2 = birds.begin() ; it2 != birds.end(); ++it2)
        {
            if (collidedMuch((*it)->getLocation(),(*it2)->getLocation(),(*it2)->getRadius()))
            {
                (*it)->collide();
                points += (*it2)->collide();
            }
        }
    }
    
    // delete dead bullets from list
    for (list<Bullet *>::iterator it = bullets.begin() ; it != bullets.end(); ++it)
    {
        if (!(*it)->getLife())
        {
            bullets.erase(it--);
        }
    }
    
    // delete dead birds from list
    for (list<Bird *>::iterator it = birds.begin() ; it != birds.end(); ++it)
    {
        if (!(*it)->getLife())
        {
            birds.erase(it--);
        }
    }
}

/***************************************
 * GAME :: input
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
    // angle gun up
    if(ui.isRight())
    {
        rifle.rotateDown();
    }
    // angle gun down
    if(ui.isLeft())
    {
        rifle.rotateUp();
    }
    // shoot a bullet
    if(ui.isSpace())
    {
        start = false; // make instructions disappear
        
        Velocity velocity;
        float x = sin(deg2rad(rifle.getAngle())) * BULLET_VELOCITY;
        float y = cos(deg2rad(rifle.getAngle())) * BULLET_VELOCITY;
        velocity.setDx(-x);
        velocity.setDy(y);
        if(rounds > 0)
        {
            bullets.push_back( new Bullet(velocity) );
            rounds -= 1;
        }
    }
    // pull!
    if(ui.isUp())
    {
        start = false; // make instructions disappear
        
        int delay = rand() % 5;
        if (delay == 0)
        {
            int randomBird = rand() % 3;
            if (randomBird == 0)
            {
                birds.push_back( new StandardBird() );
            }
            if (randomBird == 1)
            {
                birds.push_back( new StrongBird() );
            }
            if (randomBird == 2)
            {
                birds.push_back( new SacredBird() );
            }
        }
    }
    // load the gun with full ammo
    if(ui.isDown())
    {
        rounds = 7;
    }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
    // draw rifle
    rifle.draw();
    
    // draw bullets
    for (list<Bullet *>::iterator it = bullets.begin() ; it != bullets.end(); ++it)
    {
        (*it)->draw();
    }
    
    // draw birds
    for (list<Bird *>::iterator it = birds.begin() ; it != birds.end(); ++it)
    {
        (*it)->draw();
    }
    
    // display of points accumulated and rounds left + startup instructions
    drawText(pointsWord, "points");
    drawNumber(pointsPosition, points);
    drawText(roundsWord, "rounds");
    drawNumber(roundsPosition, rounds);
    if (start)
    {
        drawText(instructions1,"press up arrow to launch a bird");
        drawText(instructions2,"use left and right to angle the gun");
        drawText(instructions3,"spacebar to shoot");
        drawText(instructions4,"and down arrow to reload the gun");
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

   Interface ui(argc, argv, "skeet", topLeft, bottomRight);
   Game game(topLeft, bottomRight);
   ui.run(callBack, &game);
   
   return 0;
}
