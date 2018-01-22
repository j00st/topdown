#ifndef Timer_HEADER
#define Timer_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <ctime>

struct Timer {
	float start = 0;
	float timer = 0;
	bool done = false;

	Timer(float t = 0);
	~Timer() {};
	void update();
	void reset();
};

#endif