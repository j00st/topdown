#ifndef LevelManager_HPP
#define LevelManager_HPP

#include "stdafx.h"
#include "EntityController.h"
#include "Map.h"
#include "Player.h"
#include "Cursor.h"
#include "controlsInput.h"
#include "Timer.h"

/// The gamestate currently containing all gameplay.
//
/// In this gamestate the player can play the game. Pressing 2 switches back to
/// the main menu state. Currently, returning to the main menu introduces a bug
/// with zoom/camera on the main menu state.

using namespace sf;

class LevelManager {
private:
	Map * map;
	EntityController * entityController;

	Player & player;
	Cursor & cursor;
	ControlsInput & controlsInput;

	sf::Music level1music;
	sf::Music level2music;
	sf::Music level3music;
	sf::Music level4music;

	int currentLevel = 1;
public:
	/// Constructor method
	//
	///
	LevelManager(Player & plr, Cursor & cr, ControlsInput & ci);
	void Update();
	void Draw(sf::RenderWindow & window);
	int GetCurrentLevel();
	void RestartCurrentLevel();
	void SwitchToLevel(int selectedLevel);
	void Reset();

	int GetExitingBlock();
	Timer GetShakeTimer();
	Vector2f GetSpawnPoint();
};

#endif // LevelManager_HPP