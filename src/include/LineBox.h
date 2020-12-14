#ifndef LINEBOX_H_
#define LINEBOX_H_

#include "Line.h"

class LineBox
{
private:
	Line top;
	Line bottom;
	Line right;
	Line left;
public:
	LineBox();
	LineBox(int topLeftCornerX, int topLeftCornerY, int bottomRightCornerX, int bottomRightCornerY);
	virtual ~LineBox();
	void draw();
	void setColor(g2dColor color);
	void setAlpha(unsigned int alpha);
	void setPos(int topLeftCornerX, int topLeftCornerY, int bottomRightCornerX, int bottomRightCornerY);
};

#endif /* LINEBOX_H_ */
