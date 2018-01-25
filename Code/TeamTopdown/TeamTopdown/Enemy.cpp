#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(Vector2f position, unsigned int waypointNr, Vector2f size, bool isSolid, Vector2f & lookatobject) :
	Entity(position, size, isSolid), lookAtObject(lookatobject)
{
	addWaypoint(position, waypointNr);
	hitbox = RectangleShape(size);
	hitbox.setFillColor(Color::Green);
}

void Enemy::addWaypoint(Vector2f pos, unsigned int number) {
	waypointMap.insert(std::pair<unsigned int, Vector2f>(number, pos));
	position = waypointMap.begin()->second;
}

void Enemy::createWaypointQueue() {
	std::map<unsigned int, Vector2f>::iterator it = waypointMap.begin();
	if (waypointMap.size() % 2 != 0) {
		while (it != waypointMap.end()) {
			waypoints.push(it->second);
			++it;
		}
		--it;
		while (--it != waypointMap.begin()) {
			waypoints.push(it->second);
		}
	} else {
		for (; it != waypointMap.end(); ++it) {
			waypoints.push(it->second);
		}
	}
	waypointMap.clear();
}
void Enemy::update()
{
	if (!waypoints.empty()) {
		if (position == waypoints.front() && waypoints.front() != waypoints.back()) {
			waypoints.push(position);
			waypoints.pop();
		}
		moveTowards(waypoints.front());
	}
	if (hasAggro) {
		//std::queue<Vector2f>().swap(waypoints); //clear waypoints
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

void Enemy::moveTowards(Vector2f direction) {
	direction -= position;
	direction *= (movementSpeed / sqrt(direction.x * direction.x + direction.y * direction.y));
	position += direction;
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