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

	// ability cooldowns
	Timer energy = Timer(20);
	Timer sprint = Timer(13); //wow
	Timer dodge = Timer(20);


	PlayerStats();
};

#endif