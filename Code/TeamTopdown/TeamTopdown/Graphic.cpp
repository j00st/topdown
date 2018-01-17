#include "stdafx.h"
#include "Graphic.h"


Graphic::Graphic(RenderWindow& w, String path):
	window(w)
{
	spriteTexture.loadFromFile(path);
	spriteTexture.setSmooth(false);
	sprite.setTexture(spriteTexture);
	sprite.setScale(Vector2f(2, 2));
}

void Graphic::draw(Vector2f pos)
{
	sprite.setPosition(pos);
	window.draw(sprite);
}