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
	RenderWindow& window;
	//Entity& entity, to call for position without needing to refer to it in draw()

public:
	Graphic(RenderWindow& w, String path);
	void draw(Vector2f pos); /*!< draws sprite at set Vector2f position */
	void rotate(float rotation);
};

#endif