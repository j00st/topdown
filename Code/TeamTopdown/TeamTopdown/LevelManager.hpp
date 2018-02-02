#ifndef LevelManager_HPP
#define LevelManager_HPP

#include "stdafx.h"
#include "GameLoopObject.hpp"
#include "EntityController.h"
#include "Map.h"
#include "Player.h"
#include "Cursor.h"
#include "controlsInput.h"
#include "Timer.h"

using namespace sf;

/// Works together with the PlayingState to handle maps, entities and music.
//
/// The level manager loads the map of the current level, creates a corresponding 
/// entity controller and handles background music.
class LevelManager : public GameLoopObject {
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
	/// The level manager's constructor method. Sets background music.
	//
	/// 'nuff said.
	LevelManager(Player & plr, Cursor & cr, ControlsInput & ci);
	/// Calls the entity controller's update method.
	//
	/// 'nuff said.
	void Update();
	/// Calls the entity controller's draw method.
	//
	/// 'nuff said.
	void Draw(sf::RenderWindow & window);
	/// Resets music and player stats.
	//
	/// 'nuff said.
	void Reset();
	/// Returns the current level
	//
	/// Returns an int with the current level. Nothing else.
	int GetCurrentLevel();
	/// Restarts the current level.
	//
	/// Restarts the current level by resetting player stats, resurrecting the
	/// player, reloading the map and reloading the entity controller.
	void RestartCurrentLevel();
	/// Switches to a selected level.
	//
	/// Loads a new map and entity controller for the new level. Does not reset
	/// player stats etc.
	void SwitchToLevel(int selectedLevel);
	/// Asks the entity controller if the player stepped on a level switching block.
	//
	/// Calls a method in the entity controller that checks if the player
	/// collides with a level switching block. The value returned tells to which
	/// level the game should switch.
	int GetExitingBlock();
	/// Gets the shaketimer from the entity controller.
	//
	/// 'nuff said.
	Timer GetShakeTimer();
	/// Returns the player's original spawn point as a Vector2f.
	//
	/// 'nuff said.
	Vector2f GetSpawnPoint();
};

#endif // LevelManager_HPP