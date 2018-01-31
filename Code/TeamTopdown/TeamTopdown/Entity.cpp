#include "stdafx.h"
#include "Entity.h"

Entity::Entity(Vector2f position, Vector2f size, bool isSolid, int state, bool hostile):
	position (position),
	size (size),
	isSolid(isSolid),
	state(state),
	hostile(hostile)
{}

void Entity::move(Vector2f delta) {
	position += delta;
}

bool Entity::collidesWith(Entity *other, Vector2f delta) {
	Vector2f newPos(other->position  + delta);
	if (position.x < newPos.x + other->size.x &&
		position.x + size.x > newPos.x &&
		position.y < newPos.y + other->size.y &&
		position.y + size.y > newPos.y) {
		return true;
	}
	return false;
}