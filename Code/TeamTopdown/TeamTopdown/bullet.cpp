#include "stdafx.h"
#include "bullet.h"


Bullet::Bullet(float speed, Vector2f relativePosBul, Vector2f position, Vector2f size, bool isSolid, int state)
	:
	Entity(position, size, isSolid, state)
{
	float totalLength = sqrt(relativePosBul.x * relativePosBul.x + relativePosBul.y * relativePosBul.y);
	speedVect = (speed / totalLength) * relativePosBul;
	rotate(relativePosBul.x, relativePosBul.y);
	this->position += speedVect * 1.5f;
}
Bullet::~Bullet(){
}

void Bullet::rotate(float x, float y)
{
	rotation = atan2(y, x);
	rotation = rotation * (float(180.0) / float(3.141592653589793238463)); // transform radian to degree
	bulletSprite.rotate(rotation);
}



void Bullet::update() {
	if (isAlive) {
		position.x += speedVect.x;
		position.y += speedVect.y;
		bulletSprite.setPosition(position);
		if (timeAlive >= 900) {
			isAlive = false;
		}
		timeAlive++;
	}
}

void Bullet::setIsAlive(bool b) {
	isAlive = b;
}

bool Bullet::getIsAlive() {
	return isAlive;
}

Vector2f Bullet::getDirection() { 
	return speedVect;
}

int Bullet::getTimeAlive() {
	return timeAlive;
}

void Bullet::draw(RenderWindow &window) {
	if(isAlive) bulletSprite.draw(window);
}

