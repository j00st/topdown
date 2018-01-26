#include "stdafx.h"
#include "Crate.h"


Crate::Crate(Vector2f position, Vector2f size, bool isSolid, int state):
	Entity(position, size, isSolid, state)
{
	body.setPosition(position);
}

void Crate::update() {
	body.setPosition(position);
}

void Crate::draw(RenderWindow & w) {
	body.draw(w);
}