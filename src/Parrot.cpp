#include "include/Parrot.h"

Parrot::Parrot() : Sprite("./data/characters.png", 210, 12)
{
	Sprite::setCrop(0, 0, 128, 153);
	Sprite::setScale(0.5);
	Sprite::setFramesX(2);
}

Parrot::~Parrot() { }

void Parrot::run(State &st, Score &score)
{
	move(score.getCurrScore()); // score increases the speed

	// animate
	if (st.getCounter() % 12 == 10) // 4 frames per second
		Sprite::cycleFrameX();

}

void Parrot::draw()
{
	Sprite::draw();
}

int Parrot::getPosX()
{
	return Sprite::getPosX();
}

int Parrot::getPosY()
{
	return Sprite::getPosY();
}

void Parrot::move(int speed)
{
	Sprite::pingPong(0, 456, 2 + speed);
	Sprite::setScale(0.5 *Sprite::getDirection(), 0.5); // change direction
}



