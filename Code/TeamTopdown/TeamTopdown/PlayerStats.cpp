#include "stdafx.h"
#include "PlayerStats.h"


PlayerStats::PlayerStats()
{
	energy = Timer(20.0);
	sprint = Timer(10.0);
	dodge = Timer(20.0);
	shoot = Timer(15.0);
	reload = Timer(50.0);
	seconds = Timer(60.0);
}

void PlayerStats::Reset()
{
	//Vector2f position = Vector2f(0, 0);
	int stamina = 100; /*!< player max stamina */
	float speed = 3; /*!< player max speed */
	bool dodging = false; /*!< "is player dodging?" boolean */
	int ammo = 5; /*!< current gun ammunition */
	int maxAmmo = 5;
	int isDead = 0; /*!< player dead state */
	int remainingTime = 120;
	int startTime = 120;
}