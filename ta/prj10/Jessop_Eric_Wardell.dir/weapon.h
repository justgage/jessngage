/*************************
 * File: weapon.h
 ************************/
#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
using namespace std;
#include "point.h"
#include "uiDraw.h"
#include "bullet.h"

class Weapon
{
private:
   Point position;
   int angle;
   int ammoCount;
   
public:
   // default constructor
   Weapon()
   {
      position(200, -200);
      angle = 45;
      ammoCount = 100;
   }
   
   // non-default constructor
   Weapon(int angle, int ammoCount, bool reload)
   {
      position(200, -200);
      setAngle(angle);
      setAmmoCount(ammoCount);
   }

   // getters
   int getangle() const { return angle; }
   int getAmmoCount() const { return ammoCount; }

   // setters
   void setAngle(float angle) { this->angle = angle; }
   void setAmmoCount(int reload) { ammoCount = reload; }

   // aim method
   void addAngle(int angle);

   // aim up and down
   void aimUp() { addAngle(1); }
   void aimDown() { addAngle(-1); }
   
   // reload ammo
   void virtual Reload() { setAmmoCount(100); }

   // draw rifle method
   void virtual drawGun const() { drawRect(position, 20, 10, angle); }
   
   // shoot rifle
   void virtual shoot();

   // advance weopon on screen
   void virtual advance() { drawGun(); }
};

class Rifle : public Weapon
{
private:
   Bulllet bullet;
   
public:
Rifle
{
   ammoCount = 20;
}
   // draw rifle method
   void drawGun const() { drawRect(position, 20, 10, angle); }

   // reload ammo
   void Reload() { setAmmoCount(20); }

   // shoot rifle
   void shoot() { bullet.draw(angle) }
   
};

#endif
