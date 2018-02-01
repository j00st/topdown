#include "stdafx.h"
#include "Turret.h"


Turret::Turret(Vector2f position, Vector2f size, Vector2f lookAtObject, int framesBetweenShots, bool isSolid):
	Entity(position, size, isSolid, states::alive),
	shootDirection (lookAtObject),
	bulletTimer (framesBetweenShots)
{
	turret.setPosition(position);
	if (shootDirection == Vector2f(0, 1)) {
		turret.rotate(90);
	} else if (shootDirection == Vector2f(-1, 0)) {
		turret.rotate(180);
	} else if (shootDirection == Vector2f(0, -1)) {
		turret.rotate(270);
	}
}

Vector2f Turret::getDirection() {
	return shootDirection;
}

Vector2f Turret::getPos() {
	return position;
}

void Turret::update() {
	if (state == states::alive) {
		if (bulletTimer.done) {
			willShoot = true;
			bulletTimer.reset();
		}
		else {
			willShoot = false;
			bulletTimer.update();
		}
	}
}

Entity* Turret::hit() {
	state = states::dead;
	willShoot = false;
	isSolid = false;
	turret.SetSprite("sprites/turretdead.png", true);
	return nullptr;
}

void Turret::draw(RenderWindow &window)
{
	//hitbox.setPosition(position - Vector2f(size.x/2, size.y/2));
	//window.draw(hitbox);
	turret.draw(window);
	//hud.draw(window);
}

bool Turret::collidesWith(Entity* other) {
	Vector2f delta = other->position - getPos();
	return size.x / 2 > sqrt((int)delta.x * delta.x + delta.y * delta.y);
}