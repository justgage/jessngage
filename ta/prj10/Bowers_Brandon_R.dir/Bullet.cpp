#include "Bullet.h"
#include "uiDraw.h"
#include "Rifle.h"
#include <cmath>


void Bullet::drawBullet()
{
	drawDot(point);

}



void Bullet::advance()
{
	const float BULLET_SPEED = 10.0;
	//default angle set to 50. 
	//angle from rifle is needed.
	float angle = 50.0;

	float dx = BULLET_SPEED * (-cos(3.1459 / 180.0 * angle));
	float dy = BULLET_SPEED * (sin(3.1459 / 180.0 * angle));

	point.addX(dx);
	point.addY(dy);

}