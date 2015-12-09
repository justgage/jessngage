/***********************************************************************
 * Header File:
 *    Bird.cpp : The object at which we will shoot
 * Author:
 *    Taylor Groom
 * Summary:
 *    Everything we need to know about a bird, including its velocity,
 *    position, drawing it, advcancing it, checking if it is alive
 *    the location and the bounds. also contains three offspring classes,
 *    normalBird, toughBird, and sacredBird.  Is a flyingobject
 ************************************************************************/
#include "bird.h"
#include "uiDraw.h"
#include "flyingobject.h"

/************************************************************************
 *  Bird::Draw - the default draw function for birds.  Will draw a circle
 *  at the bird's current location
 ***********************************************************************/
void Bird::draw() const
{
   
   drawCircle(position,20);
}

/************************************************************************
 *   NormalBird::draw - draws the normal bird as a circle at the birds current
 *   location
 ***********************************************************************/
void NormalBird::draw() const
{
   
   drawCircle(position,20);

}
/************************************************************************
 *  ToughBird::draw - draws the tough bird as a circle with the number
 *  of its requied to kill it in the center, at the birds current 
 *  location
 ***********************************************************************/
void ToughBird::draw() const
{
   drawToughBird(position, 20, hitNum);
}

/************************************************************************
 *   SacredBird::draw - draws the sacred bird as a star at the birds 
 *   current location
 ***********************************************************************/
void SacredBird::draw() const
{
   drawSacredBird(position, 20);
}

/************************************************************************
 *   advance - checks the birds location to make sure it is on the screen
 *   and if it is it moves the bird one frame at the current velocity.
 *   If the position is off the screen the function will "kill" the bird
 ***********************************************************************/

void MoonLander :: draw() const
{
   drawLander(position);
   Point textLocal;
   textLocal.setX(-20);
   textLocal.setY(160);
   drawText(textLocal, "Shoot the alien ship!!!");
}

void Bird :: advance()
{
   if(position.getX() > -220 && position.getX() < 220 &&
      position.getY() > -220 && position.getY() < 220)
   {
      position.addX(velocity.getdx());
      position.addY(velocity.getdy());
   }
     else
   {
      isAlive = false;
   }

}

/************************************************************************
 *  setVelocity - takes velocity as a parameter and sets the birds velocity
 *  to this new value
 ***********************************************************************/
void Bird :: setVelocity(Velocity temp)
{
   velocity = temp;
}

