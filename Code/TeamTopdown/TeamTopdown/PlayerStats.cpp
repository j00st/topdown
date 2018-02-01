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
	stamina = 100; /*!< player max stamina */
	speed = 3; /*!< player max speed */
	dodging = false; /*!< "is player dodging?" boolean */
	ammo = 5; /*!< current gun ammunition */
	maxAmmo = 5;
	isDead = 0; /*!< player dead state */
	pauseMenuOpen = 0;
	remainingTime = 120;
	startTime = 120;
}