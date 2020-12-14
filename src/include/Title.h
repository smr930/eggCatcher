#ifndef TITLE_H_
#define TITLE_H_

#include <pspkernel.h>
#include <pspctrl.h>
#include "Line.h"
#include "Sprite.h"
#include "State.h"

class Title
{
private:
	// texture paths
	char* startScreenTex;
	char* charactersTex;
	unsigned int lastRTButton;
	State titleState;
	Line line;

	int gridPos1, gridPos2, gridPos3, gridSpeed;
	int parrotPos, parrotAlpha;
	float ecTitleScale;
	int lineAlpha;

	Sprite bg;
	Sprite egg;
	Sprite parrot;
	Sprite ecTitle;
	Sprite pressStart;
	Sprite pillarCorner;
	Sprite mainSprite;
	Sprite startWrapper;

public:
	Title();
	virtual ~Title();
	void init();
	void run(State &st, SceCtrlData &pad);

};

#endif /* TITLE_H_ */
