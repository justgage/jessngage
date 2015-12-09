#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
  protected:
   float dx;
   float dy;
   
  public:
   //getters
   float getDx() const { return dx; }
   float getDy() const { return dy; }

   //setters
   void setDx(float newDx) { dx = newDx; }
   void setDy(float dy) { this -> dy = dy;}
   
};

#endif 
