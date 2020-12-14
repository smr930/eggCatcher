#include "include/Line.h"
Line::Line() {}
Line::Line(int startX, int startY, int endX, int endY)
{
	this->startPosX = startX;
	this->startPosY = startY;
	this->endPosX = endX;
	this->endPosY = endY;
	this->offsetX = 0;
	this->offsetY = 0;
	this->alpha = 255;
	this->color = WHITE;
}

void Line::setStartCoord(int x, int y)
{
	this->startPosX = x;
	this->startPosY = y;
}

void Line::setEndCoord(int x, int y)
{
	this->endPosX = x;
	this->endPosY = y;
}

void Line::setOffset(int x, int y)
{
	this->offsetX = x;
	this->offsetY = y;
}

void Line::setColor(g2dColor color)
{
	this->color = color;
}

void Line::setAlpha(g2dAlpha alpha)
{
	this->alpha = alpha;
}

void Line::draw()
{
	g2dBeginLines(g2dLine_Mode G2D_VOID);
	g2dSetColor(color);
	g2dSetAlpha(alpha);
	g2dSetCoordXY(startPosX + offsetX, startPosY + offsetY);
	g2dAdd();
	g2dPush();
	g2dSetCoordXYRelative(endPosX + offsetX, endPosY + offsetY);
	g2dAdd();
	g2dEnd();
}
