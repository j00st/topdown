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