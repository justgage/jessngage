#include <iostream>


#include "bullet.h"
#include "point.h"
#include "uiDraw.h"

/***************************************
* Bullet :: GETVELOCITY
* returns bullets velocity
***************************************/
Velocity Bullet::getVelocity()
{
	return Velocity();
}

/***************************************
* Bullet :: DRAW
* draws bullet
***************************************/
void Bullet::drawBullet()
{
	drawDot(point);
}

/***************************************
* Bullet :: ADVANCE
* Advances the bullet
***************************************/
void Bullet::advance()
{
	point.addX(velocity.getDx() + x);
	point.addY(velocity.getDy() + y);

	if (point.getX() <= -200 || point.getY() >= 200)
	{
		kill();
	}

	//Hit detection?

}

/***************************************
* Bullet :: FIRE
* Fires the bullet at the right angle 
* and velocity
***************************************/
void Bullet::fire(float angle)
{
	alive = true;

	float newDy = velocity.getDy();
	velocity.setDy(newDy);
	float newDx = velocity.getDx();
	velocity.setDx(newDx);

	x = 10 * cos(angle * 3.14159265 / 180);
	y = 10 * sin(angle * 3.14159265 / 180);
}

/***************************************
* Bullet :: GETPOINT
* Gets bullets piont
***************************************/
Point Bullet::getPoint() const
{
	return point;
}

/***************************************
* Bullet :: ISALIVE
* Determins if alive
***************************************/
bool Bullet::isAlive()
{
	return alive;
}

/***************************************
* Bullet :: Kill
* Will kill the bullet
***************************************/
void Bullet::kill()
{
	alive = false;
}