#include "flyingobject.h"
#include <cmath>

void FlyingObject::advance()
{
   //TODO: factor in velocity
   dx = (double) (rifle.cos(angle) * +/-4);
   dy = (double) (rifle.sin(angle) * +/-4);            

   rifle.x += dx;
   rifle.y += dy;
   
   4 * (bird.velocityX * (bird.startX - rifle.X)
      + bird.velocityY * (bird.startY - rifle.Y))
}
   
}
