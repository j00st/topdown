#include "stdafx.h"
#include "Map.h"

Map::Map(String path)
{
	map.loadFromFile(path);
	mapSize = map.getSize();
}

std::vector<Entity*> Map::getEntities() {
	for (unsigned int y = 0; y < mapSize.y; y++) {
		for (unsigned int x = 0; x < mapSize.x; x++) {
			Vector2f currentPosition(tileSize.x * x, tileSize.y * y);
			Color entityColor = map.getPixel(x, y);
			unsigned int entity = entityColor.r;
			switch (entity) {
			case 0: //floor
				break;
			case 1:	//walls
				entityList.push_back(new Wall(currentPosition, tileSize));
				break;
			case 2: //crates
				entityList.push_back(new Crate(currentPosition, tileSize));
				break;
			case 3: //spawn point
				spawnPoint = currentPosition + middle;
				break;
			}
			
		}
	}
	return entityList;
}

Vector2f Map::getSpawnPoint() {
	return spawnPoint;
}