#ifndef MAP_HEADER
#define MAP_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Crate.h"
#include "Spike.h"
#include "Wall.h"
#include "Exit.h"
#include "Enemy.h"
#include "Turret.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

using namespace sf;

/*! \class Map
\brief Creates an entity list based on a collision map
This class creates a list of entities based on the red value of a .png-file.
We loop through the pixels to determine a position. The tile size is constant and set.
Once we find a pixel with a red-value of 0, we make it our spawnpoint.
If it's a 1, we spawn a wall at that position with the standard tilesize and add it to the entity list.
A red-value of 2 indicates an enemy waypoint. This will either create a new enemy from that waypoint, or add the waypoint to an already existing enemy.
In creating such a waypoint, the green-value of the pixel determines the enemy by ID and the blue-value determines the order of waypoints. In that way, we only have to loop through the pixel map once.
A red-value of 3 is a crate, and a red-value of 4 is a set of spikes. In this case, the green value represents the starting state (down, rising or up).
Finally a red-value of 5 represents an exit, with its green-value being the level number (1-based!)*/

class Map
{
private:
	std::vector<Entity*> entityList;
	std::map<unsigned int, Enemy*> enemies;
	std::vector<Enemy*> enemyList;
	std::vector<Exit*> exitList;
	std::vector<Turret*> turretList;
	const Vector2f tileSize = Vector2f(32.0f, 32.0f);
	const Vector2f middle = tileSize / 2.0f;
	Vector2u mapSize;
	Image map;
	Vector2f spawnPoint = tileSize + middle;
	Vector2f getDirection(int alpha);
public:
	Map(String backgroundFile, String shadowMapFile, String collisionMapFile, Player & ourPlayer);
	~Map();
	Graphic background;
	Graphic shadowMap;
	std::vector<Entity*> getEntities();
	std::vector<Enemy*> getEnemies();
	std::vector<Exit*> getExits();
	std::vector<Turret*> getTurrets();
	Vector2f getSpawnPoint();
};

#endif
