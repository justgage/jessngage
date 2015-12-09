/***********************************************************************
 * Header File:
 *    Bullet: My projectile fired from the gun
 * Author:
 *    David Brewerton
 * Summary:
 *    Moves through the air into birds
 ************************************************************************/
 
#include "bullet.h"
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include <iostream>

void Bullet :: fire(Velocity v)
{
   setVelocity(v);
}

void Bullet :: draw()
{
   drawDot(getPoint());
}

void Bullet :: advance()
{
   point.addX(velocity.getDx());
   point.addY(velocity.getDy());
   drawDot(getPoint());
}