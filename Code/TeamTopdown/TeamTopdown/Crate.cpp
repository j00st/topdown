#include "stdafx.h"
#include "Crate.h"


Crate::Crate(Vector2f position, Vector2f size, bool isSolid):
	Entity(position, size, isSolid)
{
	body.setPosition(position);
}

void Crate::update() {
	body.setPosition(position);
}

void Crate::draw(RenderWindow & w) {
	body.draw(w);
}