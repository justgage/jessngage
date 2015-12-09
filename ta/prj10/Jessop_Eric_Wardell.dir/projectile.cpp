/*************************
 * File: projectile.cpp
 ************************/
#include <cmath>	
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "projectile.h"

	// angle to velocity method
	void Projectile :: angleToVelocity(int angle)
   {
   	velocity.setDX(speed * -cos(M_PI / 180 * angle));
   	velocity.setDY(speed * sin(M_PI / 180 * angle));
   }

   void Projectile :: advance(int angle)
   { 
   	angleToVelocity(angle);
   	position(position.getX() + velocity.getDX(), position.getY() + velocity.getDY()); 
   }