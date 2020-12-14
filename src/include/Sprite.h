#ifndef SPRITE_H_
#define SPRITE_H_

#include "../lib/glib2d.h"

class Sprite
{
protected:
	g2dTexture* tex;    // pass a texture file pointer
	int posX;
	int posY;
	int cropX;  		// crop coordinates X
	int cropY ;  		// crop coordinates Y
	int cropW;  		// crop width, from cropX to cropW
	int cropH;  		// crop height
	int scaleX;
	int scaleY;
	float multiplier;
	int rot;    		// rotation in degrees
	g2dAlpha alpha;   	// transparency of texture
	g2dColor color;
	int framesX;		// number of individual frames for animating sprite
	int framesY;
	int oldCropX;		// save the old crop before animating
	int oldCropY;
	bool animCompleted;
	int dir;

public:
	Sprite();
	Sprite(char* path, int x, int y);

	// Getters
	int getPosX();
	int getPosY();
	int getWidth();
	int getHeight();
	float getScaleX();
	float getScaleY();
	g2dColor getColor();
	g2dAlpha getAlpha();
	bool isAnimCompleted();
	int getDirection();

	// Setters
	void setPosX(int x);
	void setPosY(int y);
	void setPos(int x, int y);
	void setRotation(int rot);
	void setCrop(int x, int y, int width, int height);
	void setScale(float multiplier);
	void setScale(float x, float y);
	void setColor(g2dColor color);
	void setAlpha(g2dAlpha alpha);
	void setFade(g2dAlpha alpha);
	
	void flipX();
	void flipY();
	void pingPong(int startPos, int endPos, int speed);
	void setFramesX(int frames);
	void setFramesY(int frames);
	void cycleFrameX ();
	void resetFrameX ();
	void cycleFrameXY ();
	void setAnimCompleted(bool toggle);
	virtual void draw();
	void showBoundingBox(bool isActive);
	void setCoordMode(g2dCoord_Mode mode);
	void resetCoordMode();
	void rotateTo(int rot, int limit);
};

#endif /* SPRITE_H_ */
