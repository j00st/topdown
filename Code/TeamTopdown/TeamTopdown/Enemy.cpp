#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(Vector2f position, Vector2f size, bool isSolid) :
	Entity(position, size, isSolid)
{
	hitbox = RectangleShape(size);
	hitbox.setFillColor(Color::Green);
}

void Enemy::update()
{
	enemySprite.setPosition(position);
	rotate();
}

void Enemy::rotate()
{
	enemySprite.rotate(rotation);
}

void Enemy::draw(RenderWindow &window)
{
	//hitbox.setPosition(position - Vector2f(size.x/2, size.y/2));
	//window.draw(hitbox);
	enemySprite.draw(window);
}

Vector2f Enemy::getPos()
{
	return position;
}