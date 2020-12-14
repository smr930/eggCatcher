#ifndef STATE_H_
#define STATE_H_

class State {
private:
	int counter; // frame counter
	int currState; // game state
	bool stateChange; // toggle at the beginning of state change
	bool introSceneDone;
	bool introSceneDeleted;
	bool titleSceneDone;
	bool titleSceneDeleted;

public:
	State();
	virtual ~State();

	enum state
	{
		INTRO,
		TITLE,
		MAINGAME,
		WIN,
		GAMEOVER
	};

	void incCounter();
	int getCounter();
	void setCounter(int count);
	void resetCounter();
	int getCurrState();
	void setCurrState(int st);
	bool getStateChange();
	void setStateChange(bool toggle);

	void setIntroSceneDone(bool toggle);
	void setIntroSceneDeleted(bool toggle);
	bool getIntroSceneDone();
	bool getIntroSceneDeleted();
	void setTitleSceneDone(bool toggle);
	void setTitleSceneDeleted(bool toggle);
	bool getTitleSceneDone();
	bool getTitleSceneDeleted();

};

#endif /* STATE_H_ */

