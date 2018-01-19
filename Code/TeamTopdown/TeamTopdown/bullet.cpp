#include "stdafx.h"
#include "bullet.h"


Bullet::Bullet(float speedTotal, Vector2f relativePosBul)
{
	float climb =  (relativePosBul.y / relativePosBul.x );
	float climbsquared = climb * climb;
	speedTotal *= speedTotal;
	climbsquared++;
	speedTotal /= climbsquared;
	float x = sqrt(speedTotal);
	float y = x * climb;
	//speed.x = (relativePosBul.x / relativePosBul.y);
	//std::cout << sqrt((speed.x * speed.x) ) <<" \n";
	std::cout << x  << "\n";
	std::cout << y  << "\n";
	clock.restart();
}



void Bullet::draw() {
	time = clock.getElapsedTime();
	distance.x = time.asSeconds() * speed.x; distance.y	 = time.asSeconds() * speed.y;
	//std::cout << time.asSeconds() << "\n";
}

