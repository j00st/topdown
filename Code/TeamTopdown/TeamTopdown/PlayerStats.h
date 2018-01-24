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
	int stamina = 100;
	float speed = 3;
	bool dodging = false;
	int ammo = 5;
	int isDead = 0;

	// ability cooldowns
	Timer energy, sprint, dodge, shoot, reload;

	PlayerStats();
};

#endif