#include "stdafx.h"
#include "Turret.h"


Turret::Turret(Vector2f position, Vector2f size, Vector2f lookAtObject, int framesBetweenShots, bool isSolid):
	Entity(position, size, isSolid, states::alive),
	shootDirection (lookAtObject),
	bulletTimer (framesBetweenShots)
{
	turret.setPosition(position);
	Vector2f defaultDirection(1, 0);
	float angle = acos((shootDirection.x * defaultDirection.x + shootDirection.y * defaultDirection.y) / (sqrt((int)shootDirection.x * shootDirection.x + shootDirection.y * shootDirection.y) * sqrt((int)defaultDirection.x * defaultDirection.x + defaultDirection.y * defaultDirection.y)));
	turret.rotate(angle);
}

Vector2f Turret::getDirection() {
	return shootDirection;
}

Vector2f Turret::getPos() {
	return position + size / 2.0f;
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
	//setsprite to dead turret
	return nullptr;
}

void Turret::draw(RenderWindow &window)
{
	//hitbox.setPosition(position - Vector2f(size.x/2, size.y/2));
	//window.draw(hitbox);
	turret.draw(window);
	//hud.draw(window);
}

