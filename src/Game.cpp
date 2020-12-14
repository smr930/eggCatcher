#include "include/Game.h"

Game::Game()  { }
Game::~Game() { }

void Game::init()
{
	pspDebugScreenInit();
	sceCtrlSetSamplingCycle(0);
	sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);
	gameState = State();
	gameState.setCurrState(State::INTRO);
	introScene = new Intro();
	if (introScene == NULL)
		printf("---->  introScene - Failed to allocate memory!\n");
	introScene->init();
	titleScene = new Title();
	if (titleScene == NULL)
		printf("---->  titleScene - Failed to allocate memory!\n");
	titleScene->init();

	lastRTButton = 0;
	lastStartButton = 0;
	toggleBoundingBox = false;
	gamePaused = false;
	winScore = 12;

	// initialize game objects
	bgTex = "./data/bg1.png";
	bg = Sprite(bgTex, 0, 0);
	bg.setCrop(0, 0, 480, 272);
	bg.setScale(1);
	parrot = Parrot();
	egg = Egg(parrot, 208, parrot.getPosY() + 52);
	cat = Cat();
	score = Score(456, 10);
	pause = Pause();
	result = Results();

	printf("---->  Game::init() completed!\n");
}

//--------------------------------------
void Game::run()
{
	  for (;;) // the game loop
	  {
		gameState.incCounter();
		sceCtrlPeekBufferPositive(&pad, 1);
		g2dClear(BLACK);
		switch(gameState.getCurrState())
		{
			case State::INTRO:
				introScene->run(gameState);
				break;

			case State::TITLE:
				// dispose of introScene from heap
				if (gameState.getIntroSceneDone() && !gameState.getIntroSceneDeleted())
				{
					delete introScene;
					introScene = 0;
					gameState.setIntroSceneDeleted(true);
				}

				titleScene->run(gameState, pad);
				break;

			case State::MAINGAME:
				// dispose of titleScene from heap
				if (gameState.getTitleSceneDone() && !gameState.getTitleSceneDeleted())
				{
					delete titleScene;
					titleScene = 0;
					gameState.setTitleSceneDeleted(true);
				}

				// gameScene stays on the stack
				gameScene();
				break;

			case State::WIN:
				winScene();
				break;

		} // end of switch

	    g2dFlip(G2D_VSYNC);

	    if (gameState.getCounter() > 10000)
	    	gameState.resetCounter();

	    if (gameState.getStateChange() == true)
	    	gameState.resetCounter();
	  } // end of game loop
}

//--------------------------------------
void Game::gameScene()
{
	if (gamePaused == false)
	{
		drawMainGameItems();
		parrot.run(gameState, score);

		// drop the egg from the parrot's position
		egg.drop(parrot, score);

		// check for egg's collision with the cat
		if (egg.getCollision(cat))
		{
			cat.react();
			score.incScore();
			score.run();
			//printf("Current Score = %d\n", score.getCurrScore());
			egg.returnEgg(parrot);
		}

		// check if the egg goes off-screen
		else if (egg.getEggPosY() > 272)
		{
			cat.initMiss();
			egg.initMiss();
			egg.returnEgg(parrot);
			score.incMiss();
		}

		if (cat.getMissToggle())
		{
			cat.displayMiss();
			egg.displayMiss();
		}

		// check for win condition
		if (score.getCurrScore() == winScore)
		{
			result.init(score);
			gameState.setCurrState(State::WIN);
			gameState.setStateChange(true);
		}

		// controls
		if (pad.Buttons & PSP_CTRL_RIGHT || pad.Lx > 150)
		{
			cat.move(gameState, 2);
		}

		if (pad.Buttons & PSP_CTRL_LEFT || pad.Lx < 106)
		{
			cat.move(gameState, -2);
		}

		/****** bounding box for debugging
		if (pad.Buttons != lastRTButton)
		{
			if (pad.Buttons & PSP_CTRL_RTRIGGER)
			{
				if (toggleBoundingBox == false)
					toggleBoundingBox = true;
				else if (toggleBoundingBox == true)
					toggleBoundingBox = false;
			}
			lastRTButton = pad.Buttons;
		}
		boundingBox(toggleBoundingBox);
		*******/
	}

	if (gamePaused == true)
	{
		drawMainGameItems();
		pause.run(gameState);
	}

	if (pad.Buttons != lastStartButton)
	{
		if (pad.Buttons & PSP_CTRL_START)
		{
			if (gamePaused == false)
			{
				gamePaused = true;
				gameState.resetCounter();
			}
			else if (gamePaused == true)
			{
				gamePaused = false;
			}
		}
		lastStartButton = pad.Buttons;
	}
}

//--------------------------------------
void Game::winScene()
{
	result.run(score, gameState);

	if(gameState.getCounter() > 200)
	{
		score.reset();
		gameState.setCurrState(State::MAINGAME);
	}
	gameState.setStateChange(false);
}

//--------------------------------------
void Game::boundingBox(bool b)
{
	parrot.showBoundingBox(b);
	egg.showBoundingBox(b);
	cat.showBoundingBox(b);
}

//--------------------------------------
void Game::drawMainGameItems()
{
	bg.draw();
	parrot.draw();
	egg.draw();
	cat.draw();
	score.draw();
}

//--------------------------------------

