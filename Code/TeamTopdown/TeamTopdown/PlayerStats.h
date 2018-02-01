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
	/*
	 * Functional stats
	 */
	Vector2f position = Vector2f(0, 0);
	bool dodging = false; /*!< "is player dodging?" boolean */
	int pauseMenuOpen = 0; // used to prevent the player from doing stuff in entitycontroller while pausemenu is open
	float meleeRange = 40;
	float meleeSpeed = 15;

	/*
	 * ability cooldowns
	 */
	Timer energy, sprint, dodge, shoot, reload, seconds; /*!< timer for player based on fps */

	/*
	 * in-game stats
	 */
	int stamina = 100; /*!< player max stamina */
	float speed = 3; /*!< player max speed */
	int ammo = 5; /*!< current gun ammunition */
	int maxAmmo = 5;
	int isDead = 0; /*!< player dead state */
	int remainingTime = 120;
	int startTime = 120;
	
	/*
	 * Methods
	 */
	PlayerStats(); // initializer/constructor
	void Reset(); // resets all stats to default
};

#endif