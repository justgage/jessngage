#ifndef FLYINGOBJ_H
#define FLYINGOBJ_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class FlyingObj
{
protected:
	Point point;
	Velocity velocity;
	float startPointY;

public:
	FlyingObj()
	{
		startPointY = random(-50, 50);
		point.setX(-210);
		point.setY(startPointY);

	}

	Point getPoint() const;
	Velocity getVelocity();
	float getStart() const { return startPointY; }
	virtual void draw() const = 0;

};


#endif
