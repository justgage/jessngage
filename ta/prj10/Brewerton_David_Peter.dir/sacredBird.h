/***********************************************************************
 * Header File:
 *    Bird: A flying object to be shot
 * Author:
 *    David Brewerton
 * Summary:
 *    Flies until shot
 ************************************************************************/
 
#ifndef SACREDBIRD_H
#define SACREDBIRD_H

#include "point.h"
#include "velocity.h"
#include "bird.h"
#include <iostream>

class SacredBird: public Bird
{
public:
   virtual void draw();
   virtual int add()
   {
      return -10;
   }
};

#endif