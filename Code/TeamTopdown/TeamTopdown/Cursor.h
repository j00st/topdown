#ifndef Cursor_HEADER
#define Cursor_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include "ControlsInput.h"

using namespace sf;

/*! \class Cursor
\brief places a sprite on the cursor location*/
class Cursor
{
private:
	Sprite cursorSprite; /*!< Sprite used for all properties of the cursor */
	Texture cursorTexture; /*!< Texture storing file location of a png */
	ControlsInput& controlsInput; /*!< reference to cursor location from mouse input */
public:
	Cursor(ControlsInput& controlsInput);
	void update(Vector2f delta); /*!< updates location of cursor */
	void draw(RenderWindow& w); /*!< draws cursor on window */
};

#endif