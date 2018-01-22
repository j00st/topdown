#ifndef MainMenuState_HPP
#define MainMenuState_HPP

#include "stdafx.h"
#include "GameState.hpp"
#include "controlsController.h"
#include "controlsInput.h"
#include "GameStateManager.hpp"
#include <string>

class MainMenuState : public GameState{
private:
	sf::RenderWindow &window;
	ControlsController &controlsCtrl;
	ControlsInput & controlsInput;
	GameStateManager &gsm;
	sf::Font font1;
	sf::Text text1;
public:
	MainMenuState(sf::RenderWindow & w, ControlsController &cc, ControlsInput &ci, GameStateManager &gsm);
	void HandleInput();
	void Update();
	void Draw();
};

#endif // MainMenuState_HPP