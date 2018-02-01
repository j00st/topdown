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
	level1music.openFromFile("audio/music/level01.wav");
	level2music.openFromFile("audio/music/level02.wav");
	level3music.openFromFile("audio/music/level03.ogg");
	level4music.openFromFile("audio/music/level04.wav");
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
	player.TriggerLife();

	switch (currentLevel) {
	case 0: // nothing
		break;
	case 1: { // Restart level 1
		delete map, entityController;
		map = new Map("sprites/map1.png", "sprites/map1s.png", "sprites/map1c.png", player);
		entityController = new EntityController(player, cursor, controlsInput, map);
		break;
	}
	case 2: { // Restart level 2
		delete map, entityController;
		map = new Map("sprites/map2.png", "sprites/map2s.png", "sprites/map2c.png", player);
		entityController = new EntityController(player, cursor, controlsInput, map);
		break;
	}
	case 3: { // Restart level 3
		delete map, entityController;
		map = new Map("sprites/map3.png", "sprites/map3s.png", "sprites/map3c.png", player);
		entityController = new EntityController(player, cursor, controlsInput, map);
		break;
	}
	case 4: { // Restart level 4
		delete map, entityController;
		map = new Map("sprites/map4.png", "sprites/map4s.png", "sprites/map4c.png", player);
		entityController = new EntityController(player, cursor, controlsInput, map);
		break;
	}
	} // end switch
}

void LevelManager::SwitchToLevel(int selectedLevel) {
	switch (selectedLevel) {
	case 0: // nothing pressed
		break;
	case 1: { // Reload level 1
		map = new Map("sprites/map1.png", "sprites/map1s.png", "sprites/map1c.png", player);
		entityController = new EntityController(player, cursor, controlsInput, map);
		level1music.play();
		level2music.stop();
		level3music.stop();
		level4music.stop();
		currentLevel = 1;
		break;
	}
	case 2: { // Reload level 2
		map = new Map("sprites/map2.png", "sprites/map2s.png", "sprites/map2c.png", player);
		entityController = new EntityController(player, cursor, controlsInput, map);
		//level1music.play();
		level2music.stop();
		level3music.stop();
		level4music.stop();
		currentLevel = 2;
		break;
	}
	case 3: { // Reload level 3
		map = new Map("sprites/map3.png", "sprites/map3s.png", "sprites/map3c.png", player);
		entityController = new EntityController(player, cursor, controlsInput, map);
		level1music.stop();
		level2music.play();
		level3music.stop();
		level4music.stop();
		currentLevel = 3;
		break;
	}
	case 4: { // Reload level 4
		map = new Map("sprites/map4.png", "sprites/map4s.png", "sprites/map4c.png", player);
		entityController = new EntityController(player, cursor, controlsInput, map);
		level1music.stop();
		level2music.stop();
		level3music.stop();
		level4music.play();
		currentLevel = 4;
		break;
	}
	} // end switch
}

void LevelManager::Reset() {
	player.stats.Reset();
	
	// load level 1 map
	//map = new Map("sprites/map1.png", "sprites/map1s.png", "sprites/map1c.png", player);
	//entityController = new EntityController(player, cursor, controlsInput, map);
	level1music.play();
	level2music.stop();
	level3music.stop();
	level4music.stop();
	currentLevel = 1;
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

