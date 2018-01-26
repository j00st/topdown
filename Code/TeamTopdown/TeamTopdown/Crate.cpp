#include "stdafx.h"
#include "Crate.h"


Crate::Crate(Vector2f position, Vector2f size, bool isSolid, int state):
	Entity(position, size, isSolid, state)
{
	crate.setPosition(position);
}

void Crate::update(std::map<int, Bullet*> & bullets) {
	for (auto bulletPair : bullets) {
		if (collidesWith(bulletPair.second, Vector2f(0, 0))) {
			state = states::destroyed;
			crate.SetSprite(spriteStates[state]);
			//drop item
		}
	}
}

void Crate::draw(RenderWindow & w) {
	crate.draw(w);
}