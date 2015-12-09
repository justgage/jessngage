#ifndef SHOT_H
#define SHOT_H
#include "flyingObject.h"

class Shot : public flyingObject
{
  private:
   bool life;
   
  public:
   Shot()
   {
      life = true;
      Point pos(200,-200);
      setVelocity(0,0);
      setPosition(pos);
   }
     
   void drawShot()
   {
      if(life)
         drawDot(getPosition());
   }
   
   bool getLife() {return life;}
   void endShot()
   {
      life = false;
   }
   
};

#endif
