#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(Vector2f position, unsigned int waypointNr, Vector2f size, bool isSolid) :
	Entity(position, size, isSolid)
{
	addWaypoint(position, waypointNr);
	hitbox = RectangleShape(size);
	hitbox.setFillColor(Color::Green);
}

void Enemy::addWaypoint(Vector2f pos, unsigned int number) {
	waypoints.insert(std::pair<unsigned int, Vector2f>(number, position));
	position = waypoints.begin()->second;
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