#include "stdafx.h"
#include "Graphic.h"

Graphic::Graphic(String path, bool centerSprite)
{
	spriteTexture.loadFromFile(path);
	spriteTexture.setSmooth(false);
	sprite.setTexture(spriteTexture);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	sprite.setScale(Vector2f(2, 2));
=======
	//sprite.setScale(Vector2f(2.0f, 2.0f));
>>>>>>> refs/remotes/origin/master
=======
	sprite.setScale(Vector2f(2, 2));
>>>>>>> parent of 79a6ac8... Merge remote-tracking branch 'refs/remotes/origin/mapCollision' into Bullet
=======
	sprite.setScale(Vector2f(2, 2));
>>>>>>> parent of 79a6ac8... Merge remote-tracking branch 'refs/remotes/origin/mapCollision' into Bullet
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