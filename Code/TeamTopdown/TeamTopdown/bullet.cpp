#include "stdafx.h"
#include "bullet.h"


Bullet::Bullet(float speed, Vector2f relativePosBul, Vector2f position, Vector2f size, bool isSolid)
	:
	Entity(position, size, isSolid)
{
	if (relativePosBul.y == 0) {
		speedVect.y = 0;
		speedVect.x = speed;
	} else if(relativePosBul.x == 0){
		speedVect.x = 0;
		speedVect.y = speed;
	} else {

		float climb = (relativePosBul.y / relativePosBul.x);
		float climbsquared = climb * climb;
		speed *= speed;
		climbsquared++;
		speed /= climbsquared;
		speedVect.x = sqrt(speed);
		if (relativePosBul.x < 0) {
			speedVect.x *= -1;
		}
		speedVect.y = speedVect.x * climb;
	}
	rotate(relativePosBul.y, relativePosBul.x);
	
}
Bullet::~Bullet(){
}

void Bullet::rotate(float y, float x)
{
	rotation = atan2(y, x);
	rotation = rotation * (float(180.0) / float(3.141592653589793238463)); // transform radian to degree
	bulletSprite.rotate(rotation);
}



void Bullet::update() {
	position.x += speedVect.x;
	position.y += speedVect.y;
	bulletSprite.setPosition(position);
	timeAlive++;
}

int Bullet::getTimeAlive() {
	return timeAlive;
}

void Bullet::draw(RenderWindow &window) {
	bulletSprite.draw(window);
}

