#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include "FlyingObj.h"


class Bullet 
{
private:
	Point point;
	Velocity velocity;
	bool alive;
	float x;
	float y; 

public:
	Bullet()
	{
	alive = false;

	point.setX(198);
	point.setY(-198);
	
	velocity.setDx(0);
	velocity.setDy(0);

	}

	Point getPoint() const;
	Velocity getVelocity();

	float getX() { return point.getX(); }
	float getY() { return point.getY(); }


	void drawBullet();
	void fire(float angle);
	bool isAlive();
	void kill();
	void advance();


};

#endif