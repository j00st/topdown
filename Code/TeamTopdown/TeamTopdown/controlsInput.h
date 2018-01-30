#ifndef ControlsInput_HEADER
#define ControlsInput_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>

using namespace sf;

/*! \class controlsInput
\brief struct with saves states of hardware inputs*/
struct ControlsInput
{
	ControlsInput();
	Vector2f mousePos; /*!< Current mouse position in pixels */
	bool wKeyPressed = false; /*!< state of the UP key */
	bool aKeyPressed = false; /*!< state of the LEFT key */
	bool sKeyPressed = false; /*!< state of the DOWN key */
	bool dKeyPressed = false; /*!< state of the RIGHT key */
	bool pKeyPressed = false; // state of p key
	bool num1KeyPressed = false; // state of 1 key
	bool num2KeyPressed = false; // state of 2 key
	bool num3KeyPressed = false; // state of 3 key
	bool num4KeyPressed = false; // state of 4 key
	bool num5KeyPressed = false; // state of 5 key
	bool num6KeyPressed = false; // state of 6 key
	bool num7KeyPressed = false; // state of 7 key
	bool num8KeyPressed = false; // state of 8 key
	bool num9KeyPressed = false; // state of 9 key
	bool num0KeyPressed = false; // state of 0 key
	bool minusKeyPressed = false; // state of - _ key
	bool plusKeyPressed = false; // state of + = key
	bool shiftKeyPressed = false;
	bool spaceKeyPressed = false;
	bool enterKeyPressed = false; //state of Enter key
	bool lmbKeyPressed = false;
	bool rKeyPressed = false;
};

#endif