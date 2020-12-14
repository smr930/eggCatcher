#ifndef INTRO_H_
#define INTRO_H_

#include <pspkernel.h>
#include <pspctrl.h>
#include "Line.h"
#include "Sprite.h"
#include "State.h"

class Intro
{
private:
	SceCtrlData pad;
	bool logo1Done;
	int offsetX, offsetY;
	float offsetScale;
	int logo2Alpha;

	// texture paths
	char* lockSpinTex;
	char* igTex;

	// intro sprites
	Sprite lockSpin;
	Sprite ig, ig2, ig3;

	void companyLogo1(State &st);
	void companyLogo2(State &st);

public:
	Intro();
	virtual ~Intro();
	void init();
	void run(State &st);
};

#endif /* INTRO_H_ */
