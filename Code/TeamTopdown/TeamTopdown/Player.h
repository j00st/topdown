#ifndef Player_HEADER
#define Player_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
private:
	int playerX, playerY;
	RectangleShape playerShape;
	Vector2f playerPos;
public:
	Player( Vector2f size );
	void update();
	void draw(RenderWindow & w);
};

#endif