#include "Sprite.h"
#include "State.h"

#ifndef SRC_CAT_H_
#define SRC_CAT_H_

class Cat : public Sprite
{
private:
	Sprite shadow;
	Sprite miss;
	bool missToggle;

public:
	Cat();
	virtual ~Cat();
	void run();
	void draw();
	int getPosX();
	int getPosY();
	void move(State &st, int speed);
	void react();
	bool getMissToggle();
	void initMiss();
	void displayMiss();
};

#endif /* SRC_CAT_H_ */
