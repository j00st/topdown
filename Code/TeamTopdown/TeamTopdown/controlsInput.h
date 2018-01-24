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
	bool num1KeyPressed = false; // state of 1 key
	bool num2KeyPressed = false; // state of 2 key
	bool shiftKeyPressed = false;
	bool spaceKeyPressed = false;
	bool lmbKeyPressed = false;
};

#endif