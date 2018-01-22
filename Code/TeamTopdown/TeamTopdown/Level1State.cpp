#include "stdafx.h"
#include "Level1State.hpp"
#include <iostream>


Level1State::Level1State(sf::RenderWindow & w, GameStateManager & gsm, ControlsController & cc, ControlsInput & ci, EntityController & ec, Camera & cm, Cursor cr) :
	window(w),
	gsm(gsm),
	controlsCtrl(cc),
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

	controlsCtrl.update();
	if (controlsInput.aKeyPressed) {
		gsm.SetNext("MainMenuState");
		std::cout << "level1state switched state to mainmenustate\n";
	}

}

void Level1State::Update()
{
	gsm.SwitchState();
	camera.update();
	controlsCtrl.update();
	entityCtrl.update();
}

void Level1State::Draw()
{
	window.clear();
	//window.clear(sf::Color::Blue);
	//window.draw(text1);
	//window.draw(mouseObject);
	entityCtrl.draw(window);
	window.display();
}