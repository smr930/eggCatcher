#ifndef GAME_H_
#define GAME_H_

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <stdio.h>
#include "Line.h"
#include "Sprite.h"
#include "State.h"
#include "Intro.h"
#include "Title.h"
#include "Pause.h"
#include "Parrot.h"
#include "Egg.h"
#include "Cat.h"
#include "Score.h"
#include "Results.h"

class Game
{
private:
	SceCtrlData pad;
	State gameState;
	Intro *introScene;
	Title *titleScene;
	Pause pause;
	Parrot parrot;
	Cat cat;
	Egg egg;
	Score score;
	Results result;

	unsigned int lastRTButton;
	unsigned int lastStartButton;
	bool gamePaused;
	int winScore;
	bool winner;
	bool toggleBoundingBox;
	char* bgTex;
	Sprite bg;

	void gameScene();
	void winScene();

	void boundingBox(bool b);
	void drawMainGameItems();

public:
	Game();
	virtual ~Game();
	void init();
	void run();
};

#endif /* GAME_H_ */
