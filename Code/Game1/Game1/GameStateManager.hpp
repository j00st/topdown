#ifndef GameStateManager_HPP
#define GameStateManager_HPP

#include "stdafx.h"
#include "GameLoopObject.hpp"
#include "GameState.hpp"
#include<string>
#include<map>

class GameStateManager : public GameLoopObject {
private:
	GameState * currentState;
	GameState * nextState;
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

#endif //GameStateManager_HPP