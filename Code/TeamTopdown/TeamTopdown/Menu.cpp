#include "stdafx.h"
#include "Menu.hpp"
#include <iostream>

Menu::Menu(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f buttonSize, std::vector<std::string> buttonNames, bool isVisible) :
	window(window),
	position(position),
	isVisible(isVisible)
{

	//sf::Vector2f tempPos(0, 0);
	//float x = 0;
	//float y = 0; 
	for (int i = 0; i < buttonNames.size(); i++)
	{/*
		x = position.x;
		y = position.y + buttonSize.y * i;
		tempPos.x = x;
		tempPos.y = y;*/
		listOfButtons.push_back(new MenuButton(window, sf::Vector2f(position.x, position.y + buttonSize.y * i), buttonSize, buttonNames[i]));
	}
	amountOfButtons = listOfButtons.size();


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

void Menu::Draw()
{
	for (auto button : listOfButtons)
	{
		button->Draw(window);
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