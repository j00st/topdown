#include "stdafx.h"
#include "Crate.h"


Crate::Crate(Vector2f position, Vector2f size, bool isSolid, bool hostile):
	Entity(position, size, isSolid, hostile)
{
	body.setPosition(position);
}

void Crate::update() {
	body.setPosition(position);
}

void Crate::draw(RenderWindow & w) {
	body.draw(w);
}