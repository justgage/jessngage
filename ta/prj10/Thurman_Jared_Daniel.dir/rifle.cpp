
#include "rifle.h"
#include "uiDraw.h"

/***************************************
* Rifle:: DRAW
* Draws the rifle
***************************************/
void Rifle::draw()
{
	drawRect(point, 50, 5, angle);
}

/***************************************
* Rifle::ANGLEPOS
* determins the positive angle of the rifle
***************************************/
float Rifle::anglePos()
{
	if (180 && angle < 180)
	{
		angle += 3;
	}
	return angle;
}

/***************************************
* Rifle::ANGLENEG
* determins the negitive angle of the rifle
***************************************/
float Rifle::angleNeg()
{
	if (90 && angle > 90)
	return angle -= 3;		
}



float Rifle::getAngle()
{
	return angle;
}
