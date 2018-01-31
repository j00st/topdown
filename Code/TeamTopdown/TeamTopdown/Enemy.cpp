#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(Vector2f position, unsigned int waypointNr, Vector2f size, bool isSolid, int state, bool hostile, Vector2f & playerPos, Vector2f initLookAtObj) :
	Entity(position, size, isSolid, state, hostile),
	playerPos(playerPos),
	initLookAtObj(initLookAtObj)
{
	enemySprite.setPosition(position);
	addWaypoint(position, waypointNr);
	//hitbox = RectangleShape(size);
	//hitbox.setFillColor(Color::Green);
}

void Enemy::addWaypoint(Vector2f pos, unsigned int number) {
	waypointMap.insert(std::pair<unsigned int, Vector2f>(number, pos));
	position = waypointMap.begin()->second;
}

void Enemy::createWaypointQueue() {
	std::map<unsigned int, Vector2f>::iterator it = waypointMap.begin();
	if (waypointMap.size() == 1) {
		waypoints.push(it->second);
		lookAtObject = it->second + initLookAtObj;
	} else if (waypointMap.size() % 2 != 0) {
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

Entity* Enemy::hit()
{
	state = states::dead;
	enemySprite.SetSprite(spriteStates[1]);
	isSolid = false;
	return nullptr;
}

void Enemy::update()
{
	hitbox.setPosition(position - Vector2f(size.x / 2, size.y / 2));
	if (state == states::patrolling) {
		if (waypoints.size() > 1) {
			if (position == waypoints.front()) {
				if (waypoints.front() != waypoints.back()) {
					waypoints.push(position);
				}
				waypoints.pop();
			}
			moveTowards(waypoints.front());
			lookAtObject = waypoints.front();
		}
		Vector2f delta = playerPos - position;
		/*if (aggroRange > sqrt(delta.x * delta.x + delta.y * delta.y)) {
			state = states::alarmed;
		}*/
	}
	if (state == states::alarmed) {
		//std::queue<Vector2f>().swap(waypoints); //clear waypoints
		lookAtObject = playerPos;
	}
	rotate();
	enemySprite.setPosition(position + Vector2f(8.0f, 8.0f));
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
	enemySprite.draw(window);
}

Vector2f Enemy::getPos()
{
	return position;
}

Vector2f Enemy::getLookAtObj()
{
	return lookAtObject;
}