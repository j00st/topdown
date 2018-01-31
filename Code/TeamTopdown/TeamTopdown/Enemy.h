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

/*! \class Enemy
\brief Handles enemy movement, interaction, animations and art.
The enemy class creates an instance of an enemy and adds the position given as waypoint.
If other waypoints are added, which are first in line, we set entity position to that waypoint.
Once all waypoints are added (map is looped through entirely) we create a queue from this map of waypoints.
If we only have 1 waypoint we empty our queue and stand still. If we have an even amount, we loop through those points.
If the amount of waypoints is uneven, we create a line instead.*/

class Enemy : public Entity
{
private:
	enum states { patrolling, alarmed, dead };
	String spriteStates[2] = { "sprites/guard1.png", "sprites/guard1_dead.png" };
	Vector2f lookAtObject = Vector2f(0, 0);
	Vector2f & playerPos;
	float movementSpeed = 1.0f;
	float aggroRange = 128.0f;
	Graphic enemySprite = Graphic(spriteStates[0], true);
	RectangleShape hitbox;
	std::map<unsigned int, Vector2f> waypointMap;
	Vector2f initLookAtObj = Vector2f(0,0);
public:
	Enemy(Vector2f position, unsigned int waypointNr, Vector2f size = Vector2f(24.0f, 24.0f), bool isSolid = true, int state = states::patrolling, bool hostile = false, Vector2f & playerPos = Vector2f(0,0), Vector2f initLookAtObj = Vector2f(0,0));
	std::queue<Vector2f> waypoints;
	void addWaypoint(Vector2f position, unsigned int number);
	void createWaypointQueue();
	void rotate(); /*!< Rotates the enemy sprite */
	void moveTowards(Vector2f direction);  /*!< Moves the enemy towards a certain position */
	Entity* hit() override;
	void update() override;
	void draw(RenderWindow &window) override; /*!< Draws the enemy on window */
	Vector2f getPos(); /*!< Returns position of the enemy */
	Vector2f getLookAtObj();
	float rotation; /*!< Rotation in degrees to rotate the player sprite */
	bool collidesWith(Entity* other);
};

#endif