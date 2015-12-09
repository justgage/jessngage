/***********************************************************************
 * Header File:
 *    Bullet : The bullet class
 * Author:
 *    Allen Foster
 * Summary:
 *    Everything we need to know about how the bullet functions in the game
 ************************************************************************/


#ifndef BULLET_H
#define BULLET_H

#include <iostream>

/*********************************************
 * BULLET
 *********************************************/

class Bullet
{
public:
    Bullet();
    void draw();
    void handleInput();
    void show();
  
private:
    int velocity;
};

#endif // BULLET_H
