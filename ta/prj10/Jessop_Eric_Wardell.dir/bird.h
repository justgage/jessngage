/*************************
 * File: bird.h
 ************************/
#ifndef BIRD_H
#define BIRD_H

#include "flyingobject.h"
#include "uiDraw.h"

class Bird : public FlyingObject
{
  private:
   float size;
   float hitPoints;
   int scorePoint;
   int bonusPoint;
   
  public:
   Bird()
   {
      setSpeed(5);
      setPosition(getRanPosition());
      setBonusPoint(0);
   }
   
   // getters and setters
   float getSize() const { return size; }
   float getHitPoints() const { return hitPoints; }
   int getScorePoint() const { return scorePoint; }
   int getBonusPoint() const { return bonusPoint; }
   void setSize(float size) { this->size = size; }
   void setHitPoints(float hitPoints) { this->hitPoints = hitPoints; }
   void setScorePoint(int scorePoint) { this->scorePoint = scorePoint; }
   void setBonusPoint(int bonusPoint) { this->bonusPoint = bonusPoint; }

   // random position on the left side of screen
   Point getRanPosition() const;

   // random velocity downward if higher position or angle up if lower
   int getRanAngle() const;

   // draw bird method
   virtual void draw() const = 0;

   // hit points calculator
   void takeHit(int hit) { setHitPoints(getHitPoints() + hit); }

   // getting farther effect
   void goFar() { size = size / 1.009; }
   
   virtual void advance()
   {
      if (isOnScreen())
      {
         position.addX(velocity.getDX());
         velocity.addDY(-0.01);
         position.addY(velocity.getDY());
      }
      goFar();
   }
};

class NormalBird : public Bird
{
  public:	
   NormalBird()
   {
      setSize(15);
      setSpeed(5);
      angleToVelocity(getRanAngle());
      setHitPoints(1);
      setScorePoint(1);
   }
   virtual void draw() const { drawCircle(getPosition(), getSize()); }
};

class ToughBird : public Bird
{
  public:	
   ToughBird()
   {
      setSize(15);
      setSpeed(3);
      angleToVelocity(getRanAngle());
      setHitPoints(3);
      setScorePoint(1);
      setBonusPoint(2);
   }
   virtual void draw() const
   { drawToughBird(getPosition(), getSize(), getHitPoints()); }
};

class SacredBird : public Bird
{
  public:	
   SacredBird()
   {
      setSize(15);
      setSpeed(6);
      angleToVelocity(getRanAngle());
      setHitPoints(1);
      setScorePoint(-10);
   }
   virtual void draw() const { drawSacredBird(getPosition(), getSize()); }
};

class TinyBird : public Bird
{
  public:	
   TinyBird()
   {
      setSize(5);
      setSpeed(6);
      angleToVelocity(getRanAngle());
      setHitPoints(1);
      setScorePoint(2);
      setBonusPoint(2);
   }
   virtual void draw() const { drawToughBird(getPosition(), getSize(), 0); }
};

class BigBird : public Bird 
{
  public:	
   BigBird()
   {
      setSize(25);
      setSpeed(5);
      angleToVelocity(getRanAngle());
      setHitPoints(2);
      setScorePoint(0);
      setBonusPoint(3);
   }
   virtual void draw() const
   { drawRect(getPosition(), getSize(), getSize(), getRanAngle()); }
};

class BossBird : public Bird
{
  public:	
   BossBird()
   {
      setSize(20);
      setSpeed(5);
      angleToVelocity(getRanAngle());
      setHitPoints(5);
      setScorePoint(1);
      setBonusPoint(5);
   }
   virtual void draw() const
   { drawMediumAsteroid(getPosition(), getRanAngle());
     drawToughBird(getPosition(), getSize(), getHitPoints()); }
};

#endif
