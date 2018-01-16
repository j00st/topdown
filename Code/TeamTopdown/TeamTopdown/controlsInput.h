#ifndef controlsInput_HEADER
#define controlsInput_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>

using namespace sf;

struct controlsInput
{
	controlsInput();
	Vector2i mousePos;
	bool wKeyPressed = false;
	bool aKeyPressed = false;
	bool sKeyPressed = false;
	bool dKeyPressed = false;
};

#endif