#ifndef BULLET_H
#define BULLET_H

#include "Velocity.h"
#include "point.h"
#include "Rifle.h"
class Bullet
{
private:
	Point point;
	Velocity velocity;
	Rifle angle;
public:
	Bullet() : point(198, -198)
	{


	}

	void drawBullet();

	void advance();

};

#endif