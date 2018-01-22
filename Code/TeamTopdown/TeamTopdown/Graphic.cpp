#include "stdafx.h"
#include "Graphic.h"

Graphic::Graphic(String path, bool centerSprite)
{
	spriteTexture.loadFromFile(path);
	spriteTexture.setSmooth(false);
	sprite.setTexture(spriteTexture);
<<<<<<< HEAD
	sprite.setScale(Vector2f(2, 2));
=======
	//sprite.setScale(Vector2f(2.0f, 2.0f));
>>>>>>> refs/remotes/origin/master
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

void Graphic::setScale(Vector2f scale) {
	sprite.setScale(scale);
}
void Graphic::draw(RenderWindow &w) {
	w.draw(sprite);
}