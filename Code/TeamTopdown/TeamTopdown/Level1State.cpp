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

}

void Level1State::HandleInput()
{
	controlsCtrl.update();
	if (controlsInput.num2KeyPressed) {
		gsm.SetNext("MainMenu");
	}

}

void Level1State::Update()
{
	HandleInput();
	gsm.SwitchState();
	camera.update();
	controlsCtrl.update();
	entityCtrl.update();
}

void Level1State::Draw()
{
	window.clear();
	entityCtrl.draw(window);
	window.display();
}