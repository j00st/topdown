#ifndef MainMenuState_HPP
#define MainMenuState_HPP

#include "stdafx.h"
#include "GameState.hpp"

class MainMenuState : public GameState{
private:

public:
	MainMenuState(sf::RenderWindow & w);
	void HandleInput();
	void Update();
	void Draw();
};

#endif // MainMenuState_HPP