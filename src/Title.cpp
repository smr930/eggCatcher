#include "include/Title.h"
#include <stdio.h>

Title::Title()
{ }

Title::~Title()
{
	printf("---->  Title::~Title() destructor called!\n");
}

void Title::init()
{
	titleState = State();
	lineAlpha = 0;
	line = Line(0, 0, 480, 0);
	line.setColor(BLACK);

	// texture paths
	startScreenTex = "./data/startScreen.png";
	charactersTex = "./data/characters.png";

	lastRTButton = 0;
	gridPos1 = -240;
	gridPos2 = 0;
	gridPos3 = 240;
	gridSpeed = 1;
	parrotPos = 0;
	parrotAlpha = 0;
	ecTitleScale = 0.1;

	// sprite
	mainSprite = Sprite(startScreenTex, 0, 0);

	// bg
	bg = Sprite(startScreenTex, 0, 0);
	bg.setCrop(204, 132, 20, 20);
	bg.setScale(26, 18);

	// egg 
	egg = Sprite(startScreenTex, 0, 0);

	// egg catcher title
	ecTitle = Sprite(startScreenTex, 0, 0);

	// parrot
	parrot = Sprite(charactersTex, 0, 0);
	parrot.setCrop(0, 0, 128, 128);
	parrot.setScale(1);
	
	// press start
	pressStart = Sprite(startScreenTex, 0, 0);
	pressStart.setCrop(82, 102, 174, 22);
	pressStart.setScale(1);
	pressStart.setPos(150, 180);

	// start wrapper
	startWrapper = mainSprite;

	// pillar corner left and right
	pillarCorner = Sprite(startScreenTex, 0, 0);

	printf("---->  Title::init() completed!\n");
}

void Title::run(State &st, SceCtrlData &pad)
{
	titleState.incCounter();
	bg.draw(); 

	// Egg
	egg.setCrop(81, 0, 67, 93);
	egg.setScale(1);
	egg.setRotation(0);
	egg.setPos(91, 12);
	egg.draw();

	egg.setCrop(81, 0, 67, 93);
	egg.setScale(-1);
	egg.setRotation(0);
	egg.setPos(225, 198);
	egg.draw();

	egg.setCrop(81, 0, 67, 93);
	egg.setScale(1, -1);
	egg.setRotation(0);
	egg.setPos(91, 198);
	egg.draw();

	egg.setCrop(81, 0, 67, 93);
	egg.setScale(-1, 1);
	egg.setRotation(0);
	egg.setPos(225, 12);
	egg.draw();

	// Parrot
	parrot.setPos(parrotPos, 30);
	parrot.setAlpha(parrotAlpha);

	if(parrot.getPosX() != 50)
	{
		if (parrotPos > 45 && parrotPos < 50)
			parrotPos++;
		else
			parrotPos += 2;
	}

	if(parrot.getAlpha() < 255)
		parrotAlpha += 8;
	parrot.draw();

	// EC Title
	ecTitle.setCrop(0, 94, 80, 36);
	ecTitle.setScale(ecTitleScale);
	ecTitle.setPos(188, 48);
	ecTitle.draw();

	ecTitle.setCrop(0, 131, 192, 36);
	ecTitle.setScale(ecTitleScale);
	ecTitle.setPos(188, 88);
	ecTitle.draw();
	if (ecTitleScale < 1)
	{
		if (ecTitleScale < 1 && ecTitleScale > 0.8) // ease the scaling towards the end
			ecTitleScale += 0.03;
		else
			ecTitleScale += 0.1; // start scale factor to normal speed
	}

	pressStart.draw();

	// Start Button Wrapper
	startWrapper.setCrop(224, 124, 11, 47);
	startWrapper.setScale(1);
	startWrapper.setPos(137, 168);
	startWrapper.draw();

	startWrapper.setScale(-1, 1);
	startWrapper.setPos(337, 168);
	startWrapper.draw();

	// Upper Left corner
	pillarCorner.setCrop(0, 0, 81, 73);
	pillarCorner.setScale(1);
	pillarCorner.setPos(0, 0);
	pillarCorner.draw();

	// Left pillar
	pillarCorner.setCrop(0, 64, 20, 8);
	pillarCorner.setScale(1,28);
	pillarCorner.setPos(0, 64);
	pillarCorner.draw();

	// Lower right corner
	pillarCorner.setCrop(0, 0, 81, 73);
	pillarCorner.setScale(-1);
	pillarCorner.setRotation(0);
	pillarCorner.setPos(480, 272);
	pillarCorner.draw();

	// Right pillar
	pillarCorner.setCrop(0, 64, 20, 8);
	pillarCorner.setScale(1,28);
	pillarCorner.setPos(461, 0);
	pillarCorner.draw();

	// Grid
	pillarCorner.setCrop(0, 172, 240, 88);
	pillarCorner.setScale(1);
	if (gridPos1 >= 480)
		gridPos1 = -240;
	gridPos1 += gridSpeed;

	if (gridPos2 >= 480)
		gridPos2 = -240;
	gridPos2 += gridSpeed;

	if (gridPos3 >= 480)
		gridPos3 = -240;
	gridPos3 += gridSpeed;

	pillarCorner.setPos(gridPos1, 187); // 1
	pillarCorner.draw();
	pillarCorner.setPos(gridPos2, 187); // 2
	pillarCorner.draw();
	pillarCorner.setPos(gridPos3, 187); // 3
	pillarCorner.draw();

	// scanlines
	if (pad.Lx > 200 || pad.Lx < 56 || pad.Ly > 200 || pad.Ly < 56)
	{
		if (lineAlpha >= 240)
			lineAlpha = 240;
		else
			lineAlpha += 2;
	}

	else
	{
		if (lineAlpha < 0)
			lineAlpha = 0;
		else
			lineAlpha -= 8;
	}

	for (int i = 0; i < 272; i+=2)
	{
		line.setStartCoord(0, i);
		line.setEndCoord(480, 0);
		line.setAlpha(lineAlpha);
		line.draw();
	} // end of scanlines imp

	// go on to the next scene
	if (pad.Buttons != lastRTButton)
	{
		if ((pad.Buttons & PSP_CTRL_CROSS) || (pad.Buttons & PSP_CTRL_START))
		{
			st.setStateChange(true);
		}
		lastRTButton = pad.Buttons;
		titleState.resetCounter();
	}

	// transition before changing scene
	if(st.getStateChange() == true)
	{
		switch(titleState.getCounter())
		{ // scale down start button
			case 2:
				pressStart.setScale(0.9);
				pressStart.setPos(158, 181);
				startWrapper.setAlpha(205);
				break;
			case 4:
				pressStart.setScale(0.8);
				pressStart.setPos(164, 182);
				startWrapper.setAlpha(155);
				break;
			case 6:
				pressStart.setScale(0.7);
				pressStart.setPos(174, 182);
				startWrapper.setAlpha(105);
				break;
			case 8:
				pressStart.setScale(0.6);
				pressStart.setPos(180, 182);
				startWrapper.setAlpha(55);
				break;
			case 9:
				pressStart.setScale(0.5);
				pressStart.setPos(190, 182);
				startWrapper.setAlpha(32);
				break;
		}

		if (titleState.getCounter() > 10)
		{
			st.setStateChange(false);
			st.setCurrState(st.MAINGAME);
			st.setTitleSceneDone(true);
		}
	}
}
