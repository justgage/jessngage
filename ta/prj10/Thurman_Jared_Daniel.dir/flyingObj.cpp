#include <iostream>

#include "FlyingObj.h"

Point FlyingObj::getPoint() const
{
	return point;
}

Velocity FlyingObj::getVelocity()
{
	return Velocity();
}

