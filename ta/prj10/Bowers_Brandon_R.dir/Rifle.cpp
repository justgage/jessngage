#include "Rifle.h"
#include "uiDraw.h"

void Rifle::draw() const
{
	drawRect(point, 10, 40, angle);
	
}

void Rifle::rotateUp()
{
	angle += 3;

}

void Rifle::rotateDown()
{
	angle -= 3;

}