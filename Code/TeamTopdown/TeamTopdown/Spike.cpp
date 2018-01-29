#include "stdafx.h"
#include "Spike.h"


Spike::Spike(Vector2f position, unsigned int startState, Player & p, Vector2f size, bool isSolid):
	Entity(position, size, isSolid),
	ourPlayer(p),
	currentState(startState)
{
	spikes.setPosition(position);
}

void Spike::update() {
	spikeTimer.update();
	if (spikeTimer.done) {
		if (currentState == states::up) {
			currentState = states::down;
			isSolid = false;
		} else {
			currentState++;
			if (currentState == states::up) {
				isSolid = true;
			}
		}
		spikes.SetSprite(spikeStates[currentState]);
		spikeTimer.reset();
	}
	if (isSolid && ourPlayer.collidesWith(this, Vector2f(0, 0))) {
		ourPlayer.TriggerDeath();
	}
}

void Spike::draw(RenderWindow & w) {
	spikes.draw(w);
}