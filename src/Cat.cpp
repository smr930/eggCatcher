#include "include/Cat.h"

Cat::Cat() : Sprite("./data/characters.png", 208, 210)
{
	Sprite::setCrop(0, 153, 88, 103);
	Sprite::setScale(0.5);
	Sprite::setFramesX(2);

	shadow = Sprite("./data/characters.png", 208, 250);
	shadow.setCrop(176, 228, 80, 28);
	shadow.setScale(0.5);
	shadow.setAlpha(128);

	miss = Sprite("./data/characters.png", 208, 200);
	miss.setCrop(178, 217, 40, 11);
	miss.setScale(1);
	miss.setAlpha(255);
	missToggle = false;
}

Cat::~Cat() { }

void Cat::run()
{

}

void Cat::draw()
{
	shadow.draw();
	Sprite::draw();
}

int Cat::getPosX()
{
	return Sprite::getPosX();
}

int Cat::getPosY()
{
	return Sprite::getPosY();
}

void Cat::react()
{
	Sprite::setColor(GREEN);
	Sprite::draw();
	Sprite::setColor(WHITE);
}

void Cat::move(State &st, int speed)
{
	// move right
	if (speed > 0)
	{
		// don't let the cat go off-screen
		if(Sprite::getPosX() > 480)
		{
			Sprite::setPosX(0);
			shadow.setPosX(0);
		}
		else
		{
			int currPos = Sprite::getPosX();
			currPos += speed;
			Sprite::setPosX(currPos);
			shadow.setPosX(currPos);

			// animate
			if (st.getCounter() % 12 == 10) // 4 frames per second
				Sprite::cycleFrameX();
		}
	}

	// move left
	else if (speed < 0)
	{
		// don't let the cat go off-screen
		if(Sprite::getPosX() < -10)
		{
			Sprite::setPosX(480);
			shadow.setPosX(480);
		}
		else
		{
			int currPos = Sprite::getPosX();
			currPos += speed;
			Sprite::setPosX(currPos);
			shadow.setPosX(currPos);

			// animate
			if (st.getCounter() % 12 == 10) // 4 frames per second
				Sprite::cycleFrameX();
		}
	}
}

bool Cat::getMissToggle()
{
	return missToggle;
}

void Cat::initMiss()
{
	miss.setPosX(Sprite::getPosX());
	miss.setAlpha(255);
	missToggle = true;
}

void Cat::displayMiss()
{
	if (missToggle)
	{
		miss.setPosX(Sprite::getPosX());
		miss.setColor(RED);
		miss.rotateTo(-10,20);
		miss.draw();
		miss.setFade(-10);
	}
}
