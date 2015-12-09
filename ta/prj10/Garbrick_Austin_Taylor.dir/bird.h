#ifndef BIRD_H
#define BIRD_H

#include "bullet.h"
#include <cmath>
#include "uiDraw.h"

#define RADIUS 15

class Bird : public Moveable
{
  protected:
   int life;
   int pointValue;
   

  public:
   Bird()
   {
      life = 1;
      pointValue = 1;
      //p = Point(100,10);
      //v = Velocity(0,0);
      generateBirdVectors();
   }
   Bird(Point p, Velocity v)
   {
      this-> p = p;
      this-> v = v;
      life = 1;
      pointValue = 1;
   }

   int getLife() {return life;}
   int getPointValue() { return pointValue;}
   
   virtual void draw()
   {
      drawCircle(p,RADIUS);
   }

   float getRadius() { return RADIUS;}
   virtual int hurtBird()
   {
      life --;
      return pointValue;
   }
   virtual void generateBirdVectors()
   {
      int x = -200;
      int y = random(-150,150);
     this->p = Point(x,y);

      float dx;
      float dy;

      int yNum = random(0,4000);
      dy = (float)yNum / 1000.0;
      
      if (y > 0) // make it go downward. 
      {
         dy *= -1.0;
       
      }

      int xNum = random(3000, 6000);
      dx = (float)xNum / 1000.0;

      this->v = Velocity(dx, dy);
   }
   void update()
   {
      Moveable:: update();
      v.setDeltaY(v.getDeltaY() - 0.05);
   }
   
};


class StrongBird : public Bird
{
  public:
   StrongBird()
   {
      life = 3;
      generateBirdVectors();
   }
   StrongBird(Point p, Velocity v)
   {
      this-> p = p;
      this-> v = v;
      life = 3;
      // pointValue = 3 + 2;
   }

   virtual void draw()
   {
      drawToughBird(p, RADIUS, life);
   }

   int hurtBird()
   {
      if (life > 1)
      {
         life--;
         return 1;
      }
      else
      {
         life--;
         return 3;
      }

   }
   
   void generateBirdVectors()
   {
      int x = -200;
      int y = random(-150,150);
     this->p = Point(x,y);

      float dx;
      float dy;

      int yNum = random(0,3000);
      dy = (float)yNum / 1000.0;
      
      if (y > 0) // make it go downward. 
      {
         dy *= -1.0;
       
      }

      int xNum = random(2000, 4000);
      dx = (float)xNum / 1000.0;

      this->v = Velocity(dx, dy);
   }
   
  
};

class SacredBird : public Bird
{
  public:
   SacredBird()
   {
      life = 1;
      pointValue = -10;
   }
   SacredBird(Point p, Velocity v)
   {
      this-> p = p;
      this-> v = v;
      life = 1;
      pointValue = -10;
   }
      
   virtual void draw()
   {
      drawSacredBird(p, RADIUS);
   }
   
};



#endif

