#include "include/Digit.h"
//#include <stdio.h>

Digit::Digit() { }

Digit::Digit(int num, int posX, int posY) : Sprite("./data/digits.png", posX, posY)
{
	this->num = num;
	sWidth = 128;
	sHeight = 16;

	Sprite::setCrop(0, 0, 15, 16);
	Sprite::setScale(1);
}

Digit::~Digit() { }

void Digit::setPos(int posX, int posY)
{
	Sprite::setPos(posX, posY);
}

void Digit::setScale(int scale)
{
	Sprite::setScale(scale);
}

void Digit::setSpriteWH(int w, int h)
{
	sWidth = w;
	sHeight = h;
}

void Digit::setColor(g2dColor color)
{
	Sprite::setColor(color);
}

void Digit::run(int updateNum)
{
	//printf("Digit.num = %d\n", num);
	this->num = updateNum;
	switch (num)
	{
	case 0:
		Sprite::setCrop(0, 0, 15, sHeight);
		break;
	case 1:
		Sprite::setCrop(15, 0, 8, sHeight);
		break;
	case 2:
		Sprite::setCrop(23, 0, 13, sHeight);
		break;
	case 3:
		Sprite::setCrop(36, 0, 13, sHeight);
		break;
	case 4:
		Sprite::setCrop(49, 0, 13, sHeight);
		break;
	case 5:
		Sprite::setCrop(62, 0, 13, sHeight);
		break;
	case 6:
		Sprite::setCrop(75, 0, 14, sHeight);
		break;
	case 7:
		Sprite::setCrop(89, 0, 13, sHeight);
		break;
	case 8:
		Sprite::setCrop(102, 0, 13, sHeight);
		break;
	case 9:
		Sprite::setCrop(115, 0, 13, sHeight);
		break;
	}
}


void Digit::draw()
{
	Sprite::draw();
}

