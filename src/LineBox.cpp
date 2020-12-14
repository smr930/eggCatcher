#include "include/LineBox.h"

LineBox::LineBox() { }
LineBox::~LineBox() { }

LineBox::LineBox(int topLeftCornerX, int topLeftCornerY, int bottomRightCornerX, int bottomRightCornerY)
{
	setPos(topLeftCornerX, topLeftCornerY, bottomRightCornerX, bottomRightCornerY);
	this->top = Line(topLeftCornerX, topLeftCornerY, bottomRightCornerX, 0);
	this->bottom = Line(topLeftCornerX, topLeftCornerY+bottomRightCornerY, bottomRightCornerX, 0);
	this->left = Line(topLeftCornerX, topLeftCornerY, 0, bottomRightCornerY);
	this->right = Line(topLeftCornerX+bottomRightCornerX, topLeftCornerY, 0, bottomRightCornerY);
}

void LineBox::setPos(int topLeftCornerX, int topLeftCornerY, int bottomRightCornerX, int bottomRightCornerY)
{
	this->top.setStartCoord(topLeftCornerX, topLeftCornerY);
	this->top.setEndCoord(bottomRightCornerX, 0);
	this->bottom.setStartCoord(topLeftCornerX, topLeftCornerY + bottomRightCornerY);
	this->bottom.setEndCoord(bottomRightCornerX, 0);
	this->left.setStartCoord(topLeftCornerX, topLeftCornerY);
	this->left.setEndCoord(0, bottomRightCornerY);
	this->right.setStartCoord(topLeftCornerX + bottomRightCornerX, topLeftCornerY);
	this->right.setEndCoord(0, bottomRightCornerY);
}

void LineBox::draw()
{
	this->top.draw();
	this->bottom.draw();
	this->left.draw();
	this->right.draw();
}

void LineBox::setColor(g2dColor color)
{
	this->top.setColor(color);
	this->bottom.setColor(color);
	this->left.setColor(color);
	this->right.setColor(color);
}

void LineBox::setAlpha(unsigned int alpha)
{
	this->top.setAlpha(alpha);
	this->bottom.setAlpha(alpha);
	this->left.setAlpha(alpha);
	this->right.setAlpha(alpha);
}

