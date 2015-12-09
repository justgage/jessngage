#ifndef FLYING_OBJECT_H
#define FLYING_OBJECT_H

#include "point.h"
#include "flyingObject.h"
#include "Velocity.h"
class FlyingObject
{
private:
	Point position;
	Velocity velocity;

public:
	Point getPosition() const { return position; }
	void setPosition(Point p) { position = p; }


	Velocity getVelocity() const { return velocity; }
	void setVelocity(Velocity velocity) { this->velocity = velocity; }

	void advance();

	virtual void draw() const = 0;

};

#endif