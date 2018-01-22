#ifndef MAP_HEADER
#define MAP_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Crate.h"
#include "Wall.h"
#include <SFML/Graphics.hpp>

using namespace sf;

/*! \class Map
\brief Creates an entity list based on a collision map
This class creates a list of entities based on the red value of a .png-file.
We loop through the pixels to determine a position. The tile size is constant and set.
Once we find a pixel with a red-value of 1, we spawn a wall at that position with our set size and add it to the entity list.
A red-value of 2 indicates a crate, and a red-value of 3 is a player spawn point.
*/

class Map
{
private:
	std::vector<Entity*> entityList;
	const Vector2f tileSize = Vector2f(32.0f, 32.0f);
	const Vector2f middle = tileSize / 2.0f;
	Vector2u mapSize;
	Image map;
	Vector2f spawnPoint = tileSize + middle;
public:
	Map(String path);
	std::vector<Entity*> getEntities();
	Vector2f getSpawnPoint();
};

#endif
