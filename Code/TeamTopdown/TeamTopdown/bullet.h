#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet
{
private:
	Vector2f distance = Vector2f(0,0);
	Vector2f speed = Vector2f(5, 0);
	Clock clock;
	Time time;
public:
	Bullet(float speedTotal, Vector2f relativePosBul);
	void draw();
};

