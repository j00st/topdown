
#include "stdafx.h"
#include "Spike.h"


Spike::Spike(Vector2f position, unsigned int startState, Vector2f size, bool isSolid):
 Entity(position, size, isSolid),
 currentState(startState)
{
	spikes.setPosition(position);
}

void Spike::update() {
	spikeTimer.update();
	if (spikeTimer.done) {
		if (currentState == states::up) {
			currentState = states::down;
		} else {
			currentState++;
		}
		spikes.SetSprite(spikeStates[currentState]);
		spikeTimer.reset();
	}
	switch (currentState) {
		case states::down:
			isSolid = false;
			break;
		case states::up:
			isSolid = true;
			break;
	}
}

void Spike::draw(RenderWindow & w) {
	spikes.draw(w);
}