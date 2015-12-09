/***********************************************************************
 * Header File:
 *    Bird.h : The object at which we will shoot
 * Author:
 *    Taylor Groom
 * Summary:
 *    Everything we need to know about a bird, including its velocity,
 *    position, drawing it, advcancing it, checking if it is alive
 *    the location and the bounds. also contains three offspring classes,
 *    normalBird, toughBird, and sacredBird.  Is a flyingobject
 ************************************************************************/

#ifndef BIRD_H
#define BIRD_H

#include "point.h"
#include "velocity.h"
#include "flyingobject.h"
#include "uiDraw.h"
#define MAX_SCREEN  190
#define LEAST_SCREEN  -190

class Bird : public FlyingObject
{
  protected:
  bool isAlive;
  int hitNum;  

  public:
//Default Constructor
   Bird()
   {
      hitNum = 1;
      position.setX(LEAST_SCREEN);
      position.setY(random(-1,2) * random(10,MAX_SCREEN));

      Velocity temp;
      if (position.getY() > 0)
      {
         temp.setDy(random(-5,1));
      }
      else 
      {
         temp.setDy(random(0,5));
      }
      temp.setDx(random(3,7));           
      setVelocity(temp);
   }

//Getters
   float getVelocityDx() const { return velocity.getdx(); }
   float getVelocityDy() const { return velocity.getdy(); }
   bool getIsAlive() { return isAlive; }
   int getHitNum() { return hitNum; }
//Setters
   bool setIsAlive(bool b) { isAlive = b; }
   void setVelocity(Velocity newVelocity);
   void setVelocityX(float x) { velocity.setDx(x); }
//Member Functions
   void changeHitNum(int num) { hitNum = hitNum + num; } 
   virtual void draw() const = 0;
   virtual void advance();
};

/*********************************************************
 * Normal bird - draws a circle
 *******************************************************/
class NormalBird : public Bird
{
  public:
   virtual void draw() const;
};

/**********************************************************
 * Tough bird - draws a circle with a number inside and
 * changes the velocity to be between -4 and 4 in the y
 * and 2 and 4 in the x
 ********************************************************/
class ToughBird : public Bird
{
  public:
   ToughBird()
   {
      Velocity temp;
      if (position.getY() > 0)
      {
         temp.setDy(random(-4,1));
      }
      else 
      {
         temp.setDy(random(0,4));
      }
      temp.setDx(random(2,5));
      setVelocity(temp);
   }
   virtual void draw() const;
   
};

/*************************************************************
 *   Sacred bird - draws a red star
 ************************************************************/
class SacredBird : public Bird
{
  public:
   virtual void draw() const;
   
};

/************************************************************
 *    Moonlander - draws the moonlander
 **********************************************************/
class MoonLander : public Bird
{
  public:
   virtual void draw() const;
   MoonLander()
   {
      Velocity temp;
      if (position.getY() > 0)
      {
         temp.setDy(random(-8,1));
      }
      else
      {
         temp.setDy(random(0,9));
      }
      temp.setDx(random(4,9));
      setVelocity(temp);
   }
};

#endif
