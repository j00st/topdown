#include "stdafx.h"
#include "ClickableButton.hpp"
#include <iostream>

ClickableButton::ClickableButton(
	sf::RenderWindow & window, 
	sf::Vector2f position, 
	sf::Vector2f size, 
	std::string text, 
	bool autoCalcWidth) :
	window(window)
{
	// sound effects
	SEhighlightBuffer.loadFromFile("audio/FGBS(4).wav");
	SEclickBuffer.loadFromFile("audio/FGBS(36)_2.wav");
	SEhighlight.setBuffer(SEhighlightBuffer);
	SEclick.setBuffer(SEclickBuffer);

	//rect1texture1 = buttontexture
	//rect1 = rectangle to draw button in (size, position, sprite)
	//rect1text = button text
	rect1texture1.loadFromFile("sprites/buttonStock1_2.png");
	rect1texture2.loadFromFile("sprites/buttonStock1h_2.png");
	rect1texture3.loadFromFile("sprites/buttonStock1d_2.png");
	rect1.setTexture(&rect1texture1);

	// text initialize font/string/char size
	font1.loadFromFile("Lato-Black.ttf"); // change arial black of idk wat
	rect1text.setFont(font1);
	rect1text.setString(text);
	rect1text.setCharacterSize(size.y / 2);
	//rect1text.setCharacterSize(50);
	//rect1text.setScale(0.15, 0.15);

	// set button size
	rect1.setSize(size); // use in constructor specified size
	rect1.setPosition(position); // use in constructor specified position

	// ----- not working
	// auto calculate button/menu width and correct position
	if (autoCalcWidth) AutoCalcWidth(text);

	// place text in the centre of the button.
	rect1text.setOrigin(
		rect1text.getLocalBounds().left + rect1text.getLocalBounds().width / 2.0f, 
		rect1text.getLocalBounds().top + rect1text.getLocalBounds().height / 2.0f);
	rect1text.setPosition(
		rect1.getPosition().x + (rect1.getSize().x / 2.0f),
		rect1.getPosition().y + (rect1.getSize().y / 2.0f));
}

void ClickableButton::HandleInput()
{
	// if hovering and lmb is newly pressed
	// --> change sprite to DOWN
	if (rect1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left)
		&& leftMouseButtonPreviouslyPressed == 0)
	{
		leftMouseButtonPreviouslyPressed = 1;
		mouseIsHovering = 1;
		rect1.setTexture(&rect1texture3);
	}

	// if hovering and mouse is not pressed 
	// --> highlight
	// if hover + not pressed --> highlight
	else if (rect1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))
		&& !sf::Mouse::isButtonPressed(sf::Mouse::Left)
		&& mouseIsHovering == 0
		&& leftMouseButtonPreviouslyPressed == 0)
	{
		mouseIsHovering = 1;
		//leftMouseButtonPreviouslyPressed = 0;
		rect1.setTexture(&rect1texture2);
		// PLAY HIGHLIGHT SOUND
		SEhighlight.play();
	}

	// if not hovering anymore --> normal
	else if (!rect1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))
		&& mouseIsHovering == 1)
		//&& leftMouseButtonPreviouslyPressed == 0)
	{
		rect1.setTexture(&rect1texture1);
		mouseIsHovering = 0;
		leftMouseButtonPreviouslyPressed = 0;
	}

	// if pressed + still holding --> keep holding
	else if (leftMouseButtonPreviouslyPressed == 1
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (detectCounter == 1)
		{
			detectCounter++;
		}
		else if (detectCounter < 60) detectCounter++;
		else if (detectCounter >= 60) detectCounter = 1;
	}

	// if hover + pressed + released --> do action
	else if (leftMouseButtonPreviouslyPressed == 1
		&& !sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		rect1.setTexture(&rect1texture1);
		leftMouseButtonPreviouslyPressed = 0;
		mouseIsHovering = 0;
		isPressed = 1; // TRIGGERS ACTION
		// PLAY TRIGGER SOUND
		SEclick.play();
	}
}

void ClickableButton::Update()
{
	// not needed
}

void::ClickableButton::Draw(sf::RenderWindow & window)
{
	window.draw(rect1);
	window.draw(rect1text);
}

void::ClickableButton::Reset()
{
	// not yet implemented.
}

void ClickableButton::AutoCalcWidth(std::string str)
{
	rect1.setSize(
		sf::Vector2f(str.length() * rect1text.getCharacterSize(), 
		rect1.getSize().y));
	//rect1.setPosition(sf::Vector2f(rect1.getPosition().x - rect1.getSize().x / 2.0f, rect1.getPosition().y));
}

void ClickableButton::AutoCalcWidthMenu(std::string str)
{
	int prevSize = rect1.getSize().x;
	rect1.setSize(sf::Vector2f(
		str.length() * rect1text.getCharacterSize(), 
		rect1.getSize().y));
	rect1.setPosition(sf::Vector2f(
		rect1.getPosition().x + prevSize / 2.0f - rect1.getSize().x / 2.0f, 
		rect1.getPosition().y));
}

int ClickableButton::GetWidth()
{
	return rect1.getSize().x;
}

bool ClickableButton::IsPressed()
{
	if (isPressed) {
		isPressed = 0;
		return 1;
	}
	return 0;
}

void ClickableButton::RepositionToCenter(sf::Vector2f screenOrigin, int height)
{
	rect1.setOrigin(sf::Vector2f(
		rect1.getSize().x / 2.0f, 0));
	rect1.setPosition(sf::Vector2f(
		screenOrigin.x,
		screenOrigin.y + height));
	rect1text.setPosition(sf::Vector2f(
		screenOrigin.x,
		screenOrigin.y + height + (rect1.getSize().y / 2.0f)));
}