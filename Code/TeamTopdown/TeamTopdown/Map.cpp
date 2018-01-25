#include "stdafx.h"
#include "Map.h"

Map::Map(String path)
{
	map.loadFromFile(path);
	mapSize = map.getSize();
}

std::vector<Entity*> Map::getEntities(Vector2f & lookatobj) {
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
						enemies.insert(std::pair<unsigned int, Enemy*>(entityColor.g, new Enemy(position, entityColor.b,Vector2f(24.0, 24.0),false,false,lookatobj)));
					}
					else { //add waypoint
						enemies[entityColor.g]->addWaypoint(position, entityColor.b);
					}
					break;
				case 3: //crates
					entityList.push_back(new Crate(position, tileSize));
					break;
			}
		}
	}
	for (std::map<unsigned int, Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
		entityList.push_back(it->second);
	}
	return entityList;
}

Vector2f Map::getSpawnPoint() {
	return spawnPoint;
}