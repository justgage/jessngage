/***********************************************************************
 * Header File:
 *    Velocity: A class of how fast things move
 * Author:
 *    David Brewerton
 * Summary:
 *    Defines physics in the game
 ************************************************************************/

 #include "velocity.h"
 
 void Velocity:: add(Velocity other)
 {
    dx += other.dx;
    dy += other.dy;
 }