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
	bool pKeyPressed = false; /*!< state of the P key */
	bool num1KeyPressed = false; /*!< state of the 1 key */
	bool num2KeyPressed = false; /*!< state of the 2 key */
	bool num3KeyPressed = false; /*!< state of the 3 key */
	bool num4KeyPressed = false; /*!< state of the 4 key */
	bool num5KeyPressed = false; /*!< state of the 5 key */
	bool num6KeyPressed = false; /*!< state of the 6 key */
	bool num7KeyPressed = false; /*!< state of the 7 key */
	bool num8KeyPressed = false; /*!< state of the 8 key */
	bool num9KeyPressed = false; /*!< state of the 9 key */
	bool num0KeyPressed = false; /*!< state of the 9 key */
	bool minusKeyPressed = false; /*!< state of the - key */
	bool plusKeyPressed = false; /*!< state of the + key */
	bool shiftKeyPressed = false; /*!< state of he SHIFT key */
	bool spaceKeyPressed = false; /*!< state of the SPACE key */
	bool enterKeyPressed = false; /*!< state of the ENTER key */
	bool backspaceKeyPressed = false; /*!< state of the BACKSPACE key */
	bool lmbKeyPressed = false; /*!< state of the LEFT MOUSE BUTTON key */
	bool rKeyPressed = false; /*!< state of the R key */
};

#endif