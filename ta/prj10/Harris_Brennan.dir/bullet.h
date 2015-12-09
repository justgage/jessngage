//
//  bullet.hpp
//  skeet
//
//  Created by Brennan Harris on 11/6/15.
//  Copyright © 2015 Brennan Harris. All rights reserved.
//

#ifndef bullet_hpp
#define bullet_hpp

#include <stdio.h>
#include <stdlib.h>
#include "flyingObject.h"

class Bullet : public FlyingObject
{
public:
    Bullet(Velocity);
    void draw();
};
#endif /* bullet_h */
