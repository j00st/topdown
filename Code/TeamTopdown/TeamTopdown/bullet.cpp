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
	rect = RectangleShape(position);
	
	std::cout << speedVect.x << "\n";
	std::cout << speedVect.y << "\n";
	
}


void Bullet::update() {
	position.x += speedVect.x;
	position.y += speedVect.y;
	rect.setPosition(position);

}

void Bullet::draw(RenderWindow &window) {
	window.draw(rect);
}

