#ifndef RIFLE_H
#define RIFEL_H

#include "point.h"

class Rifle
{
private:
	Point point;
	float angle;

public:
	Rifle()
	{
		angle = 135.0;

		point.setX(200);
		point.setY(-200);
		
	}

	void draw();
	float anglePos();
	float angleNeg();
	float getAngle();
	

};

#endif