#include "stdafx.h"
#include "Graphic.h"

Graphic::Graphic(RenderWindow& w, String path):
	window(w)
{
	spriteTexture.loadFromFile(path);
	spriteTexture.setSmooth(false);
	sprite.setTexture(spriteTexture);
	sprite.setScale(Vector2f(2, 2));
	sprite.setOrigin(Vector2f(16, 16));
}

void Graphic::rotate(float rotation)
{
	sprite.setRotation(rotation);
}

void Graphic::draw(Vector2f pos)
{
	sprite.setPosition(pos);
	window.draw(sprite);
}