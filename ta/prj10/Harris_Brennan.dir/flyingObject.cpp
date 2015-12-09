//
//  flyingObject.cpp
//  skeet
//
//  Created by Brennan Harris on 11/6/15.
//  Copyright © 2015 Brennan Harris. All rights reserved.
//

#include "flyingObject.h"

void FlyingObject :: advance()
{
    location.addX(velocity.getDx());
    location.addY(velocity.getDy());
}