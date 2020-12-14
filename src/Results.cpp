#include "include/Results.h"

Results::Results()
{
	res = Sprite("./data/results.png", 0, 0);
	overlay = Sprite(0, 0, 0);
	overlay.setCrop(0, 0, 480, 272);
	overlay.setScale(1);
	overlay.setAlpha(255);
	overlay.setColor(BLACK);
}

Results::~Results() { }

void Results::init(Score score)
{
	totalScore = score.getCurrScore();
	totalMisses = score.getMisses();
}

void Results::run(Score sc, State &st)
{
	// reuse res object to draw everything
	// bg
	res.setPos(0, 0);
	res.setCrop(80, 35, 34, 20);
	res.setScale(16);
	res.draw();

	// dots
	res.setCrop(180, 1, 8, 8);
	res.setScale(1);

	for (int i = 0; i < 30; i++) // x-axis
	{
		for (int j = 0; j < 17; j++) // y-axis
		{
			res.setPos((i*16) + 6, (j*16) + 6);
			res.setAlpha(1*(j+1));
			res.draw();
		}
	}

	// title
	res.setPos(140, 40);
	res.setCrop(0, 0, 179, 33);
	res.setScale(1);
	res.setAlpha(255);
	res.draw();

	// gradient
	res.setPos(60, 40);
	res.setCrop(0, 34, 73, 33);
	res.setRotation(0);
	res.setScale(1);
	res.draw();
	res.setPos(400, 40);
	res.setCrop(0, 34, 73, 33);
	res.setRotation(0);
	res.setScale(-1, 1);
	res.draw();

	// eggs
	res.setPos(160, 100);
	res.setCrop(115, 34, 64, 21);
	res.setScale(1);
	res.draw();

	// misses
	res.setPos(131, 140);
	res.setCrop(85, 56, 94, 21);
	res.setScale(1);
	res.draw();

	// display score
	sc.setCurrScore(totalScore);
	sc.setPos(270, 94);
	sc.setScale(2);
	sc.setSpacing(32);
	sc.draw();

	// display misses
	sc.setCurrScore(totalMisses);
	sc.setPos(270, 140);
	sc.setScale(2);
	sc.setSpacing(32);
	sc.run();
	sc.draw();

	fade(st);
}

void Results::fade(State &st)
{
	// fade in
	if(st.getCounter() > 10)
		overlay.setFade(-20);

	// fade out
	if(st.getCounter() > 170)
		overlay.setFade(30);

	if(st.getCounter() > 200)
		overlay.setAlpha(255);

	overlay.draw();
}

void Results::draw()
{

}


