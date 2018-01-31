#include "stdafx.h"
#include "TitleScreenState.hpp"
#include <iostream>

TitleScreenState::TitleScreenState(sf::RenderWindow & window, GameStateManager & gsm, ControlsInput & ci) :
	window(window), 
	gsm(gsm),
	controlsInput(ci)
{
	view.setSize(Vector2f(640, 360));
	view.setCenter(Vector2f(320, 180));
	font1.loadFromFile("Lato-Black.ttf");
	text1.setString("Press SPACE or ENTER to begin\n");
	text1.setFont(font1);
	text1.setCharacterSize(100);
	text1.setScale(Vector2f(0.15, 0.15));
	text1.setFillColor(sf::Color::White);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(Vector2f(120, 312));
	background.setScale(Vector2f(1.0, 1.0));
}

void TitleScreenState::HandleInput()
{
	if (controlsInput.spaceKeyPressed || controlsInput.enterKeyPressed) {
		gsm.SetNext("MainMenu");
		Reset();
	}
}

void TitleScreenState::Update()
{
	gsm.SwitchState(); // switches state if a new state has been set.
}

void TitleScreenState::Draw(sf::RenderWindow & window)
{
	window.setMouseCursorVisible(false);
	window.setView(view);
	window.clear(sf::Color::Red);
	background.draw(window);
	window.draw(text1);
	window.display();
}

void TitleScreenState::Reset()
{

}