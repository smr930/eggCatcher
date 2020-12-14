#ifndef LINE_H_
#define LINE_H_

#include "../lib/glib2d.h"

class Line
{
private:
	int startPosX;
	int startPosY;
	int endPosX;
	int endPosY;
	int offsetX;
	int offsetY;
	g2dAlpha alpha;
	g2dColor color;

public:
	Line();
	Line(int startX, int startY, int endX, int endY);

	void setStartCoord(int x, int y);
	void setEndCoord(int x, int y);
	void setOffset(int x, int y);
	void setColor(g2dColor color);
	void setAlpha(g2dAlpha alpha);
	void draw();

};

#endif /* LINE_H_ */
