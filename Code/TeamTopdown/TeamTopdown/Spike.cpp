#include "stdafx.h"
#include "Spike.h"


Spike::Spike(Vector2f position, unsigned int startState, Player & p, Vector2f size, bool isSolid):
	Entity(position, size, isSolid, startState),
	ourPlayer(p)
{
	spikes.setPosition(position);
}

void Spike::update() {
	spikeTimer.update();
	if (spikeTimer.done) {
		switch (state) {
		case states::down:
			state = states::rising;
			break;
		case states::rising:
			state = states::up;
			isSolid = true;
			break;
		case states::up:
			state = states::down;
			isSolid = false;
			break;
		}
		spikes.SetSprite(spikeStates[state]);
		spikeTimer.reset();
	}
	if (isSolid && ourPlayer.collidesWith(this, Vector2f(0, 0))) {
		ourPlayer.TriggerDeath();
	}
}

void Spike::draw(RenderWindow & w) {
	spikes.draw(w);
}