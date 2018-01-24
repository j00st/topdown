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

	void rotate(float rotation);
	void setPosition(Vector2f pos);
	void setScale(Vector2f scale);
	void draw(RenderWindow & w);
	void SetSprite(std::string p, bool center = false);
};

#endif