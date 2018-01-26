#ifndef MENU_HPP
#define MENU_HPP

#include "stdafx.h"
#include "GameLoopObject.hpp"
#include "MenuButton.hpp"

class Menu : public GameLoopObject {
private:
	sf::RenderWindow & window;
	sf::Vector2f position;
	int amountOfButtons;


	bool isVisible = 0;

public:
	Menu(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, std::string[], bool isVisible = 0);
	void HandleInput();
	void Update();
	void Draw();
	void Reset();
	void Show();
	void Hide();
	bool IsVisible();
};
#endif // MENU_HPP