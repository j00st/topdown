#ifndef Player_HEADER
#define Player_HEADER

#include "stdafx.h"
#include "controlsInput.h"
#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>

using namespace sf;

/*! \class Player
\brief Handles player movement, interaction, animations and art*/
class Player
{
private:
	Vector2f playerPos; /*!< Stores the players position in a vector */
	Sprite playerSprite; /*!< Sprite used for all properties of the player */
	Texture playerTexture; /*!< Texture storing file location of a png */
	float rotation; /*!< Rotation in degrees to rotate the player sprite */
	ControlsInput& controlsInput; /*!< Reference to cursor location used to rotate sprite */
	Vector2f size; /*!< Size for the player sprite */
public:
	Player( Vector2f size, ControlsInput& controlsInput );
	void update();
	void rotate(); /*!< Rotates the player sprite */
	void draw(RenderWindow & w); /*!< Draws the player on window */
};

#endif