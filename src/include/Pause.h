#include "Sprite.h"
#include "LineBox.h"
#include "State.h"

#ifndef PAUSE_H_
#define PAUSE_H_

class Pause : public Sprite
{
private:
	Sprite pauseBox;
	LineBox lb;
	float pauseScale;

public:
	Pause();
	virtual ~Pause();
	void run(State st);
};

#endif /* PAUSE_H_ */
