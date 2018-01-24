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

	void rotate(float rotation); /*!< rotates sprite based on rotation */
	void setPosition(Vector2f pos); /*!< sets sprite potion based on pos */
	void setScale(Vector2f scale); /*!< sets scale based on scale */
	void draw(RenderWindow & w); /*!< draws sprite on screen */
	void SetSprite(std::string path, bool centerSprite = false); /*!< sets sprite based on path */
};

#endif