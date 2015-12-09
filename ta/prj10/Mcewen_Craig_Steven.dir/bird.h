/***********************************************************************
 * Header File:
 *    Bird.h
 * Author:
 *    Craig McEwen
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/


#ifndef BIRD_H
#define BIRD_H

#include "point.h"
#include "velocity.h"
#include "flyingobject.h"
#include "uiDraw.h"

class Bird : public FlyingObject //New
{
  private:
   bool onScreen;
   Velocity birdVelocity;
   bool kill;
  public:
   
   Bird()
   {
      position.setX(-190);//start at this x location every time
      position.setY(random(-1,2) * random(10,191)); //Random y
      Velocity randVel;
      if (position.getY() > 0)
      {
         randVel.setDy(random(-4,0)); //if upper go downward
      }
      else
      {
         randVel.setDy(random(0,5)); //if lower go upward
      }
      birdVelocity.setDx(random(3,7)); //random x total velocity
      birdVelocity.setDy(randVel.getDy()); // random y total velocity
      onScreen = true; //say its on screen
      kill = false; //say its not dead
   }
   virtual void draw() const = 0; 
   virtual void advance();
   virtual void addHit(int jazz) {onScreen = onScreen;};
   virtual int getHit() {return 0;}
   void setBirdVelX(float newSpeed) {birdVelocity.setDx(newSpeed);}
   void setBirdVelY(float newY) {birdVelocity.setDy(newY);}
   bool getAlive() const {return onScreen;}
   
   void setAlive(bool newLive) {onScreen = newLive;}
};

//Just draw the normal bird in this class
class NormalBird : public Bird
{
  public:
   virtual void draw() const;
};

//draws the tough bird, changes the velocity to specs, adds life
class ToughBird : public Bird
{
  private:
   int hitCount;
  public:
   ToughBird()
   {
      hitCount = 3;
      Velocity randVel;
      if (position.getY() > 0)
      {
         randVel.setDy(random(-3,0));
      }
      else
      {
         randVel.setDy(random(0,4));
      }
      setBirdVelX(random(2,5));
      setBirdVelY(randVel.getDy());
   }
   virtual void draw() const;
   virtual void addHit(int hit);
   virtual int getHit() {return hitCount;}
};

//Draws the sacred bird, nothing to special
class SacredBird : public Bird
{
  public:
   virtual void draw() const;
   
};

//draws the moonlander, an extra above and beyond
class MoonLander : public Bird
{
  public:
   virtual void draw() const;
};

#endif
