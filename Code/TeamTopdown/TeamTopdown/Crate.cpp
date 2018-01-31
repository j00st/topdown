#include "stdafx.h"
#include "Crate.h"

SoundBuffer Crate::audioClip;
Crate::Crate(Vector2f position, Vector2f size, bool isSolid, int state):
	Entity(position, size, isSolid, state)
{
	audioClip.loadFromFile("audio/crateDestroyed.wav");
	crateDestroyed.setBuffer(audioClip);
	crate.setPosition(position);
}

Entity* Crate::hit() {
	state = states::destroyed;
	isSolid = false;
	crate.SetSprite(spriteStates[state]);
	crateDestroyed.play();
	return new Item(position, size, 5, 0);
}

void Crate::draw(RenderWindow & w) {
	crate.draw(w);
}