//
//  bullet.cpp
//  skeet
//
//  Created by Brennan Harris on 11/6/15.
//  Copyright © 2015 Brennan Harris. All rights reserved.
//

#include "bullet.h"
Bullet :: Bullet(Velocity velocity)
{
    setLocation(Point(200,-200));
    setVelocity(velocity);
    setLife(true);
}

void Bullet :: draw()
{
    drawDot(getLocation());
}