#ifndef Cursor_HEADER
#define Cursor_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ControlsInput.h"
#include "Entity.h"

/*! \class Cursor
\brief places a sprite on the cursor location*/
class Cursor : public Entity
{
private:
	Sprite cursorSprite; /*!< Sprite used for all properties of the cursor */
	Texture cursorTexture; /*!< Texture storing file location of a png */
	ControlsInput& controlsInput; /*!< reference to cursor location from mouse input */
public:
	Cursor(sf::Vector2f position, sf::Vector2f size, ControlsInput & controlsInput, bool isSolid);
	void update() override; /*!< updates location of cursor */
	void draw(RenderWindow & w) override; /*!< draws cursor on window */
	sf::Vector2f getPos(); /*!< Returns position of the cursor */
};

#endif