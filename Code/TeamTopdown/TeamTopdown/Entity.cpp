#include "stdafx.h"
#include "Entity.h"

Entity::Entity(Vector2f position, Vector2f size, bool isSolid):
	position (position),
	size (size),
	isSolid(isSolid)
{}

void Entity::move(Vector2f delta) {
	position += delta;
}

bool Entity::collidesWith(Entity &other, Vector2f delta) {
	Vector2f newPos(position - size / 2.0f + delta);
	if (newPos.x < other.position.x + other.size.x &&
		newPos.x + size.x > other.position.x &&
		newPos.y < other.position.y + other.size.y &&
		newPos.y + size.y > other.position.y) {
		return true;
	}
	return false;
}