#include "include/Intro.h"
#include <stdio.h>

Intro::Intro() { }

Intro::~Intro()
{
	printf("---->  Intro::~Intro() destructor called!\n");
}

//--------------------------------------
void Intro::init()
{
	// texture paths
	lockSpinTex = "./data/lockSpin.png";
	igTex = "./data/igLogo.png";

	/** set params for sprites **/

	// intro1
	lockSpin = Sprite(lockSpinTex, 198, 94);
	lockSpin.setCrop(0, 0, 84, 84);
	lockSpin.setScale(1);
	lockSpin.setFramesX(6);
	lockSpin.setFramesY(6);
	logo1Done = false;

	// intro2
	ig = Sprite(igTex, 160, 80);
	offsetX = -260;
	offsetY = 12;
	offsetScale = 2;
	logo2Alpha = 255;

	printf("---->  Intro::init() completed!\n");
}

//--------------------------------------
void Intro::run(State &st)
{
	companyLogo1(st);
	companyLogo2(st);

	// go to title screen
	if(st.getCounter() > 300)
	{
		st.setCurrState(st.TITLE);
		st.resetCounter();
		lockSpin.setAnimCompleted(false);
		st.setStateChange(false);
		st.setIntroSceneDone(true);
	}
}

//--------------------------------------
void Intro::companyLogo1(State &st)
{
	// display and animate logo1
	if(!lockSpin.isAnimCompleted())
	{
		lockSpin.cycleFrameXY();
		lockSpin.draw();
	}

	if(lockSpin.isAnimCompleted())
			logo1Done = true;
}

void Intro::companyLogo2(State &st)
{
	if (logo1Done)
	{
		ig.setCrop(0, 0, 256, 36); // ig sprite
		ig.setScale(offsetScale);
		ig.setPos(140 + offsetX, 90 + offsetY);			// final pos = 140, 90
		ig.setAlpha(logo2Alpha);
		ig.draw();

		ig2 = ig;
		ig2.setCrop(0, 36, 164, 36); // games sprite
		ig2.setScale(offsetScale);
		ig2.setPos(140 + offsetX, 126 + offsetY);		// final pos = 140, 126
		ig2.setAlpha(logo2Alpha);
		ig2.draw();

		ig3 = ig;
		ig3.setCrop(196, 36, 60, 72); // igLogo sprite
		ig3.setScale(offsetScale);
		ig3.setPos(78 + offsetX, 90 + offsetY);			// final pos = 78, 90
		ig3.setAlpha(logo2Alpha);
		ig3.draw();

		// scale down and move over
		if(offsetX < 0)
			offsetX += 16;

		if(offsetY > 0)
			offsetY -= 1;

		if(offsetScale > 1)
			offsetScale -= 0.06;

		if(st.getCounter() > 268)
		{
			logo2Alpha -= 8;
		}
	}
}

