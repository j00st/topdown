#ifndef Enemy_HEADER
#define Enemy_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Graphic.h"
#include "Entity.h"
#include "bullet.h"
#include <SFML/Graphics.hpp>
#include <queue>

using namespace sf;

/*! \class Player
\brief Handles enemy movement, interaction, animations and art*/
class Enemy : public Entity
{
private:
	enum states { patrolling, alarmed, dead };
	String spriteStates[2] = { "sprites/guard1.png", "sprites/guard1_dead.png" };
	Vector2f lookAtObject = Vector2f(0, 0);
	Vector2f & playerPos;
	float movementSpeed = 1.0f;
	float aggroRange = 160.0f;
	float rotation; /*!< Rotation in degrees to rotate the player sprite */
	Graphic enemySprite = Graphic(spriteStates[0], true);
	RectangleShape hitbox;
	Clock clock;
	std::map<unsigned int, Vector2f> waypointMap;
public:
	Enemy(Vector2f position, unsigned int waypointNr, Vector2f size = Vector2f(24.0f, 24.0f), bool isSolid = false, int state = states::patrolling, bool hostile = false, Vector2f & playerPos = Vector2f(0,0));
	std::queue<Vector2f> waypoints;
	void addWaypoint(Vector2f position, unsigned int number);
	void createWaypointQueue();
	void update(std::map<int, Bullet*> & bullets);
	void rotate(); /*!< Rotates the enemy sprite */
	void moveTowards(Vector2f direction);  /*!< Moves the enemy towards a certain position */
	void draw(RenderWindow &window) override; /*!< Draws the enemy on window */
	Vector2f getPos(); /*!< Returns position of the enemy */
};

#endif