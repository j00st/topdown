#ifndef PlayerStats_HEADER
#define PlayerStats_HEADER

#include "stdafx.h"
#include <iostream>
#include "Timer.h"
#include <windows.h>
#include <SFML/Graphics.hpp>

using namespace sf;
/*! \class PlayerStats
\brief Struct that contains player statistics*/
struct PlayerStats
{
	Vector2f position;
	int stamina = 100; /*!< player max stamina */
	float speed = 3; /*!< player max speed */
	bool dodging = false; /*!< "is player dodging?" boolean */
	int ammo = 5; /*!< current gun ammunition */
	int isDead = 0; /*!< player dead state */

	// ability cooldowns
	Timer energy, sprint, dodge, shoot, reload; /*!< timer for player based on fps */

	PlayerStats();
};

#endif