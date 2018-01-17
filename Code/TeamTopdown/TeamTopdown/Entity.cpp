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
	//((position + delta), size);
	//FloatRect AABB = FloatRect(position, size);
	Vector2f newPos(position.x + delta.x, position.y + delta.y);
	FloatRect AABB ((float)newPos.x, (float)newPos.y, (float)size.x, (float)size.y);
	FloatRect otherAABB ((float) other.position.x, (float) other.position.y, (float) other.size.x, (float) other.size.y);
	return ((AABB.intersects(otherAABB)) ? true : false);
	return true;
}