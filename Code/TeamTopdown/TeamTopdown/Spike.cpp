#include "stdafx.h"
#include "Spike.h"


Spike::Spike(Vector2f position, unsigned int startState, Player & p, Vector2f size, bool isSolid):
	Entity(position, size, isSolid, startState),
	player(p)
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
			//isSolid = true;
			break;
		case states::up:
			state = states::down;
			isSolid = false;
			break;
		}
		spikes.SetSprite(spikeStates[state]);
		spikeTimer.reset();
	}

	if (state == rising) {
		spikes.setPosition(position + Vector2f(rand() % 2, 0));
	}

	if (state == states::up && collidesWith(&player) && !player.stats.isDead) {
		player.TriggerDeath();
	}
}

void Spike::draw(RenderWindow & w) {
	spikes.draw(w);
}