#ifndef TestState2_HPP
#define TestState2_HPP

#include "stdafx.h"
#include "GameState.hpp"
#include <string>

class TestState2 : public GameState {
private:
	sf::RenderWindow & window;
	sf::Font font1;
	sf::Text text1;
public:
	TestState2(sf::RenderWindow & w);
	void HandleInput();
	void Update();
	void Draw();
};

#endif // TestState2_HPP