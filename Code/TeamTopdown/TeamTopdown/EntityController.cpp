#include "stdafx.h"
#include "EntityController.h"


EntityController::EntityController():
	player (PlayerTemp(Vector2f(32.0f, 128.0f), Vector2f(32.0f, 32.0f)))
{
	upwards = Vector2f(0.0f, -player.speed);
	downwards = Vector2f(0.0f, player.speed);
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
	
	if (GetAsyncKeyState(87)) { //wKeyPressed
		if (!playerColliding(upwards)) {
			player.move(upwards);
		}
	}
	if (GetAsyncKeyState(83)) { //sKeyPressed
		if (!playerColliding(downwards)) {
			player.move(downwards);
		}
	}
	if (GetAsyncKeyState(65)) { //aKeyPressed
		if (!playerColliding(leftwards)) {
			player.move(leftwards);
		}
	}
	if (GetAsyncKeyState(68)) { //dKeyPressed
		if (!playerColliding(rightwards)) {
			player.move(rightwards);
		}
	}
	player.update();
}

void EntityController::draw(RenderWindow & w) {
	for (auto object : entities) {
		object->draw(w);
	}
	player.draw(w);
}
