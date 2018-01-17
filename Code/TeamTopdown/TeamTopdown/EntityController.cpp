#include "stdafx.h"
#include "EntityController.h"


EntityController::EntityController():
	p (PlayerTemp(Vector2f(32.0f, 32.0f), Vector2f(32.0f, 32.0f))),
	c (Crate(Vector2f(64.5f, 64.0f), Vector2f(64.0f, 64.0f)))
{}

void EntityController::update() {
	if (true) { //wKeyPressed
		//for (wall : walls) {
			if (!p.collidesWith(c, Vector2f(0.0f, -speed))) {
				p.move(Vector2f(0.0f, -speed));
			}
		//}
	}
	p.update();
}

void EntityController::draw(RenderWindow & w) {
	p.draw(w);
	c.draw(w);
}
