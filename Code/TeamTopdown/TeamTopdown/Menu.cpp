#include "stdafx.h"
#include "Menu.hpp"
#include <iostream>

Menu::Menu(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f buttonSize, std::vector<std::string> buttonNames, bool isVisible) :
	window(window),
	position(position),
	isVisible(isVisible)
{

	// store new buttons in list of buttons
	for (int i = 0; i < buttonNames.size(); i++)
	{
		listOfButtons.push_back(new MenuButton(window, sf::Vector2f(position.x - buttonSize.x/2, position.y + buttonSize.y * i), buttonSize, buttonNames[i]));
	}
	amountOfButtons = listOfButtons.size();

	std::cout << "menu class amount of buttons: " << amountOfButtons;




}

void Menu::HandleInput()
{
	for (auto button : listOfButtons)
	{
		button->HandleInput();
	}
}

void Menu::Update()
{
	for (auto button : listOfButtons)
	{
		button->Update();
	}
}

void Menu::Draw(sf::RenderWindow & w)
{
	for (auto button : listOfButtons)
	{
		button->Draw(w);
	}
}

void Menu::Reset()
{
	for (auto button : listOfButtons)
	{
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

bool Menu::IsVisible()
{
	return isVisible;
}