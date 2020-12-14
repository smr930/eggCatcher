#include "include/Score.h"

Score::Score() { }
Score::Score(int x, int y) : Digits(currScore, x, y)
{
	this->currScore = 0;
	this->miss = 0;
}

Score::~Score() { }

void Score::setPos(int x, int y)
{
	Digits::setPos(x, y);
}

void Score::setScale(int scale)
{
	Digits::setScale(scale);
}

void Score::setCurrScore(int newScore)
{
	this->currScore = newScore;
}

int Score::getCurrScore()
{
	return currScore;
}

int Score::getMisses()
{
	return miss;
}

void Score::run()
{
	Digits::run(currScore);
}

void Score::draw()
{
	Digits::draw();
}

void Score::incScore()
{
	this->currScore++;
}

void Score::incMiss()
{
	this->miss++;
}

void Score::reset()
{
	this->currScore = 0;
	this->miss = 0;
	Digits::run(currScore);
}

