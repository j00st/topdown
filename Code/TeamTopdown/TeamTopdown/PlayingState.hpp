#ifndef PlayingState_HPP
#define PlayingState_HPP

#include "stdafx.h"
#include "GameStateManager.hpp"
#include "GameState.hpp"
#include "controlsController.h"
#include "controlsInput.h"
#include "LevelManager.hpp"
#include "EntityController.h"
#include "Camera.h"
#include "Cursor.h"
#include <string>
#include "Menu.hpp"

using namespace sf;

/// The gamestate handling all gameplay.
//
/// In this gamestate the player plays the game. Works together with the level
/// manager. The level manager handles the map, entitycontroller and music while
/// the playing state handles everything else (mainly the pause menu, level
/// switching and handling player death (animation and resurrection).
class PlayingState : public GameState {
private:
	sf::RenderWindow & window;
	GameStateManager & gsm;
	ControlsInput & controlsInput;
	LevelManager & levelManager;
	Camera & camera;
	Cursor & cursor;
	Player & player;
	int currentLevel;

	bool switchingStates = 0;

	sf::Font font1;
	sf::Text text1;
	sf::Text text2;

	Timer pause = Timer(60);

	Map * map;/*!< collision map */
	EntityController * entityController;
	Menu * pauseMenu;
	bool setup;
	Graphic tLeft = Graphic("sprites/transitionLeft.png");/*< graphic transition with jagged left side*/
	Graphic tRight = Graphic("sprites/transitionRight.png"); /*< graphic transition with jagged right side*/
	RectangleShape redness;
	int alpha;
public:
	/// The constructor method of the gamestate handling all gameplay.
	//
	/// Requires a window to draw on, the gamestatemanager to switch states,
	/// controlsinput to read keyboard and mouse input, the level manager for
	/// handling the map, entitycontroller and music, the camera to follow the
	/// player, the cursor (crosshair) and the player.
	PlayingState(sf::RenderWindow & window, GameStateManager & gsm, 
		ControlsInput & ci, LevelManager & lm, Camera & cm, Cursor & c, Player & p);
	/// The state's game loop method for handling keyboard and mouse input.
	//
	/// Handles all keyboard and mouse input. Pressing Escape opens the pause
	/// menu, from which the player can resume, restart the level, return to 
	/// main menu or quit the game. If the player died, pressing Space will 
	/// restart the level.
	void HandleInput();
	/// The state's game loop method for updating the game.
	//
	/// Updates everything gameplay related.
	void Update();
	/// The state's game loop method for drawing on the window.
	//
	/// Draws everything gameplay related to the screen.
	void Draw(sf::RenderWindow & window);
	/*! void transitionToThis
	/brief Initiates a screen transition when entering this state.*/
	void transitionToThis();
	/*! void transitionFromThis
	brief Initiates a screen transition towards the next state.*/
	void transitionFromThis();
};

#endif // PlayingState_HPP