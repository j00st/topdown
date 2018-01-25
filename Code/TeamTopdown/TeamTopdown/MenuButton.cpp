#include "stdafx.h"
#include "MenuButton.hpp"
#include <iostream>

MenuButton::MenuButton(sf::RenderWindow & window) :
	window(window)
{
	rect1texture1.loadFromFile("sprites/buttonStock1.png");
	rect1texture2.loadFromFile("sprites/buttonStock1h.png");
	rect1texture3.loadFromFile("sprites/buttonStock1d.png");
	rect1.setSize(sf::Vector2f(300, 200));
	rect1.setPosition(100, 200);
	rect1.setTexture(&rect1texture1);
	font1.loadFromFile("Lato-Black.ttf"); // change arial black of idk wat
	rect1text.setFont(font1);
	rect1text.setString("Inventory");
	textRect = rect1text.getLocalBounds(); // used to calculate test position
	rect1text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	rect1text.setPosition(rect1.getPosition().x + (rect1.getSize().x / 2.0f),
		rect1.getPosition().y + (rect1.getSize().y / 2.0f));
}

void MenuButton::HandleInput()
{
	// if hover + pressed
	if (rect1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left)
		&& mouseHoldBool == 0)
	{
		std::cout << "pressed" << std::endl;
		mouseHoldBool = 1;
		hoverCheckBool = 1;
		rect1.setTexture(&rect1texture3);
	}

	// if hover + not pressed --> highlight
	else if (rect1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))
		&& !sf::Mouse::isButtonPressed(sf::Mouse::Left)
		&& hoverCheckBool == 0
		&& mouseHoldBool == 0)
	{
		std::cout << "highlight" << std::endl;
		hoverCheckBool = 1;
		mouseHoldBool = 0;
		rect1.setTexture(&rect1texture2);
	}

	// if not hovering anymore --> normal
	else if (!rect1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))
		&& hoverCheckBool == 1
		&& mouseHoldBool == 0)
	{
		std::cout << "highlight reset" << std::endl;
		rect1.setTexture(&rect1texture1);
		hoverCheckBool = 0;
	}

	// if pressed + still holding --> keep holding
	else if (mouseHoldBool == 1
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (detectCounter == 1)
		{
			std::cout << "still holding" << std::endl;
			detectCounter++;
		}
		else if (detectCounter < 60) detectCounter++;
		else if (detectCounter >= 60) detectCounter = 1;
	}

	// if hover + pressed + released --> do action
	else if (mouseHoldBool == 1
		&& !sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		std::cout << "BUTTON ACTIVATE" << std::endl;
		rect1.setTexture(&rect1texture1);
		mouseHoldBool = 0;
		hoverCheckBool = 0;
		// do action
		pressed = 1;
	}
}

void MenuButton::Update()
{

}

void::MenuButton::Draw(sf::RenderWindow & window)
{
	window.draw(rect1);
	window.draw(rect1text);
}

bool MenuButton::OnPress()
{
	return pressed;
}