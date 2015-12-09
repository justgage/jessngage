#ifndef RIFLE_H
#define RIFLE_H

class Rifle
{
  private:
   int angle;
   int width;
   int height;
   
  public:
   Rifle()
   {
      width = 10;
      height = 80;
      angle = 45;
   }
   int getAngle() {return angle;}
   int getWidth() {return width;}
   int getHeight() {return height;}

   void setWidth(int Width) {width = Width;}
   void setHeight(int Height) {width = Height;}
   void setAngle(int Angle)
   {
      if(Angle < 0)
         angle = 0;
      else if(Angle > 90)
         angle = 90;
      else
         angle = Angle;
   }
   
   void rotateLeft()
   {
      angle = angle + 3;

      if(angle > 90)
         angle = 90;
      else if(angle < 0)
         angle = 0;
   }

     void rotateRight()
   {
      angle = angle - 3;

      if(angle > 90)
         angle = 90;
      else if(angle < 0)
         angle = 0;
   }
   
   void drawRifle(Point position)
   {
   drawRect(position, width, height, angle);
   }


};
#endif
