#ifndef Enemy_HEADER
#define Enemy_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Graphic.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

using namespace sf;

/*! \class Player
\brief Handles enemy movement, interaction, animations and art*/
class Enemy : public Entity
{
private:
	float rotation; /*!< Rotation in degrees to rotate the player sprite */
	Graphic enemySprite = Graphic("sprites/character.png", true);
	RectangleShape hitbox;
public:
	Enemy(Vector2f position, Vector2f size, bool isSolid = false);
	void update() override;
	void rotate(); /*!< Rotates the enemy sprite */
	void draw(RenderWindow &window) override; /*!< Draws the enemy on window */
	Vector2f getPos(); /*!< Returns position of the enemy */
};

#endif