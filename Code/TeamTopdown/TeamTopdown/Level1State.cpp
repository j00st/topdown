#include "stdafx.h"
#include "Level1State.hpp"
#include <iostream>


Level1State::Level1State(GameStateManager & gsm, ControlsInput & ci, Camera & cm, Cursor & c, Player & p) :
	gsm(gsm),
	controlsInput(ci),
	camera(cm),
	cursor(c),
	player(p),
	entityController(player, cursor, controlsInput, map)
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
	entityController.update();
}

void Level1State::Draw(sf::RenderWindow & window)
{
	window.clear(Color::Color(22, 23, 25));
	entityController.draw(window);
	window.display();
}