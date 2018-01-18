#include "stdafx.h"
#include "EntityController.h"

EntityController::EntityController(Player &p, ControlsInput &ci):
	player (p),
	ci (ci)
{
	upwards = Vector2f(0.0f, player.speed);
	downwards = Vector2f(0.0f, -player.speed);
	leftwards = Vector2f(-player.speed, 0.0f);
	rightwards = Vector2f(player.speed, 0.0f);
}

bool EntityController::playerColliding(Vector2f direction) {
	for (auto const object : entities) {
		if (object->isSolid && player.collidesWith(*object, direction)) {
			return true;
		}
	}
	return false;
}
void EntityController::update() {
	
	if (ci.wKeyPressed) { //wKeyPressed
		if (!playerColliding(upwards)) {
			player.move(upwards);
		}
	}
	if (ci.sKeyPressed) { //sKeyPressed
		if (!playerColliding(downwards)) {
			player.move(downwards);
		}
	}
	if (ci.aKeyPressed) { //aKeyPressed
		if (!playerColliding(leftwards)) {
			player.move(leftwards);
		}
	}
	if (ci.dKeyPressed) { //dKeyPressed
		if (!playerColliding(rightwards)) {
			player.move(rightwards);
		}
	}
	player.update();
}

void EntityController::draw(RenderWindow & w) {
	background.draw(w);
	for (auto object : entities) {
		object->draw(w);
	}
	player.draw(w);
}
