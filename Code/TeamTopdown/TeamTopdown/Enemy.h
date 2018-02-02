#ifndef Enemy_HEADER
#define Enemy_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Graphic.h"
#include "Entity.h"
#include "bullet.h"
#include "Item.h"
#include <SFML/Graphics.hpp>
#include <queue>
#include "SFML/Audio.hpp"

using namespace sf;

/*! \class Enemy
\brief Handles enemy movement, interaction and art.
The enemy class creates an instance of an enemy and adds the position given as waypoint.
If other waypoints are added, which are first in line, we set entity position to that waypoint.
Once all waypoints are added (map is looped through entirely) we create a queue from this map of waypoints.
If we only have 1 waypoint we empty our queue and stand still. If we have an even amount, we loop through those points.
If the amount of waypoints is uneven, we create a line instead.*/

class Enemy : public Entity
{
private:
	enum states { patrolling, alarmed, dead }; /*!< Enemies can either be patrolling (stationary on single waypoint or walking between waypoints), alarmed (tracking the player's position and shooting when the player is visible for the enemy) or dead. */
	String spriteStates[2] = { "sprites/guard1.png", "sprites/guard1_dead.png" };
	Vector2f lookAtObject = Vector2f(0, 0); /*!< Used to determine the enemy's rotation. Can either be the next waypoint when patrolling or the player when alarmed. */
	Vector2f & playerPos; /*!< Reference to players location for enemy rotation. */
	float movementSpeed = 1.0f;
	Graphic enemySprite = Graphic(spriteStates[0], true);
	std::map<unsigned int, Vector2f> waypointMap;
	Vector2f initLookAtObj = Vector2f(0,0); /*!< Location for stationary enemies to look at */
	sf::SoundBuffer SBenemyDeath; /*!< SFX to be played when enemy dies */
	sf::Sound SEenemyDeath;
public:
	Enemy(Vector2f position, unsigned int waypointNr, Vector2f size = Vector2f(24.0f, 24.0f), bool isSolid = true, int state = states::patrolling, bool hostile = false, Vector2f & playerPos = Vector2f(0,0), Vector2f initLookAtObj = Vector2f(0,0));
	std::queue<Vector2f> waypoints;
	void addWaypoint(Vector2f position, unsigned int number);
	/*! /void createWaypointQueue()
	/brief creates a que of waypoints for the enemy to follow
	*/
	void createWaypointQueue();
	void rotate();
	void moveTowards(Vector2f direction);
	/*! /void Entity* hit() override
	/brief overrides the hit function from Entity
	/description
	This funciton will be called when the enemy should die. When called, the enemy switches to it's dead state and the texture will be updated to visualise a dead enemy. Enemy interactions will also be disabled. A random amount of bullets will be dropped for the player to pick up at the enemy's locatoin.
	*/
	Entity* hit() override;
	/*! /void update() override;
	/brief overrides the update function from Entity
	/description
	This function controls the patrolling and alarmed state. When patrolling, the enemy will move to it's next waypoint if not stationary. When alarmed, the enemy will track the players location. The position will be set at the end of the function.
	*/
	void update() override;
	void draw(RenderWindow &window) override;
	Vector2f getPos();
	Vector2f getLookAtObj();
	float rotation;
	/*! /bool collidesWith(Entity* other)
	/brief returns boolean if enemy is colliding with another entity
	*/
	bool collidesWith(Entity* other);
};

#endif