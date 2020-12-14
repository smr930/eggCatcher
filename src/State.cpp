#include "include/State.h"

State::State()
{
	counter = 0;
	currState = 0;
	stateChange = false;

	introSceneDone = false;
	introSceneDeleted = false;
	titleSceneDone = false;
	titleSceneDeleted = false;
}

State::~State() { }

void State::incCounter()
{
	counter++;
}

int State::getCounter()
{
	return counter;
}

void State::setCounter(int count)
{
	counter = count;
}

void State::resetCounter()
{
	setCounter(0);
}

int State::getCurrState()
{
	return currState;
}

void State::setCurrState(int st)
{
	currState = st;
}

bool State::getStateChange()
{
	return stateChange;
}

void State::setStateChange(bool toggle)
{
	stateChange = toggle;
}

//----------------------------------------
void State::setIntroSceneDone(bool toggle)
{
	introSceneDone = toggle;
}

void State::setIntroSceneDeleted(bool toggle)
{
	introSceneDeleted = toggle;
}

bool State::getIntroSceneDone()
{
	return introSceneDone;
}

bool State::getIntroSceneDeleted()
{
	return introSceneDeleted;
}

//----------------------------------------
void State::setTitleSceneDone(bool toggle)
{
	titleSceneDone = toggle;
}

void State::setTitleSceneDeleted(bool toggle)
{
	titleSceneDeleted = toggle;
}

bool State::getTitleSceneDone()
{
	return titleSceneDone;
}

bool State::getTitleSceneDeleted()
{
	return titleSceneDeleted;
}

//----------------------------------------

