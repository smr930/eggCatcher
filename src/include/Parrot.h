#include "Sprite.h"
#include "State.h"
#include "Score.h"

#ifndef SRC_PARROT_H_
#define SRC_PARROT_H_

class Parrot : public Sprite
{
public:
	Parrot();
	virtual ~Parrot();

	void run(State &st, Score &score);
	void draw();
	int getPosX();
	int getPosY();
	void move(int speed);
};

#endif /* SRC_PARROT_H_ */
