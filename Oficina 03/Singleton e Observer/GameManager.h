#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

class GameManager {
private:
	int value;
	static GameManager * game_manager;

public:
	GameManager();
	~GameManager();

	static GameManager * getInstance();

	void setValue(int value);
	int getValue();
};

#endif