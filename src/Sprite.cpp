#include "include/Sprite.h"

	Sprite::Sprite(){}
	Sprite::Sprite(char* path, int x, int y)
	{
		this->tex = g2dTexLoad(path, G2D_SWIZZLE);
		this->posX = x;
		this->posY = y;
		this->rot = 0;
		this->alpha = 255;
		this->scaleX = 64;
		this->scaleY = 64;
		this->alpha = 255;
		this->color = WHITE;
		this->multiplier = 1;
		this->framesX = 1;
		this->framesY = 1;
		this->animCompleted = false;
		this->dir = 1;
	}

	// Getters
	int Sprite::getPosX() 	   { return posX; }
	int Sprite::getPosY() 	   { return posY; }
	int Sprite::getWidth() 	   { return cropW; }
	int Sprite::getHeight()    { return cropH; }
	float Sprite::getScaleX()  { return scaleX; }
	float Sprite::getScaleY()  { return scaleY; }
	g2dColor Sprite::getColor(){ return color; }
	g2dAlpha Sprite::getAlpha(){ return alpha; }
	bool Sprite::isAnimCompleted(){	return animCompleted;}

	// Setters
	void Sprite::setPosX(int x) { this->posX = x; }
	void Sprite::setPosY(int y) { this->posY = y; }

	void Sprite::setPos(int x, int y)
	{
		this->posX = x;
		this->posY = y;
	}

	void Sprite::setRotation(int rot)
	{
		this->rot = rot;
	}

	void Sprite::setCrop(int x, int y, int width, int height)
	{
		this->cropX = x;
		this->oldCropX = x;
		this->cropY = y;
		this->oldCropY = y;
		this->cropW = width;
		this->cropH = height;
	}

	void Sprite::setScale(float multiplier)
	{
		this->multiplier = multiplier;
		this->scaleX = cropW * multiplier;
		this->scaleY = cropH * multiplier;
	}

	void Sprite::setScale(float x, float y)
	{
		this->scaleX = cropW * x;
		this->scaleY = cropH * y;
	}

	void Sprite::setColor(g2dColor color)
	{
		this->color = color;
	}

	void Sprite::setAlpha(g2dAlpha alpha)
	{
		this->alpha = alpha;
	}

	void Sprite::setFade(g2dAlpha fadeAmount)
	{
		this->alpha += fadeAmount;
		if(this->alpha > 255)
			this->alpha = 255;
		else if(this->alpha < 0)
			this->alpha = 0;
	}

	void Sprite::flipX()
	{
		setScale(-1.0, 1.0);
	}

	void Sprite::flipY()
	{
		g2dSetScale(1.0, -0.5);
	}

	void Sprite::pingPong(int startPos, int endPos, int speed)
	{
		static bool forward = true;
		static bool backward = false;

		int currPos = this->getPosX();
		if(forward == true)
		{
			if (currPos >= endPos)
			{
				forward = false;
				backward = true;
				dir = dir * -1;
			}
			else
				currPos += speed;
		}

		if(backward == true)
		{
			if (currPos <= startPos)
			{
				forward = true;
				backward = false;
				dir = dir * -1;
			}
			else
				currPos -= speed;
		}

		this->setPosX(currPos);
	}

	int Sprite::getDirection()
	{
		return this->dir;
	}

	void Sprite::setFramesX(int frames)
	{
		this->framesX = frames;
	}

	void Sprite::setFramesY(int frames)
	{
		this->framesY = frames;
	}

	void Sprite::cycleFrameX ()
	{
		cropX += cropW;				  	// increase sprite x crop
		if (cropX == cropW * framesX)  	// check for end of sprite horizontally
		{
			cropX = oldCropX; 		  	// cycle back to the beginning
		}
	}

	void Sprite::resetFrameX ()
	{
			cropX = oldCropX; 			// back to the beginning of spritesheet
	}

	void Sprite::setAnimCompleted(bool toggle)
	{
		animCompleted = toggle;
	}

	void Sprite::cycleFrameXY ()
	{
		int maxRow = framesY; 			// maximum sprite rows
		cropX += cropW;			  		// increase sprite x crop
		static int currRow = 0;

		if (cropX == cropW * framesX)	// check for end of sprite horizontally
		{
			cropX = oldCropX;			// set cropX to start at beginning
			cropY += cropW;		  		// increase sprite y crop
			currRow++;				  	// acknowledge that sprite y crop
		}							  	// has changed by adding 1.

		if (currRow == maxRow)			// cycle through sprite frames once and
		{								// hold the last frame
			animCompleted = true;
			cropX += cropW * (framesX-1);
			return;
		}


		if (currRow == maxRow + 1)		// check if sprite has cycled through
		{								// all the rows.
			currRow = 1;				// set the current row back to 1
			cropX = oldCropX;			// set cropX to 0, so it crops at (0,y)
			cropY = oldCropY;			// set cropY to 0, so it crops at (x,0)
		}
	}


	void Sprite::draw()
	{
		g2dBeginRects(tex); 		  	// texture pointer (pass NULL to get a colored rectangle)
		g2dSetCoordXY(posX, posY); 	  	// Move to (x,y) on screen
		g2dSetCropXY (cropX, cropY);  	// Starting position of Crop
		g2dSetCropWH (cropW, cropH);  	// Ending position of Crop
		g2dSetScaleWH(scaleX, scaleY);	// Scale
		g2dSetRotationRelative (rot); 	// Rotation center
		g2dSetColor(color);
		g2dSetAlpha(alpha);
		g2dAdd(); 					  	// Add these properties to a new rectangle
		g2dEnd(); 					  	// Draw the whole thing
	}

	void Sprite::showBoundingBox(bool isActive)
	{
		if(isActive)
		{
			g2dBeginRects(0); // No texture
			g2dSetColor(RED);
			g2dSetCoordXY(posX, posY);
			g2dSetScaleWH(scaleX, scaleY);
			g2dSetAlpha(128);
			g2dAdd();
			g2dEnd();
		}
		else
			return;
	}

	void Sprite::setCoordMode(g2dCoord_Mode mode)
	{
		g2dSetCoordMode(mode);
	}

	void Sprite::resetCoordMode()
	{
		g2dResetCoord();
	}

	void Sprite::rotateTo(int rot, int limit)
	{
		this->rot += rot;
		if(this->rot > limit)
			this->rot = rot;
		if(this->rot < rot)
			this->rot = limit;
	}
