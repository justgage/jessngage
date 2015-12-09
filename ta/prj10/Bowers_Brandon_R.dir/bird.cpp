#include "bird.h"

	
	void NormalBird::draw() const
	{
		//hard coding 20 for the moment
		//will use randomizer in future?
		drawCircle(90, 20);
	}
	
	
	void ToughBird::draw() const
	{
		//3 will later be member variable for lives
		drawToughBird(90, 20, 3);

	}

	
	void SacredBird::draw() const
	{
		drawSacredBird(90, 20);

	}

