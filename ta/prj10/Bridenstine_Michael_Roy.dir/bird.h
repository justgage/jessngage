#ifndef BIRD_H
#define BIRD_H
#include "flyingObject.h"

class Bird : public flyingObject
{
  protected:
   int pointValue;
   bool life;
   float radius;
   
  public:
   virtual int gotHit() = 0;
   virtual void draw() = 0;
  
  float getRadius() {return radius;}
  void setRadius(float radius) {this->radius = radius;}
  
  int getPointValue() {return pointValue;}
  void setPointValue(int value) {pointValue = value;}

  bool getLife(){ return life;}
  void setLife(bool status) {life = status;}
};


class normalBird : public Bird
{
  public:
   normalBird()
   {
      pointValue = 1;
      life = true;
      radius = 20;
   }
   normalBird(bool empty)
   {
      pointValue = 0;
      life = false;
      radius = 0;
   }
   int gotHit();
   void draw();
};

class toughBird : public Bird
{
  private:
   int hits;

  public:
   toughBird()
   {
      pointValue = 1;
      life = true;
      radius = 20;
      hits = 3;
   }
   int gotHit();
   void draw();
};

class eagleBird : public Bird
{
  public:
   eagleBird()
   {
      pointValue = -10;
      life = true;
      radius = 20;
   }
   int gotHit();
   void draw();
};

#endif
