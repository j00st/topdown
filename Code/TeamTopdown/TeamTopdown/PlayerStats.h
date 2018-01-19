#ifndef PlayerStats_HEADER
#define PlayerStats_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>

/*! \class PlayerStats
	\brief Struct that contains player statistics*/
struct PlayerStats
{
	PlayerStats(float s = 0);
	float speed;
};

#endif