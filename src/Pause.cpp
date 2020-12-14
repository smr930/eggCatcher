#include "include/Pause.h"

Pause::Pause() : Sprite("./data/pause.png", 208, 120)
{
	pauseScale = 0.5;

	// text
	Sprite::setCrop(0, 0, 64, 32);
	Sprite::setScale(1);

	// pause box
	pauseBox = Sprite(0, 190, 116);
	pauseBox.setCrop(0, 0, 100, 40);
	pauseBox.setScale(0.5);
	pauseBox.setAlpha(220);
	pauseBox.setColor(0xFF996008);  // teal color, param in hex: alpha, b, g, r
	lb = LineBox(190, 116, 105, 42);
}

Pause::~Pause() { }

void Pause::run(State st)
{
	// draw pause box edges
	if(st.getCounter() >= 0 && st.getCounter() < 2)
	{
		lb.setPos(160, 86, 165, 102);
		lb.setAlpha(32);
		lb.draw();
	}

	else if(st.getCounter() >= 1 && st.getCounter() < 4)
	{
		lb.setPos(170, 96, 145, 82);
		lb.setAlpha(64);
		lb.draw();
	}
	else if(st.getCounter() >= 3 && st.getCounter() < 6)
	{
		lb.setPos(180, 106, 125, 62);
		lb.setAlpha(128);
		lb.draw();
	}
	else if(st.getCounter() >= 5 && st.getCounter() < 8)
	{
		lb.setPos(190, 116, 105, 42);
		lb.setAlpha(190);
		lb.draw();
	}

	// draw pause box
	if(st.getCounter() >= 8)
	{
		if (pauseScale <= 1.0)
			pauseScale += 0.28;
		pauseBox.setScale(pauseScale);
		pauseBox.draw();
		lb.setAlpha(255);
		lb.draw();
	}

	// draw pause text with color red
	if(st.getCounter() >= 10 && st.getCounter() < 12)
	{
		Sprite::setColor(RED);
		Sprite::setScale(1.1, 1);
		Sprite::draw();
	}

	// draw pause text with color white
	else if(st.getCounter() >= 12)
	{
		Sprite::setColor(WHITE);
		Sprite::setScale(1, 1);
		Sprite::draw();
	}
}
