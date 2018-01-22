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
		//std::cout << timer << "/" << start << "\n";
	}
	if (timer >= start) {
		//std::cout << "cooldown done!\n";
		done = true;
		//reset();
	}
}

void Timer::reset() {
	//std::cout << "cooldown reset:" << start << "\n";
	done = false;
	timer = 0;
}
