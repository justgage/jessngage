#include "flyingObject.h"


void FlyingObject::advance()
{
	//factor in velocity

    //delete the 1 when velocity is added
	position.addX(1);
	position.addY(1);
}
