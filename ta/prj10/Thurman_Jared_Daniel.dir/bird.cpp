#include "bird.h"
#include "uiDraw.h"


/***************************************
* NORMALBIRD
* Draws normal bird.
***************************************/
void NormalBird::draw() const
{
	drawCircle(point, 20);
}

/***************************************
* ToughBird
*  Draws Tough Bird
***************************************/
void ToughBird::draw() const
{
	drawToughBird(point, 20, hitcounter);
}

/***************************************
* SacreBird
* Draws Sacred bird
***************************************/
void SacredBird::draw() const
{
	drawSacredBird(point, 20);
}

/***************************************
* Getvelocity
* Gets velocity for bird
***************************************/
Velocity Bird::getVelocity()
{
	return Velocity();
}

/***************************************
* Advance
* advance the bird. 
***************************************/
void Bird::advance() 
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy() + angle);

	if (point.getX() >= 220 || point.getY() >= 220 
		|| point.getY() <= -220)
	{
		kill();
	}
}

/***************************************
* BirdAngle
* This makes randomly chooses and angle
* depending were it spawns.
***************************************/
void Bird::birdAngle()
{
	std::cout << startPointY;
	if (getStart() >= 0)
	{
		angle = random (-4, 0);
	}
	else if (getStart() <= -1)
	{
		angle = random (0, 4);
	}
}

/***************************************
* isAlive
* Tells if the bird is alive or not
***************************************/
bool Bird::isAlive()
{
	return alive;
}

/***************************************
* Kill
* kills the bird
***************************************/
void Bird::kill()
{
	point.setX(-250);
	point.setY(0);
	alive = false;
}

void Bird::hit()
{ 
	hitcounter -= 1;
}