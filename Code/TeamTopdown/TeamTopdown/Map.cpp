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
			case 0: //player spawn point
				spawnPoint = position + middle;
				break;
			case 1:	//walls
				entityList.push_back(new Wall(position, tileSize));
				break;
			case 2: //enemy spawn point
				if (enemies.find(entityColor.g) == enemies.end()) { //create new enemy
					enemies.insert(std::pair<unsigned int, Enemy*>(entityColor.g, new Enemy(position + Vector2f(8.0f, 8.0f), entityColor.b, Vector2f(16.0, 16.0), true, 0, false, ourPlayer.position)));
				}
				else { //add waypoint
					enemies[entityColor.g]->addWaypoint(position + Vector2f(8.0f, 8.0f), entityColor.b);
				}
				break;
			case 3: //crates
				entityList.push_back(new Crate(position, tileSize));
				break;
			case 4: //spikes
				entityList.push_back(new Spike(position, entityColor.g, ourPlayer));
			}
		}
	}
	for (std::map<unsigned int, Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
		it->second->createWaypointQueue();
		enemyList.push_back(it->second);
	}
	enemies.clear();
}

std::vector<Entity*> Map::getEntities() {
	return entityList;
}

std::vector<Enemy*> Map::getEnemies() {
	return enemyList;
}
Vector2f Map::getSpawnPoint() {
	return spawnPoint;
}