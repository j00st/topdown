#include "stdafx.h"
#include "CreditsState.hpp"
#include <iostream>

CreditsState::CreditsState(sf::RenderWindow & window, GameStateManager & gsm, ControlsInput & ci) :
	window(window),
	gsm(gsm),
	controlsInput(ci)
{
	view.setSize(Vector2f(640, 360));
	view.setCenter(Vector2f(320, 180));
	font1.loadFromFile("Lato-Black.ttf");
	text1.setString("CREDITS STATE\n\nGUNOUT MADE BY\nMichel Baartman\nJoost van Lingen\nDylan Rakiman\nRuben Rajan\nBart Commandeur\n\nPress SPACE or ENTER to exit.");
	text1.setFont(font1);
	text1.setCharacterSize(100);
	text1.setScale(Vector2f(0.15, 0.15));
	text1.setFillColor(sf::Color::Red);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(Vector2f(120, 50));
}

void CreditsState::HandleInput()
{
	if (controlsInput.spaceKeyPressed || controlsInput.enterKeyPressed || controlsInput.backspaceKeyPressed) {
		gsm.SetNext("MainMenu");
		Reset();
	}
}

void CreditsState::Update()
{
	gsm.SwitchState(); // switches state if a new state has been set.
}

void CreditsState::Draw(sf::RenderWindow & window)
{
	window.setMouseCursorVisible(false);
	window.setView(view);
	window.clear(sf::Color::Black);
	//background.draw(window);
	window.draw(text1);
	window.display();
}

void CreditsState::Reset()
{
	// reset all values in state

}