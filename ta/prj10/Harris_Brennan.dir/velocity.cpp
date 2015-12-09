//
//  velocity.cpp
//  moonLander
//
//  Created by Brennan Harris on 10/28/15.
//  Copyright © 2015 Brennan Harris. All rights reserved.
//

#include <stdio.h>
#include "velocity.h"

Velocity :: Velocity()
{
    dx = 0;
    dy = 0;
};

Velocity :: Velocity(float dxIn, float dyIn)
{
    dx = dxIn;
    dy = dyIn;
};

float Velocity :: getDx()
{
    return dx;
};

void Velocity :: setDx(float dxIn)
{
    dx = dxIn;
};

float Velocity :: getDy()
{
    return dy;
};

void Velocity :: setDy(float dyIn)
{
    dy = dyIn;
};

Velocity Velocity :: add(Velocity velIn)
{
    velIn.dx += dx;
    velIn.dy += dy;
    return velIn;
};

void Velocity :: addOnto(Velocity velIn)
{
    dx += velIn.dx;
    dy += velIn.dy;
};

void Velocity :: addOnto(float dxIn, float dyIn)
{
    dx += dxIn;
    dy += dyIn;
};