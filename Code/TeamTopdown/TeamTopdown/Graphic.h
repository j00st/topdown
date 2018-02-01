#ifndef Graphic_HEADER
#define Graphic_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "controlsInput.h"
#include <SFML/Graphics.hpp>

using namespace sf;

/*! \class Graphic
\brief Creates a graphic object*/
class Graphic
{
private:
	Sprite sprite; /*!< the virtual sprite */
	Texture spriteTexture; /*!< the texture path & load */

public:
	Graphic(String path, bool centerSprite = false);

	/*! /void rotate(float rotation)
	/brief rotates sprite based on float rotation */
	void rotate(float rotation);

	/*! /void setPosition
	/brief sets sprite position based on Vector2f pos */
	void setPosition(Vector2f pos);

	/*! /void setScale(Vector2f scale)
	/brief sets sprite scale based on Vector2f scale */
	void setScale(Vector2f scale);

	/*! /void draw(RenderWindow & w)
	/brief draws sprite */
	void draw(RenderWindow & w); 

	/*! /void SetSprite
	/brief sets sprite png to string path and checks a bool if sprite initial position should be centered */
	void SetSprite(std::string path, bool centerSprite = false); 
};

#endif