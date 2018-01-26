#include "stdafx.h"
#include "Menu.hpp"
#include <iostream>

Menu::Menu(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f buttonSize, std::vector<std::string> buttonNames, bool isVisible, bool autoCalcWidth) :
	window(window),
	position(position),
	isVisible(isVisible)
{
	
	if (autoCalcWidth) {
/*
		to auto calc size

			rect set size
			- text length * text char size
			rect set pos
			- update position
*/


		// calculate max string size and give fixed value for width
		int fixedWidth = 1;
		int length = 0;
		for (auto string : buttonNames) {
			if (length < string.length()) length = string.length();
		}

		// calculate width and give fixed value
	}
	// store new buttons in list of buttons
	for (int i = 0; i < buttonNames.size(); i++)
	{
		listOfButtons.push_back(new MenuButton(window, sf::Vector2f(position.x - buttonSize.x/2, position.y + buttonSize.y * i), buttonSize, buttonNames[i])); // , autoCalcWidth));
	}
	amountOfButtons = listOfButtons.size();

	std::cout << "menu class amount of buttons: " << amountOfButtons;




}

void Menu::HandleInput()
{
	if (isVisible) {
		for (auto button : listOfButtons) {
			button->HandleInput();
		}
	}
}

void Menu::Update()
{
	if (isVisible) {
		for (auto button : listOfButtons) {
			button->Update();
		}
	}
}

void Menu::Draw(sf::RenderWindow & w)
{
	if (isVisible) {
		for (auto button : listOfButtons) {
			button->Draw(w);
		}
	}
}

void Menu::Reset()
{
	for (auto button : listOfButtons){
		button->Reset();
	}
}

void Menu::Show()
{
	isVisible = 1;
}

void Menu::Hide()
{
	isVisible = 0;
}

int Menu::GetAmountOfButtons()
{
	return amountOfButtons;
}

int Menu::FindKeyPress()
{
	int pressedButton = 0;
	int pressedButtonIterator = 0;
	for (auto button : listOfButtons) {
		pressedButtonIterator++;
		if (button->IsPressed()) {
			pressedButton = pressedButtonIterator;
		}
	}
	pressedButtonIterator = 0;
	return pressedButton;
}


bool Menu::IsVisible()
{
	return isVisible;
}
