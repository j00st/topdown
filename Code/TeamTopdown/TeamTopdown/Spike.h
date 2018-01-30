#ifndef SPIKE_HEADER
#define SPIKE_HEADER

#include "stdafx.h"
#include "Entity.h"
#include "Graphic.h"
#include "Timer.h"
#include "Player.h"

class Spike :
	public Entity
{
private:
	Player & ourPlayer;
	enum states { down, rising, up };
	String spikeStates[3] = { "sprites/spikes0.png", "sprites/spikes1.png", "sprites/spikes2.png" };
	Graphic spikes = Graphic(spikeStates[0]);
	unsigned int currentState;
	Timer spikeTimer = Timer(60.0f);
public:
	Spike(Vector2f position, unsigned int startState, Player & p, Vector2f size = Vector2f(32.0f, 32.0f), bool isSolid = false);
	void update() override;
	void draw(RenderWindow & w);
};

#endif