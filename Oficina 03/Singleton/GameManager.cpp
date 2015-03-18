#include "GameManager.h"

GameManager * GameManager::game_manager = nullptr;

GameManager::GameManager(){
	this->value = 0;
}

GameManager::~GameManager() {

}

void GameManager::setValue(int value) {
	
	this->value = value;
}

int GameManager::getValue() {
	
	return this->value;
}

GameManager * GameManager::getInstance() {
	
	if (!game_manager) {
		game_manager = new GameManager;
	}

	return game_manager;
}