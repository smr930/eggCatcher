#include "Digits.h"

#ifndef SRC_SCORE_H_
#define SRC_SCORE_H_

class Score : public Digits {
private:
	int currScore;
	int miss;
public:
	Score();
	Score(int x, int y);
	virtual ~Score();
	void setPos(int x, int y);
	void setScale(int scale);
	void setCurrScore(int newScore);
	int getCurrScore();
	int getMisses();
	void run();
	void draw();
	void incScore();
	void incMiss();
	void reset();
};

#endif /* SRC_SCORE_H_ */
