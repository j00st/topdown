#ifndef Player_HEADER
#define Player_HEADER

#include "stdafx.h"
#include "controlsInput.h"
#include <iostream>
#include <windows.h>
#include "Graphic.h"
#include "math.h"
#include <SFML/Graphics.hpp>

using namespace sf;

/*! \class Player
\brief Handles player movement, interaction, animations and art*/
class Player
{
private:
	float speed = 3;
	float sprintSpeed = speed*5;
	Vector2f playerPos; /*!< Stores the players position in a vector */
	float rotation; /*!< Rotation in degrees to rotate the player sprite */
	ControlsInput& controlsInput; /*!< Reference to cursor location used to rotate sprite */
	Vector2f size; /*!< Size for the player sprite */
	RenderWindow& window;
	Graphic graphic;
	RectangleShape hitbox;
public:
	Player( Vector2f size, RenderWindow& w, ControlsInput& controlsInput );
	void update();
	void rotate(); /*!< Rotates the player sprite */
	void draw(); /*!< Draws the player on window */
	float calcSpeed();
	Vector2f getPos(); /*!< Returns position of the player */
};

#endif