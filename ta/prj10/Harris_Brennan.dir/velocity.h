//
//  velocity.h
//  moonLander
//
//  Created by Brennan Harris on 10/26/15.
//  Copyright © 2015 Brennan Harris. All rights reserved.
//

#ifndef velocity_h
#define velocity_h
class Velocity
{
private:
    float dx;
    float dy;
public:
    Velocity();
    Velocity(float,float);
    float getDx();
    void setDx(float);
    float getDy();
    void setDy(float);
    Velocity add(Velocity);
    void addOnto(Velocity);
    void addOnto(float,float);
};

#endif /* velocity_h */
