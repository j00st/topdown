#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(Vector2f position, unsigned int waypointNr, Vector2f size, bool isSolid, bool hostile, Vector2f & lookatobject) :
	Entity(position, size, isSolid, hostile), lookAtObject(lookatobject)
{
	addWaypoint(position, waypointNr);
	hitbox = RectangleShape(size);
	hitbox.setFillColor(Color::Green);
}

void Enemy::addWaypoint(Vector2f pos, unsigned int number) {
	waypoints.insert(std::pair<unsigned int, Vector2f>(number, pos));
	position = waypoints.begin()->second;
}
void Enemy::update()
{
	Time elapsed1 = clock.getElapsedTime();
	std::cout << (std::rand() % 800 - 400) << ' ';
	if (elapsed1.asMilliseconds() > 1000 - (std::rand() % 800 - 400))
	{
		hostile = true;
		clock.restart();
	}
	else
	{
		hostile = false;
	}
	enemySprite.setPosition(position);
	rotate();
}

void Enemy::rotate()
{
	rotation = atan2(lookAtObject.y - position.y, lookAtObject.x - position.x);
	rotation = rotation * (float(180.0) / float(3.141592653589793238463)); // transform radian to degree
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