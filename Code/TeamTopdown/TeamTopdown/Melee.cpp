#include "stdafx.h"
#include "Melee.h"

Melee::Melee(Vector2f position, Vector2f size, bool isSolid, float rotation) :
	Entity(position, size, isSolid),
	rotation(rotation)
{
	size = Vector2f(32, 16);
}

void Melee::update() {}

void Melee::draw(RenderWindow & w) {}