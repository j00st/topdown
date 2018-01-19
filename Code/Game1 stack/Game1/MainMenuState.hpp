#ifndef MainMenuState_HPP
#define MainMenuState_HPP

#include "stdafx.h"
#include "GameState.hpp"
#include <string>

class MainMenuState : public GameState{
private:
	sf::RenderWindow &window;
	sf::Font font1;
	sf::Text text1;
	std::string stateID = "999";
public:
	MainMenuState(sf::RenderWindow & w);
	void HandleInput();
	void Update();
	void Draw();
	std::string testString = "------0000--------";
	std::string Print() override { return stateID; }
};

#endif // MainMenuState_HPP