#include "Sprite.h"
#include "Cat.h"
#include "Score.h"
#include "Parrot.h"

#ifndef SRC_EGG_H_
#define SRC_EGG_H_

class Egg : public Sprite {
private:
	int eggPosY;
	bool missToggle;
	Sprite miss;
	int currEggPosX1, currEggPosX2;

public:
	Egg();
	Egg(Parrot parrot, int x, int y);
	virtual ~Egg();
	void run();
	void draw();
	bool getCollision(Cat &cat);
	bool checkCollision(Cat &cat, Parrot &parrot);
	void drop(Parrot &parrot, Score &score);
	void returnEgg(Parrot &parrot);
	int getEggPosY();
	bool getMissToggle();
	void initMiss();
	void displayMiss();
};

#endif /* SRC_EGG_H_ */
