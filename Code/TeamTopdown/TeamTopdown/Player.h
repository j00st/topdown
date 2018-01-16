#ifndef Player_HEADER
#define Player_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include "controlsInput.h"

using namespace sf;

class Player
{
private:
	int playerX, playerY;
	bool state = false;
	RectangleShape playerShape;
	Vector2f playerPos;
	ControlsInput& ctrlsInpt;
public:
	Player(ControlsInput& inpt, Vector2f size);
	void update();
	void draw(RenderWindow & w);
};

#endif