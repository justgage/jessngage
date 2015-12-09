/***********************************************************************
 * Header File:
 *    Bird: A flying object to be shot
 * Author:
 *    David Brewerton
 * Summary:
 *    Flies until shot
 ************************************************************************/
 
#ifndef STANDARDBIRD_H
#define STANDARDBIRD_H

#include "point.h"
#include "velocity.h"
#include "bird.h"
#include <iostream>

class StandardBird : public Bird
{
public:
   virtual void draw();
   virtual int add()
   {
      return 1; 
   }
};

#endif