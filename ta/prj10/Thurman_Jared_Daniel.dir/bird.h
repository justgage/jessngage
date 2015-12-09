#ifndef BIRD_H
#define BIRD_H

#include "FlyingObj.h"

class Bird : public FlyingObj
{
public:
	float angle;
	float startPointY;
	bool alive;
	int hitcounter; 

	Bird()
	{
		alive = true;
		velocity.setDx(3);
		velocity.setDy(0);
		hitcounter = 3;
	}


	virtual void draw() const = 0;

	void advance();
	Velocity getVelocity();
	void birdAngle();
	bool isAlive();
	void kill();
	void hit();

	float getX() {return point.getX(); }
	float getY() {return point.getY(); }
};


class NormalBird : public Bird
{
public:
	virtual void draw() const;
};


class ToughBird : public Bird
{
public:
	virtual void draw() const;
};


class SacredBird : public Bird
{
public:
	virtual void draw() const;
};

#endif