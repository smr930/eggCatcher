#include "include/Egg.h"

Egg::Egg() { }

Egg::Egg(Parrot parrot, int x, int y) : Sprite("./data/characters.png", x, y)
{
	Sprite::setCrop(176, 153, 64, 64);
	Sprite::setPos(x, y);
	Sprite::setScale(0.25);
	eggPosY = parrot.getPosY() + 52;

	miss = Sprite("./data/characters.png", x, 240);
	miss.setCrop(244, 153, 8, 29);
	miss.setScale(1);
	miss.setAlpha(255);
	missToggle = false;
}

Egg::~Egg() { }

void Egg::run()
{

}

int Egg::getEggPosY()
{
	return eggPosY;
}

bool Egg::getCollision(Cat &cat)
{
	return (Sprite::getPosX() > cat.getPosX() - 10 &&					// right edge
			Sprite::getPosX() < cat.getPosX() + cat.getScaleX() && 		// left edge
			Sprite::getPosY() > cat.getPosY()							// top edge
			);
}

void Egg::draw()
{
	Sprite::draw();
}

void Egg::drop(Parrot &parrot, Score &score)
{
	eggPosY++;
	eggPosY += score.getCurrScore() / 3;
	Sprite::setPosY(eggPosY);
}

void Egg::returnEgg(Parrot &parrot)
{
	eggPosY = parrot.getPosY() + 52;
	Sprite::setPosY(parrot.getPosY() + 52);
	Sprite::setPosX(parrot.getPosX());
}

bool Egg::getMissToggle()
{
	return missToggle;
}

void Egg::initMiss()
{
	miss.setPosX(Sprite::getPosX());
	miss.setAlpha(255);
	missToggle = true;
	currEggPosX1 = Sprite::getPosX() - 4;
	currEggPosX2 = Sprite::getPosX() + 8;

}

void Egg::displayMiss()
{
	if (missToggle)
	{
		miss.setPosX(currEggPosX1);
		miss.draw();
		miss.setPosX(currEggPosX2);
		miss.draw();
		miss.setFade(-10);
	}
}
