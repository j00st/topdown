#include "stdafx.h"
#include "EntityController.h"


EntityController::EntityController():
	player (PlayerTemp(Vector2f(32.0f, 128.0f), Vector2f(32.0f, 32.0f))),
	c (Crate(Vector2f(320.0f, 320.0f), Vector2f(64.0f, 64.0f)))
{}

void EntityController::update() {
	if (GetAsyncKeyState(87)) { //wKeyPressed
		Vector2f upwards(0.0f, -speed);
		//for (wall : walls) {
			if (!player.collidesWith(c, upwards)) {
				player.move(upwards);
			}
		//}
	}
	if (GetAsyncKeyState(83)) { //sKeyPressed
		Vector2f downwards(0.0f, speed);
		//for (wall : walls) {
		if (!player.collidesWith(c, downwards)) {
			player.move(downwards);
		}
		//}
	}
	if (GetAsyncKeyState(65)) { //aKeyPressed
		//for (wall : walls) {
		Vector2f leftwards(-speed, 0.0f);
		if (!player.collidesWith(c, leftwards)) {
			player.move(leftwards);
		}
		//}
	}
	if (GetAsyncKeyState(68)) { //dKeyPressed
		//for (wall : walls) {
		Vector2f rightwards(speed, 0.0f);
		if (!player.collidesWith(c, rightwards)) {
			player.move(rightwards);
		}
		//}
	}
	player.update();
}

void EntityController::draw(RenderWindow & w) {
	player.draw(w);
	c.draw(w);
}
