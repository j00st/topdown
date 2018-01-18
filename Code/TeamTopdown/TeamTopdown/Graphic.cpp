#include "stdafx.h"
#include "Graphic.h"

Graphic::Graphic(String path, bool centerSprite)
{
	spriteTexture.loadFromFile(path);
	spriteTexture.setSmooth(false);
	sprite.setTexture(spriteTexture);
	sprite.setScale(Vector2f(2, 2));
	if (centerSprite) {
		sprite.setOrigin(Vector2f(16, 16));
	}
}

void Graphic::rotate(float rotation)
{
	
	sprite.setRotation(rotation);
}

void Graphic::setPosition(Vector2f pos) {
	sprite.setPosition(pos);
}

void Graphic::draw(RenderWindow &w) {
	w.draw(sprite);
}