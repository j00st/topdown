#include "stdafx.h"
#include "MainMenuState.hpp"
#include <iostream>


MainMenuState::MainMenuState(sf::RenderWindow & w, ControlsController &cc, ControlsInput & ci, GameStateManager &gsm) : 
	window(w),
	controlsCtrl(cc),
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
	controlsCtrl.update(); // update input of keyboard/mouse
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