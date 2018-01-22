#include "stdafx.h"
#include "EntityController.h"

EntityController::EntityController(Player &p, ControlsInput &ci):
	player (p),
	ci (ci)
{
	//background.setScale(Vector2f(2.0f, 2.0f));
	upwards = Vector2f(0.0f, player.speed);
	downwards = Vector2f(0.0f, -player.speed);
	leftwards = Vector2f(-player.speed, 0.0f);
	rightwards = Vector2f(player.speed, 0.0f);
}

bool EntityController::playerColliding(Vector2f direction) {
	//for (std::vector<Entity*>::iterator obj = entities.begin(); obj != entities.end(); ++obj) {
	for (auto entity : entities) {
		if (entity->isSolid && player.collidesWith(entity, direction)) {
			return true;
		}
	}
	return false;
}
void EntityController::update() {
	
	if (ci.wKeyPressed) { //wKeyPressed
		if (!playerColliding(upwards)) {
			player.move(upwards);
			cursor.update(upwards);
		}
	}
	if (ci.sKeyPressed) { //sKeyPressed
		if (!playerColliding(downwards)) {
			player.move(downwards);
			cursor.update(downwards);
		}
	}
	if (ci.aKeyPressed) { //aKeyPressed
		if (!playerColliding(leftwards)) {
			player.move(leftwards);
			cursor.update(leftwards);
		}
	}
	if (ci.dKeyPressed) { //dKeyPressed
		if (!playerColliding(rightwards)) {
			player.move(rightwards);
			cursor.update(rightwards);
		}
	}
	player.update();
}

void EntityController::draw(RenderWindow & w) {
	background.draw(w);
	for (auto entity : entities) {
		entity->draw(w);
	}
	player.draw(w);
	cursor.draw(w);
}
