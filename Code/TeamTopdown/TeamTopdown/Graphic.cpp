#include "stdafx.h"
#include "Graphic.h"

Graphic::Graphic(String path, bool centerSprite)
{
	spriteTexture.loadFromFile(path);
	spriteTexture.setSmooth(false);
	sprite.setTexture(spriteTexture);
	//sprite.setScale(Vector2f(2.0f, 2.0f));
	if (centerSprite) {
		Vector2f center = ((Vector2f)spriteTexture.getSize()) / 2.0f;
		sprite.setOrigin(center);
	}
}

void Graphic::rotate(float rotation)
{
	sprite.setRotation(rotation);
}

void Graphic::setPosition(Vector2f pos) {
	sprite.setPosition(pos);
}

void Graphic::setScale(Vector2f scale) {
	sprite.setScale(scale);
}
void Graphic::draw(RenderWindow &w) {
	w.draw(sprite);
}