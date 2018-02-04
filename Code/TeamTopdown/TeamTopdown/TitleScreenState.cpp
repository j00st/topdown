#include "stdafx.h"
#include "TitleScreenState.hpp"
#include <iostream>

TitleScreenState::TitleScreenState(sf::RenderWindow & window, GameStateManager & gsm, ControlsInput & ci) :
	window(window), 
	gsm(gsm),
	controlsInput(ci)
{
	// sound effects
	SBload.loadFromFile("audio/soundeffects/loadgun.wav");
	SBshot.loadFromFile("audio/soundeffects/gunshot1.wav");
	SEload.setBuffer(SBload);
	SEshot.setBuffer(SBshot);

	view.setSize(Vector2f(640, 360));
	view.setCenter(Vector2f(320, 180));
	font1.loadFromFile("sprites/Lato-Black.ttf");
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
	if (switchingStates) {
		switchingStates = 0;
		gsm.SetNext("MainMenu");
		SEload.play();
		Sleep(600);
		SEshot.play();
		Sleep(400);
	}
	if (controlsInput.spaceKeyPressed || controlsInput.enterKeyPressed) {
		switchingStates = 1;
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
	if(!switchingStates) window.draw(text1);
	window.display();
}

void TitleScreenState::Reset() {}