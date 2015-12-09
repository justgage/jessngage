/***********************************************************************
 * Header File:
 *    Bullet.cpp: Projectile
 * Author:
 *    Taylor Groom
 * Summary:
 *    Contains everything you need to know about the bullet including
 *    location, velocity, if it is in play and alive, and functions such
 *    as advance and draw. Is a type of flying object.
 *************************************************************************/
#include "bullet.h"
#include "uiDraw.h"
#include "math.h"
#define PI 3.14159

/*****************************************************************
 *      draw - checks to see if the bullet is in play.  If bullet
 *      is alive it will be drawn at its current location
 ****************************************************************/
void Bullet::draw() const
{
   if(bulletInPlay)
   {
      drawDot(position);
   }
}

/*****************************************************************
 *      advance - checks if bullet is in play, if it is the 
 *      bullet will be advanced one frame at its current velocity.
 *      After moving the bullet, the function will make sure the
 *      bullet is still on the screen and will "kill" the bullet
 *      if its off the screen.
 ****************************************************************/
void Bullet :: advance()
{
   if(bulletInPlay == true)
   {
      position.addX(velocity.getdx());
      position.addY(velocity.getdy());
   }
   if (position.getX() < -200 || position.getY() > 200)
   {
      bulletInPlay = false;
      shot = false;
   }
   shot = false;
}  


/*****************************************************************
 *      fire - is called whenever a new bullet is fired.  takes
 *      the angle of the rifle as a parameter, and sets the 
 *      bullets velocity to represent that angle.  Sets
 *      bulletInPlay to true.
 ****************************************************************/
bool Bullet :: fire(int angle)
{
   if (!shot)
   {
      shot = true;
      velocity.setDx(-10 * sin(angle*PI/180));
      velocity.setDy(10 * cos(angle*PI/180));
   }
      bulletInPlay = true;
}


/*****************************************************************
 *      checkCollide - accepts the birds location as a parameter
 *      and checks this location against a 10x10 square around the
 *      bullet to determine a collision. A collision will cause the
 *      bullet to be "killed" and will return false so the game.cpp
 *      will know to "kill" the bird.
 ****************************************************************/
bool Bullet :: checkCollide(Point birdPoint)
{
   int bulletX = position.getX();
   int bulletY = position.getY();
   int birdX = birdPoint.getX();
   int birdY = birdPoint.getY();
   if(bulletX < birdX + 20 &&
      bulletX > birdX -20 &&
      bulletY < birdY + 20 &&
      bulletY > birdY - 20)
   {
      bulletInPlay = false;
      return true;
   }
   else
   {
      return false;
   }
   
}
