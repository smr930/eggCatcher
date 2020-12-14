#include "Sprite.h"

#ifndef SRC_DIGIT_H_
#define SRC_DIGIT_H_

class Digit : public Sprite
{
protected:
	int sWidth;
	int sHeight;
	int num;
public:
	Digit();
	Digit(int num, int x, int y);
	void setPos(int posX, int posY);
	void setScale(int scale);
	void setSpriteWH(int w, int h);
	void setColor(g2dColor color);
	void run(int updateNum);
	void draw();
	virtual ~Digit();
};

#endif /* SRC_DIGIT_H_ */
