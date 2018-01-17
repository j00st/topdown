#ifndef Player_HEADER
#define Player_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include "controlsInput.h"

using namespace sf;

class PlayerGraphic
{
private:
	Sprite sprite;
	Texture spriteTexture;
public:
	PlayerGraphic();
	void draw(RenderWindow& w, int x, int y);
};

class Player
{
private:
	int playerX, playerY;
	RectangleShape playerShape;
	Vector2f playerPos;
	ControlsInput& ctrlsInpt;

	PlayerGraphic playerGraphic = PlayerGraphic();
	
public:
	Player(ControlsInput& inpt, Vector2f size);
	void update();
	void draw(RenderWindow & w);
};

#endif