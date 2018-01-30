#ifndef SPIKE_HEADER
#define SPIKE_HEADER

#include "stdafx.h"
#include "Entity.h"
#include "Graphic.h"
#include "Timer.h"
#include "Player.h"

/*! \class Spike
\brief Set of spikes which protrude and retract based on a timer.
A set of spikes which change states every 1/6th second. 
The initial state is given with our constructor, and pulled from the map by green value.
The player is also given as a reference to be able to call the TriggerDeath() function.*/
class Spike :
	public Entity
{
private:
	Player & ourPlayer;
	enum states { down, rising, up };
	String spikeStates[3] = { "sprites/spikes0.png", "sprites/spikes1.png", "sprites/spikes2.png" };
	Graphic spikes = Graphic(spikeStates[0]);
	Timer spikeTimer = Timer(10);
public:
	Spike(Vector2f position, unsigned int startState, Player & p, Vector2f size = Vector2f(32.0f, 32.0f), bool isSolid = false);
	void update() override;
	void draw(RenderWindow & w);
};

#endif