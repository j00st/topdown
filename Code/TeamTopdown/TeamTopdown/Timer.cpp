#include "stdafx.h"
#include "Timer.h"


Timer::Timer(float time)
{
	start = time;
	timer = time;
}

void Timer::update() {
	if (timer < start) {
		timer++;
	}
	if (timer >= start) {
		done = true;
		//reset();
	}
}

void Timer::reset() {
	done = false;
	timer = 0;
}
