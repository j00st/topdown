#include "stdafx.h"
#include "MainMenuState.hpp"
#include <iostream>


MainMenuState::MainMenuState(sf::RenderWindow & w, ControlsInput & ci, GameStateManager &gsm) : 
	window(w),
	controlsInput(ci),
	gsm(gsm)
{
	font1.loadFromFile("Lato-Black.ttf");
	text1.setString("SUP PEEPS DIS IS MAIN MENU");
	text1.setFont(font1);
	text1.setCharacterSize(30);
	text1.setFillColor(sf::Color::Green);
	text1.setStyle(sf::Text::Bold);
}

void MainMenuState::HandleInput()
{
	if (controlsInput.wKeyPressed) {
		gsm.SetNext("Level1State");
		std::cout << "mainmenustate switched state to level1state\n";
		gsm.SwitchState();
	}
}

void MainMenuState::Update()
{
	HandleInput();
}

void MainMenuState::Draw()
{
	//std::cout << "MainMenuState draw() called\n";
	window.clear(sf::Color::Red);
	window.draw(text1);
	window.display();
}