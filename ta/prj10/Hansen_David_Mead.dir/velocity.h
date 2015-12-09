//Velocity Class

#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
  private:
   float dx;
   float dy;

  public:
   float getDX() { return dx; }
   float getDY() { return dy; }

   void setDX(float newDX) { dx = newDX; }
   void setDY(float newDY) { dy = newDY; }

   void addDX(float dX) { dx += dX; }
   void addDY(float dY) { dy += dY; }
   
   Velocity()
   {
      setDX(0);
      setDY(0);
   }

   Velocity(int x, int y)
   {
      setDX(x);
      setDY(y);
   }
   
};

#endif
