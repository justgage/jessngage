#ifndef VELOCITY_H
#define VELOCITY_H


class Velocity
{
private:
	float dx;
	float dy;

public:


	float getdx() const { return dx; }
	float getdy() const { return dy; }
	void setdx(float newdx) { dx = newdx; }
	void setdy(float dy) { this->dy = dy; }

	
};

#endif