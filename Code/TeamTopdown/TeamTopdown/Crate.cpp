#include "stdafx.h"
#include "Crate.h"

Crate::Crate(Vector2f position, Vector2f size, bool isSolid, int state):
	Entity(position, size, isSolid, state)
{
	audioClip.loadFromFile("audio/crateDestroyed.wav");
	crateDestroyed.setBuffer(audioClip);
	crate.setPosition(position);
}

void Crate::hit() {
	state = states::destroyed;
	isSolid = false;
	crate.SetSprite(spriteStates[state]);
	crateDestroyed.play();
	//drop item
}

void Crate::draw(RenderWindow & w) {
	crate.draw(w);
}