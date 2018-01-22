#include "stdafx.h"
#include "Level1State.hpp"
#include <iostream>


Level1State::Level1State(sf::RenderWindow & w, GameStateManager & gsm, ControlsInput & ci, EntityController & ec, Camera & cm, Cursor cr) :
	window(w),
	gsm(gsm),
	controlsInput(ci),
	entityCtrl(ec),
	camera(cm),
	cursor(cr)
{
	font1.loadFromFile("Lato-Black.ttf");
	text1.setString("Level1State");
	text1.setFont(font1);
	text1.setCharacterSize(30);
	text1.setFillColor(sf::Color::Yellow);
	text1.setStyle(sf::Text::Bold);
}

void Level1State::HandleInput()
{
	if (controlsInput.num1KeyPressed) {
		gsm.SetNext("MainMenuState");
		std::cout << "level1state switched state to mainmenustate\n";
		gsm.SwitchState();
	}
}

void Level1State::Update()
{
	HandleInput();
	camera.update();
	entityCtrl.update();
}

void Level1State::Draw()
{
	window.clear();
	entityCtrl.draw(window);
	window.display();
}