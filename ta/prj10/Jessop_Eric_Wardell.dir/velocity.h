/*************************
 * File: velocity.h
 ************************/
#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
private:
   float dX;
   float dY;

public:
   // default constructor
   Velocity()
   {
      dX = 0.0;
      dY = 0.0;
   }
   //non-default destructor
   Velocity(float dX, float dY)
   {
      setDX(dX);
      setDY(dY);
   }

   // getters
   float getDX() const { return dX; }
   float getDY() const { return dY; }

   // setters
   void setDX(float dX) { this->dX = dX; }
   void setDY(float dY) { this->dY = dY; }

   // add velocity methods
   void addDX(float dX) { setDX(getDX() + dX); }
   void addDY(float dY) { setDY(getDY() + dY); }

  
};

#endif
