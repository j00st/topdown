#include "stdafx.h"
#include "Level1State.hpp"
#include <iostream>


Level1State::Level1State(GameStateManager & gsm, ControlsInput & ci, EntityController & ec, Camera & cm) :
	gsm(gsm),
	controlsInput(ci),
	entityCtrl(ec),
	camera(cm)
{

}

void Level1State::HandleInput()
{
	if (controlsInput.num2KeyPressed) {
		gsm.SetNext("MainMenu");
	}

}

void Level1State::Update()
{
	gsm.SwitchState();
	camera.update();
	entityCtrl.update();
}

void Level1State::Draw(sf::RenderWindow & window)
{
	window.clear();
	entityCtrl.draw(window);
	window.display();
}