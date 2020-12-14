#include "Digit.h"

#ifndef SRC_DIGITS_H_
#define SRC_DIGITS_H_

class Digits {
protected:
	Digit dig1, dig2;
	int inputNum, ones, tens, spacing;
public:
	Digits();
	Digits(int num, int x, int y);
	virtual ~Digits();
	void convNum();
	void setPos(int x, int y);
	void setScale(int scale);
	void setColor(g2dColor color);
	void setSpacing(int space);
	void run(int updateNum);
	void draw();
	void setFade(int amount);
};

#endif /* SRC_DIGITS_H_ */
