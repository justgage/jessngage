#ifndef RIFLE_H
#define RIFLE_H

#include "Velocity.h"
#include "point.h"

class Rifle
{
private:
	Point point;
	Velocity velocity;


        int angle;
public:

	Rifle() : point(198, -198)
	{

	}

	int getAngle() { return angle; }
	void setAngle(int angle) { this->angle = angle; }
	
	void draw() const;
	void rotateUp();
	void rotateDown();


};

#endif
