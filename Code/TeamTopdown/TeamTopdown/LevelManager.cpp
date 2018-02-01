#include "stdafx.h"
#include "LevelManager.hpp"
#include <iostream>


LevelManager::LevelManager(Player & plr, Cursor & cr, ControlsInput & ci) :
	player(plr),
	cursor(cr),
	controlsInput(ci)
{
	// load level 1 map
	map = new Map("sprites/map1.png", "sprites/map1s.png", "sprites/map1c.png", player);
	entityController = new EntityController(player, cursor, controlsInput, map);
}

void LevelManager::Update() {
	entityController->update();
}

void LevelManager::Draw(sf::RenderWindow & window) {
	entityController->draw(window);
}

int LevelManager::GetCurrentLevel() {
	return currentLevel;
}

void LevelManager::RestartCurrentLevel() {
	player.stats.Reset();

	switch (currentLevel) {
	case 0: // nothing
		std::cout << "RestartCurrentLevel: currentLevel = 0" << std::endl;
		break;
	case 1: { // Restart level 1
		std::cout << "Restart level 1" << std::endl;
		entityController = new EntityController(player, cursor, controlsInput, map);
		break;
	}
	case 2: { // Restart level 2
		std::cout << "Restart level 1" << std::endl;
		entityController = new EntityController(player, cursor, controlsInput, map);
		break;
	}
	case 3: { // Restart level 3
		std::cout << "Restart level 1" << std::endl;
		entityController = new EntityController(player, cursor, controlsInput, map);
		break;
	}
	case 4: { // Restart level 4
		std::cout << "Restart level 1" << std::endl;
		entityController = new EntityController(player, cursor, controlsInput, map);
		break;
	}
	} // end switch
}

void LevelManager::SwitchToLevel(int selectedLevel) {
	switch (selectedLevel) {
	case 0: // nothing pressed
		std::cout << "SwitchToLevel called with parameter 0" << std::endl;
		break;
	case 1: { // Reload level 1
		std::cout << "Switch to level 1" << std::endl;
		map = new Map("sprites/map1.png", "sprites/map1s.png", "sprites/map1c.png", player);
		entityController = new EntityController(player, cursor, controlsInput, map);
		break;
	}
	case 2: { // Reload level 2
		std::cout << "Switch to level 1" << std::endl;
		map = new Map("sprites/map2.png", "sprites/map2s.png", "sprites/map2c.png", player);
		entityController = new EntityController(player, cursor, controlsInput, map);
		break;
	}
	case 3: { // Reload level 3
		std::cout << "Switch to level 1" << std::endl;
		map = new Map("sprites/map3.png", "sprites/map3s.png", "sprites/map3c.png", player);
		entityController = new EntityController(player, cursor, controlsInput, map);
		break;
	}
	case 4: { // Reload level 4
		std::cout << "Switch to level 1" << std::endl;
		map = new Map("sprites/map4.png", "sprites/map4s.png", "sprites/map4c.png", player);
		entityController = new EntityController(player, cursor, controlsInput, map);
		break;
	}
	} // end switch
}

void LevelManager::Reset() {
	player.stats.Reset();
	// do stuff
}

int LevelManager::GetExitingBlock() {
	return entityController->exiting();
}

Timer LevelManager::GetShakeTimer() {
	return entityController->shakeTimer;
}

Vector2f LevelManager::GetSpawnPoint() {
	return map->getSpawnPoint();
}

