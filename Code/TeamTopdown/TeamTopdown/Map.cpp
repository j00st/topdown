#include "stdafx.h"
#include "Map.h"

Map::Map(String backgroundFile, String shadowMapFile, String collisionMapFile, Player & ourPlayer):
	background(Graphic(backgroundFile)),
	shadowMap(Graphic(shadowMapFile))
{
	map.loadFromFile(collisionMapFile);
	mapSize = map.getSize();
	for (unsigned int y = 0; y < mapSize.y; y++) {
		for (unsigned int x = 0; x < mapSize.x; x++) {
			Vector2f position(tileSize.x * x, tileSize.y * y);
			Color entityColor = map.getPixel(x, y);
			switch (entityColor.r) {
			case 0: //wall
				entityList.push_back(new Wall(position, tileSize));
				break;
			case 30:	//player start point
				spawnPoint = position + middle;
				break;
			case 60: //enemy spawn point
				if (enemies.find(entityColor.g) == enemies.end()) { //create new enemy
					enemies.insert(std::pair<unsigned int, Enemy*>(entityColor.g, new Enemy(position + middle, entityColor.b, Vector2f(20.0, 20.0), true, 0, false, ourPlayer.position, getDirection(entityColor.a))));
				}
				else { //add waypoint
					enemies[entityColor.g]->addWaypoint(position + middle, entityColor.b);
				}
				break;
			case 90: //crates
				entityList.push_back(new Crate(position, tileSize));
				break;
			case 120: //spikes
				entityList.push_back(new Spike(position, entityColor.g, ourPlayer));
				break;
			case 150: //exit
				exitList.push_back(new Exit(position, entityColor.g, tileSize));
				break;
			case 180: //turret
				turretList.push_back(new Turret(position + middle, tileSize, getDirection(entityColor.a), entityColor.b));
				break;
			}
		}
	}
	for (std::map<unsigned int, Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
		it->second->createWaypointQueue();
		enemyList.push_back(it->second);
	}
	enemies.clear();
}

Map::~Map() {
	for (std::vector<Entity*>::iterator it = entityList.begin(); it != entityList.end(); ++it) {
		delete (*it);
	}
	entityList.clear();
	for (std::map<unsigned int, Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
		delete (*it).second;
	}
	enemies.clear();
	for (std::vector<Enemy*>::iterator it = enemyList.begin(); it != enemyList.end(); ++it) {
		delete (*it);
	}
	enemyList.clear();
	for (std::vector<Turret*>::iterator it = turretList.begin(); it != turretList.end(); ++it) {
		delete (*it);
	}
	turretList.clear();
	for (std::vector<Exit*>::iterator it = exitList.begin(); it != exitList.end(); ++it) {
		delete (*it);
	}
	exitList.clear();
}
Vector2f Map::getDirection(int alpha) {
	switch (alpha) {
	case 255: // looking right
		return Vector2f(1, 0);
	case 254: //looking up
		return Vector2f(0, -1);
	case 253: //looking left
		return Vector2f(-1, 0);
	case 252: //looking down
		return Vector2f(0, 1);
	}
}
std::vector<Entity*> Map::getEntities() {
	return entityList;
}

std::vector<Enemy*> Map::getEnemies() {
	return enemyList;
}

std::vector<Exit*> Map::getExits() {
	return exitList;
}

std::vector<Turret*> Map::getTurrets() {
	return turretList;
}
Vector2f Map::getSpawnPoint() {
	return spawnPoint;
}