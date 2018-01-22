#include "stdafx.h"
#include "Graphic.h"

Graphic::Graphic(String path, bool centerSprite)
{
	spriteTexture.loadFromFile(path);
	spriteTexture.setSmooth(false);
	sprite.setTexture(spriteTexture);
	sprite.setScale(Vector2f(4, 4));
	if (centerSprite) {
		sprite.setOrigin(Vector2f(8, 8));
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