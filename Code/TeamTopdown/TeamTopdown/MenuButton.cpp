#include "stdafx.h"
#include "MenuButton.hpp"
#include <iostream>

MenuButton::MenuButton(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, std::string text, bool autoCalcWidth) :
	window(window)
{
	//rect1texture1 = buttontexture
	//rect1 = rectangle to draw button in (size, position, sprite)
	//rect1text = button text
	rect1texture1.loadFromFile("sprites/buttonStock1_2.png");
	rect1texture2.loadFromFile("sprites/buttonStock1h.png");
	rect1texture3.loadFromFile("sprites/buttonStock1d.png");
	rect1.setTexture(&rect1texture1);

	// text initialize font/string/char size
	font1.loadFromFile("Lato-Black.ttf"); // change arial black of idk wat
	rect1text.setFont(font1);
	rect1text.setString(text);
	rect1text.setCharacterSize(size.y / 2);

	// set button size
	rect1.setSize(size); // use in constructor specified size
	rect1.setPosition(position); // use in constructor specified position

	// ----- not working
	// auto calculate button/menu width and correct position
	if (autoCalcWidth) AutoCalcWidth(text);

	rect1text.setOrigin(rect1text.getLocalBounds().left + rect1text.getLocalBounds().width / 2.0f,
		rect1text.getLocalBounds().top + rect1text.getLocalBounds().height / 2.0f);
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
		isPressed = 1;
		std::cout << "pressed = " << isPressed << std::endl;
	}
}

void MenuButton::Update()
{
	if (isPressed) {
		isPressed = 0;
		std::cout << "pressed = " << isPressed << std::endl;
	}
}

void::MenuButton::Draw(sf::RenderWindow & window)
{
	window.draw(rect1);
	window.draw(rect1text);
}

void MenuButton::AutoCalcWidth(std::string str)
{
	rect1.setSize(sf::Vector2f(str.length() * rect1text.getCharacterSize(), rect1.getSize().y));
	//rect1.setPosition(sf::Vector2f(rect1.getPosition().x - rect1.getSize().x / 2.0f, rect1.getPosition().y));
}

void MenuButton::AutoCalcWidthMenu(std::string str)
{
	int prevSize = rect1.getSize().x;
	rect1.setSize(sf::Vector2f(str.length() * rect1text.getCharacterSize(), rect1.getSize().y));
	rect1.setPosition(sf::Vector2f(rect1.getPosition().x + prevSize / 2.0f - rect1.getSize().x / 2.0f, rect1.getPosition().y));
}

bool MenuButton::IsPressed()
{
	return isPressed;
}