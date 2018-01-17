#ifndef Graphic_HEADER
#define Graphic_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>

using namespace sf;

class Graphic
{
private:
	Sprite sprite;
	Texture spriteTexture;
	RenderWindow& w;

public:
	Graphic(RenderWindow& w);
	void draw(int x, int y)
};

#endif