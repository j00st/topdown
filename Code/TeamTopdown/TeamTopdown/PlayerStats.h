#ifndef PlayerStats_HEADER
#define PlayerStats_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <ctime>

/*! \class PlayerStats
\brief Struct that contains player statistics*/
struct PlayerStats
{
	int stamina = 100;
	time_t sprintTimer = time(0);
	float speed = 3;
	PlayerStats();
};

#endif