#include "stdafx.h"
#include "Level1State.hpp"
#include <iostream>


Level1State::Level1State(GameStateManager & gsm, ControlsInput & ci, Camera & cm, Cursor & c, Player & p) :
	gsm(gsm),
	controlsInput(ci),
	camera(cm),
	cursor(c),
	player(p),
	map(Map("sprites/map0.png", "sprites/map0s.png", "sprites/map0c.png", player)),
	entityController(player, cursor, controlsInput, map)
{
}

void Level1State::HandleInput()
{
	if (controlsInput.num2KeyPressed) {
		gsm.SetNext("MainMenu");
	}
	if (int nextLevel = entityController.exiting()) {
		gsm.SetNext("Level" + std::to_string(nextLevel) + "State");
	}
}

void Level1State::Update()
{
	camera.setTimer(entityController.shakeTimer);
	gsm.SwitchState();
	entityController.update();
	camera.update();
}

void Level1State::Draw(sf::RenderWindow & window)
{
	window.clear(Color::Color(22, 23, 25));
	entityController.draw(window);
	window.display();
}