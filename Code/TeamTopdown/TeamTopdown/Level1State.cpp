#include "stdafx.h"
#include "Level1State.hpp"
#include <iostream>


Level1State::Level1State(GameStateManager & gsm, ControlsInput & ci, EntityController & ec, Player & p, Camera & cm) :
	gsm(gsm),
	controlsInput(ci),
	entityCtrl(ec),
	player(p),
	camera(cm)
{

}

void Level1State::HandleInput()
{
	if (controlsInput.num2KeyPressed) {
		gsm.SetNext("MainMenu");
	}
	player.HandleInput();

}

void Level1State::Update()
{
	gsm.SwitchState();
	camera.update();
	entityCtrl.update();
	player.update();
}

void Level1State::Draw(sf::RenderWindow & window)
{
	window.clear();
	entityCtrl.draw(window);
	player.draw(window);
	window.display();
}