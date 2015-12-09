#ifndef VELOCITY_H
#define VELOCITY_H

#include <iostream>

/******************************************
* CLASS VELOCITY
* This class makes velocity
******************************************/
class Velocity
{
private:
	float dx;
	float dy;
	
public:
	float getDx() const { return dx; }
	float getDy() const { return dy; }

	void setDx(float newDx) { dx = newDx; }
	void setDy(float dy) { this->dy = dy; }

};


#endif //VELOCITY_H