#include "stdafx.h"
#include "Graphic.h"

Graphic::Graphic(String path, bool centerSprite)
{
	SetSprite(path, centerSprite);
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

void Graphic::SetSprite(std::string p, bool center)
{
	spriteTexture.loadFromFile(p);
	spriteTexture.setSmooth(false);
	sprite.setTexture(spriteTexture);
	sprite.setScale(Vector2f(2.0f, 2.0f));
	if (center) {
		Vector2f center = ((Vector2f)spriteTexture.getSize()) / 2.0f;
		sprite.setOrigin(center);
	}
}