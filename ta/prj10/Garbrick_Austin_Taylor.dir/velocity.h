#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
  private:
   float deltaX;
   float deltaY;


  public:
   Velocity()
   {
      deltaX = 0;
      deltaY = 0;
   }
   Velocity(float deltaX, float deltaY)
   {
      this-> deltaX = deltaX;
      this-> deltaY = deltaY;
   }
   
   float getDeltaX(){return deltaX;}
   float getDeltaY(){return deltaY;}

   void setDeltaX(float deltaX) {this-> deltaX = deltaX;}
   void setDeltaY(float deltaY) {this-> deltaY = deltaY;}




   
   
};
#endif 
