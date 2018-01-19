#ifndef GameStackManager_HPP
#define GameStackManager_HPP

#include "stdafx.h"
#include "GameLoopObject.hpp"
#include "GameState.hpp"
#include<string>

class GameStateManager : public GameLoopObject {
private:
	GameState currentState;
public:
	void Switch(GameState state);
	void Get()

















	GameState * currentState;
	GameState * nextState;
	//std::string currentState;
	//std::string nextState;
public:
	std::map<std::string, GameState> gameStates{}; // list where all known gamestates are stored.
												   // methods
	GameStateManager();
	void AddGameState(std::string name, GameState * state);
	void SetNext(std::string name);
	void SwitchState();
	void HandleInput();
	void Update();
	void Draw();
	void Reset();
};

#endif //GameStackManager_HPP