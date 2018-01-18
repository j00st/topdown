#ifndef MainMenuState_HPP
#define MainMenuState_HPP

#include "stdafx.h"
#include "GameState.hpp"

class MainMenuState : public GameState{
private:
	sf::RenderWindow &window;
	sf::Font font1;
	sf::Text text1;
public:
	MainMenuState(sf::RenderWindow & w);
	void HandleInput();
	void Update();
	void Draw();
};

#endif // MainMenuState_HPP