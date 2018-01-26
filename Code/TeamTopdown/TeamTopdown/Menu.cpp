#include "stdafx.h"
#include "Menu.hpp"
#include <iostream>

Menu::Menu(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, std::string[], bool isVisible) :
	window(window),
	isVisible(isVisible)
{

}

void Menu::HandleInput()
{

}

void Menu::Update()
{

}

void Menu::Draw()
{

}

void Menu::Reset()
{

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