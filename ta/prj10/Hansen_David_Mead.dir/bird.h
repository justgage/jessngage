// Bird objects class

#ifndef BIRD_H
#define BIRD_H

#include "velocity.h"
#include "point.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "bullet.h"

class Bird
{
  public:
   Velocity speed;
   Point middle;
   float radius;
   bool dead;
   int hits;
   Point start;
   
  Bird() : speed(0,0), middle(-220,random(-180,180)), radius(20), dead(true),
      start(middle), hits(3) {}
   
   Velocity getSpeed() const {return speed;}
   void setSpeed(Velocity newSpeed) { speed = newSpeed; }

   Point getMiddle() const { return middle; }
   void setMiddle(Point newMiddle) {middle = newMiddle; }

   int getMiddleX() const {return middle.getX();}
   int getMiddleY() const {return middle.getY();}

   void moveMiddleX(float move);
   void moveMiddleY(float move);
   
   virtual void draw() = 0;
   virtual int hit(Bullet bullet) = 0;
   virtual void move();

   bool isDead() const {return this->dead;}
   void setIsDead(int state) {dead = state;}
   
   int getType();
   int getHits() { return hits; }
   void reset() { middle.setX(-200); middle.setY(0);}
   void minusHits() { hits--; }
};

class NormalBird : public Bird
{
  public:
   virtual void draw();
   virtual int hit(Bullet bullet);
};

class ToughBird : public Bird
{
  public:
   
   virtual void draw();
   virtual int hit(Bullet bullet);
   virtual void move();
};

class SacredBird : public Bird
{
  public:   
   virtual void draw();
   virtual int hit(Bullet bullet);
   
};

#endif
