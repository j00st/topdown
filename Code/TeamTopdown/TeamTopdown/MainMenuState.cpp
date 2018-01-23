#include "stdafx.h"
#include "MainMenuState.hpp"
#include <iostream>


MainMenuState::MainMenuState(sf::RenderWindow & w, GameStateManager & gsm, ControlsInput & ci) :
	window(w),
	gsm(gsm),
	controlsInput(ci)
{
	font1.loadFromFile("Lato-Black.ttf");
	text1.setString("SUP PEEPS DIS IS MAIN MENU\n\
		Press 1 to switch to the game.\n\
		Press 2 to return to main menu.\n\n\
		Op het moment hebben we een bug met de zoom/camera die niet gereset wordt bij terugkeren naar main menu.\n\
		Niks game breaking tho.");
	text1.setFont(font1);
	text1.setCharacterSize(30);
	text1.setFillColor(sf::Color::Green);
	text1.setStyle(sf::Text::Bold);
}

void MainMenuState::HandleInput()
{
	if (controlsInput.num1KeyPressed) {
		gsm.SetNext("Level1State");
	}	
}

void MainMenuState::Update()
{
	gsm.SwitchState(); // switches state if a new state has been set.
}

void MainMenuState::Draw()
{
	window.clear(sf::Color::Red);
	window.draw(text1);
	window.display();
}