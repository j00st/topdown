#ifndef Timer_HEADER
#define Timer_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <ctime>

struct Timer {
	float start = 0; /*!< timer duration */
	float timer = 0; /*!< current time of timer */
	bool done = false; /*!< if the timer is done */

	Timer(float t = 0); /*!< Sets a fps based timer with duration(frames) t. 60fps = 1 sec */
	~Timer() {};
	void update();
	void reset();
};

#endif