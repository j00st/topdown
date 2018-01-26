#ifndef MENU_HPP
#define MENU_HPP

#include "stdafx.h"
#include "GameLoopObject.hpp"
#include "MenuButton.hpp"
#include <vector>

class Menu : public GameLoopObject {
private:
	sf::RenderWindow & window;
	sf::Vector2f position;
	std::vector<MenuButton *> listOfButtons;
	int amountOfButtons;
	bool isVisible;
public:
	Menu(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f buttonSize, std::vector<std::string> buttonNames, bool isVisible = 1, bool autoCalcWidth = 0);
	void HandleInput();
	void Update();
	void Draw(sf::RenderWindow & window);
	void Reset();
	void Show();
	void Hide();
	int GetAmountOfButtons();
	int FindKeyPress();
	bool IsVisible();
};
#endif // MENU_HPP