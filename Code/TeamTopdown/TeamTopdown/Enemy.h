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
	std::map<unsigned int, Vector2f> waypoints;
public:
	Enemy(Vector2f position, unsigned int waypointNr, Vector2f size = Vector2f(24.0f, 24.0f), bool isSolid = false);
	void addWaypoint(Vector2f position, unsigned int number);
	void update() override;
	void rotate(); /*!< Rotates the enemy sprite */
	void draw(RenderWindow &window) override; /*!< Draws the enemy on window */
	Vector2f getPos(); /*!< Returns position of the enemy */
};

#endif