#include "stdafx.h"
#include "IntroState.hpp"
#include <iostream>

IntroState::IntroState(sf::RenderWindow & window, GameStateManager & gsm, ControlsInput & ci) :
	window(window),
	gsm(gsm),
	controlsInput(ci)
{
	view.setSize(Vector2f(640, 360));
	view.setCenter(Vector2f(320, 180));
	font1.loadFromFile("Lato-Black.ttf");
	text1.setString("INTRO STATE\n\n\n\n\n\nCreated by TeamTopdown\n\n\n\n\n\nPRESS SPACE OR ENTER TO SKIP");
	text1.setFont(font1);
	text1.setCharacterSize(100);
	text1.setScale(Vector2f(0.15, 0.15));
	text1.setFillColor(sf::Color::Red);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(Vector2f(view.getCenter().x, 10));
}

void IntroState::HandleInput()
{
	if (controlsInput.spaceKeyPressed || controlsInput.enterKeyPressed) {
		gsm.SetNext("TitleScreen");
		Reset();
	}

	// DEV quick switch game
	if (controlsInput.num1KeyPressed) {
		gsm.SetNext("Level1State");
		Reset();
	}
}

void IntroState::Update()
{
	gsm.SwitchState(); // switches state if a new state has been set.
}

void IntroState::Draw(sf::RenderWindow & window)
{
	window.setView(view);
	window.clear(sf::Color::Black);
	//background.draw(window);
	window.draw(text1);
	window.display();
}

void IntroState::Reset()
{
	// reset all values in state

}