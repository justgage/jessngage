/***********************************************************************
 * Header File:
 *    Bullet.h: Projectile
 * Author:
 *    Taylor Groom
 * Summary:
 *    Contains everything you need to know about the bullet including
 *    location, velocity, if it is in play and alive, and functions such
 *    as advance and draw. Is a type of flyingobject
 ************************************************************************/

#ifndef BULLET_H
#define BULLET_H

#include "rifle.h"
#include "velocity.h"
#include "point.h"
#include "flyingobject.h"

class Bullet : public FlyingObject
{

  private:
   bool bulletInPlay;
   bool shot;

  public:
//Default Contstuctor
   Bullet()
   {
      setBulletX(200);
      setBulletY(-200);
      velocity.setDx(0);
      velocity.setDy(0);
      bulletInPlay = false;
   }

//Getters
   float getBulletX() {return position.getX();}
   float getBulletY() {return position.getY();}
//Setters
   void setBulletX(float newX) {position.setX(newX);}
   void setBulletY(float newY) {position.setY(newY);}
//Member functions    
   virtual void draw() const;
   virtual void advance();
   
   bool fire(int angle);
   bool getBulletInPlay() { return bulletInPlay; }
   bool checkCollide(Point birdPoint);
};

#endif
