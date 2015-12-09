/***********************************************************************
 * Header File:
 *    Rifle : The rifle class
 * Author:
 *    Allen Foster
 * Summary:
 *    Everything we need to know about how the rifle functions in the game
 ************************************************************************/


#ifndef RIFLE_H
#define RIFLE_H
#include "point.h"

#include <iostream>

/*********************************************
 * RIFLE
 *********************************************/
class Rifle
{
public:
   void draw() const;
   int getPoint() {return point;}
   void setPoint(int point = Point.point);
   int getAngle() {return angle;}
   void setAngle(int angle);
	
private:
  Point point;
  int angle;
  
};

#endif // RIFLE_H
