#ifndef MAP_HEADER
#define MAP_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Crate.h"
#include "Wall.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Map
{
private:
	std::vector<Entity*> entityList;
	std::map<unsigned int, Enemy*> enemies;
	Vector2f tileSize = Vector2f(32.0f, 32.0f);
	Vector2f middle = tileSize / 2.0f;
	Vector2u mapSize;
	Image map;
	Vector2f spawnPoint = tileSize + middle;
public:
	Map(String path);
	std::vector<Entity*> getEntities();
	Vector2f getSpawnPoint();
};

#endif
