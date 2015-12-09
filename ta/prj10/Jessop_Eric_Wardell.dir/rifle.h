/*************************
 * File: rifle.h
 ************************/
#ifndef RIFLE_H
#define RIFLE_H

#include "point.h"
#include "uiDraw.h"
#include "bullet.h"

class Rifle
{
  private:
   Point position;
   int angle;
   Bullet bullet;
   int ammoCount;
   
  public:
   Rifle()
   {
      setPosition(200, -200);
      angle = 135;
      ammoCount = 20;
   }

   // non-default constructor
   Rifle(int angle, int ammoCount, bool reload)
   {
      setPosition(200, -200);
      setAngle(angle);
      setAmmoCount(ammoCount);
   }
   
   // getters
   Point getPosition() const { return position; }
   int getAngle() const { return angle; }
   int getAmmoCount() const { return ammoCount; }

   // setters
   void setPosition(float x, float y) { position.setX(x); position.setY(y); }
   void setAngle(float angle) { this->angle = angle; }
   void setAmmoCount(int reload) { ammoCount = reload; }

   // draw rifle method
   void draw() const { drawRect(position, 60, 6, angle); }

   // aim up and down
   void aimUp();
   void aimDown();
   
   // reload ammo
   void reload() { setAmmoCount(20); }

   // shoot rifle
   void shoot(Bullet &bullet);

   // laser sight
   void drawLaserSight() const;
};

#endif
