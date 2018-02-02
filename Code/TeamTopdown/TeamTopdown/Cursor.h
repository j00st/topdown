#ifndef Cursor_HEADER
#define Cursor_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include "ControlsInput.h"
#include "Entity.h"

using namespace sf;

/*! \class Cursor
\brief Class for the Cursor entity. Overrides the needed functions from Entity. Places a sprite on the cursor location. */
class Cursor : public Entity
{
private:
	sf::RenderWindow & window;
	Sprite cursorSprite; /*!< Sprite used for all properties of the cursor */
	Texture cursorTexture; /*!< Texture storing file location of a png */
	ControlsInput& controlsInput; /*!< reference to cursor location from mouse input */
public:
	Cursor(sf::RenderWindow & window, Vector2f position, Vector2f size, ControlsInput& controlsInput, bool isSolid);
	/*! /void update()
	/brief updates the data within this class 
	- updates the cursor sprite location */
	void update() override;

	/*! /void draw()
	/brief draws certain graphics within this class
	- draws the cursor sprite */
	void draw(RenderWindow& w) override;

	/*! /Vector2f getPos()
	/brief returns the position of the cursor */
	Vector2f getPos();
};

#endif