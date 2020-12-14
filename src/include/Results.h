#include "Sprite.h"
#include "Score.h"
#include "Digits.h"
#include "State.h"

#ifndef SRC_RESULTS_H_
#define SRC_RESULTS_H_

class Results {
private:
	Sprite res;
	Sprite overlay;
	int totalScore;
	int totalMisses;
public:
	Results();
	virtual ~Results();
	void init(Score score); // pass score as value
	void run(Score score, State &st);
	void fade(State &st);
	void draw();
};

#endif /* SRC_RESULTS_H_ */
