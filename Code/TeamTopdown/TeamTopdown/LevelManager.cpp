#include "stdafx.h"
#include "LevelManager.hpp"
#include <iostream>


LevelManager::LevelManager(Player & plr, Cursor & cr, ControlsInput & ci) :
	player(plr),
	cursor(cr),
	controlsInput(ci)
{
	// load music
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
		std::cout << "Restart level " << currentLevel << std::endl;
		delete map, entityController;
	case 1: { // Restart level 1
		map = new Map("sprites/map1.png", "sprites/map1s.png", "sprites/map1c.png", player);
		break;
	}
	case 2: { // Restart level 2
		map = new Map("sprites/map2.png", "sprites/map2s.png", "sprites/map2c.png", player);
		break;
	}
	case 3: { // Restart level 3
		map = new Map("sprites/map3.png", "sprites/map3s.png", "sprites/map3c.png", player);
		break;
	}
	case 4: { // Restart level 4
		map = new Map("sprites/map4.png", "sprites/map4s.png", "sprites/map4c.png", player);
		break;
	}
	} // end switch
	entityController = new EntityController(player, cursor, controlsInput, map);
}

void LevelManager::SwitchToLevel(int selectedLevel) {
	switch (selectedLevel) {
		std::cout << "Switch to level " << selectedLevel << std::endl;
	case 1: { // (re)load level 1
		map = new Map("sprites/map1.png", "sprites/map1s.png", "sprites/map1c.png", player);
		level1music.play();
		break;
	}
	case 2: { // (re)load level 2
		map = new Map("sprites/map2.png", "sprites/map2s.png", "sprites/map2c.png", player);
		level1music.stop(); // if entering from lvl 1
		level2music.play();
		break;
	}
	case 3: { // (re)load level 3
		map = new Map("sprites/map3.png", "sprites/map3s.png", "sprites/map3c.png", player);
		level2music.stop(); // if entering from lvl 2
		level3music.play();
		break;
	}
	case 4: { // (re)load level 4
		map = new Map("sprites/map4.png", "sprites/map4s.png", "sprites/map4c.png", player);
		level3music.stop(); // if entering from lvl 3
		level4music.play();
		break;
	}
	} // end switch
	entityController = new EntityController(player, cursor, controlsInput, map);
	currentLevel = selectedLevel;
}

void LevelManager::Reset() {	
	player.stats.Reset();
	level1music.play();
	level2music.stop();
	level3music.stop();
	level4music.stop();
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

