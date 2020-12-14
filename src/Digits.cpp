#include "include/Digits.h"

Digits::Digits() { }

Digits::Digits(int num, int x, int y)
{
	this->inputNum = num;
	convNum();
	spacing = 16;
	dig1 = Digit(ones, x, y);
	dig2 = Digit(tens, x - spacing, y);
}

Digits::~Digits() { }

// Get the oneths and the tenth place from the input
void Digits::convNum()
{
	ones = inputNum % 10;
	tens = (inputNum % 100) / 10;
}

void Digits::setPos(int x, int y)
{
	dig1.setPos(x, y);
	dig2.setPos(x - spacing, y);
}

void Digits::setScale(int scale)
{
	dig1.setScale(scale);
	dig2.setScale(scale);
}

void Digits::setColor(g2dColor color)
{
	dig1.setColor(color);
	dig2.setColor(color);
}

void Digits::setSpacing(int space)
{
	this->spacing = space;
	setPos(dig1.getPosX(), dig1.getPosY());
}

void Digits::run(int updateNum)
{
	this->inputNum = updateNum;
	convNum();
	dig1.run(ones);
	dig2.run(tens);
}

void Digits::draw()
{
	dig1.draw();
	dig2.draw();
}

void Digits::setFade(int amount)
{
	dig1.setFade(amount);
	dig2.setFade(amount);
}

