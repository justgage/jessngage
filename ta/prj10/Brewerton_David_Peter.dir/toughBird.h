/***********************************************************************
 * Header File:
 *    Bird: A flying object to be shot
 * Author:
 *    David Brewerton
 * Summary:
 *    Flies until shot
 ************************************************************************/
 
#ifndef TOUGHBIRD_H
#define TOUGHBIRD_H

#include "point.h"
#include "velocity.h"
#include "bird.h"
#include <iostream>

class ToughBird : public Bird
{
public:
   virtual void draw();
   virtual int add()
   {
      return 3;
   }
};

#endif