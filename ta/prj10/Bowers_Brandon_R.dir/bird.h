#ifndef BIRD_H
#define BIRD_H
#include "flyingObject.h"
#include "uiDraw.h"

class Bird : public FlyingObject
{
public:
	
};


class NormalBird : public Bird
{
public:
	virtual void draw() const;

};


class ToughBird : public Bird
{
public:
	virtual void draw() const;

};


class SacredBird : public Bird
{
public:
	virtual void draw() const;

};

#endif