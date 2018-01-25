#ifndef Enemy_HEADER
#define Enemy_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Graphic.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <queue>

using namespace sf;

/*! \class Player
\brief Handles enemy movement, interaction, animations and art*/
class Enemy : public Entity
{
private:
	Vector2f & lookAtObject;
	float movementSpeed = 1.0f;
	float rotation; /*!< Rotation in degrees to rotate the player sprite */
	Graphic enemySprite = Graphic("sprites/character.png", true);
	RectangleShape hitbox;
	std::map<unsigned int, Vector2f> waypointMap;
public:
	Enemy(Vector2f position, unsigned int waypointNr, Vector2f size = Vector2f(24.0f, 24.0f), bool isSolid = false, Vector2f & lookatobject = Vector2f(0,0));
	std::queue<Vector2f> waypoints;
	bool hasAggro = false;
	void addWaypoint(Vector2f position, unsigned int number);
	void createWaypointQueue();
	void update() override;
	void rotate(); /*!< Rotates the enemy sprite */
	void moveTowards(Vector2f direction);  /*!< Moves the enemy towards a certain position */
	void draw(RenderWindow &window) override; /*!< Draws the enemy on window */
	Vector2f getPos(); /*!< Returns position of the enemy */
};

#endif