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

void LevelManager::SelectLevel(int selectedLevel) {

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