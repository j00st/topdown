#include "stdafx.h"
#include "Entity.h"

Entity::Entity(sf::Vector2f position, sf::Vector2f size, bool isSolid):
	position (position),
	size (size),
	isSolid(isSolid)
{}

void Entity::move(sf::Vector2f delta) {
	position += delta;
}

bool Entity::collidesWith(Entity *other, sf::Vector2f delta) {
	sf::Vector2f newPos(position - size / 2.0f + delta);
	if (newPos.x < other->position.x + other->size.x &&
		newPos.x + size.x > other->position.x &&
		newPos.y < other->position.y + other->size.y &&
		newPos.y + size.y > other->position.y) {
		return true;
	}
	return false;
}