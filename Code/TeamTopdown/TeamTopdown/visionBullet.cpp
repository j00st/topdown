#include "stdafx.h"
#include "visionBullet.h"


visionBullet::visionBullet(float speed, Vector2f relativePosBul, Vector2f position, Vector2f size, bool isSolid, int state)
	:
	Entity(position, size, isSolid, state)
{
	float totalLength = sqrt(relativePosBul.x * relativePosBul.x + relativePosBul.y * relativePosBul.y);
	speedVect = (speed / totalLength) * relativePosBul;
	this->position += speedVect * 2.0f;
}
visionBullet::~visionBullet() {
}

void visionBullet::update() {
	if (isAlive) {
		position.x += speedVect.x;
		position.y += speedVect.y;
		if (timeAlive >= 900) {
			isAlive = false;
		}
		timeAlive++;
	}
}

void visionBullet::setIsAlive(bool b) {
	isAlive = b;
}

bool visionBullet::getIsAlive() {
	return isAlive;
}

Vector2f visionBullet::getDirection() {
	return speedVect;
}

int visionBullet::getTimeAlive() {
	return timeAlive;
}

void visionBullet::draw(RenderWindow &window) {
}

