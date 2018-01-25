#ifndef Level1State_HPP
#define Level1State_HPP

#include "stdafx.h"
#include "GameStateManager.hpp"
#include "GameState.hpp"
#include "controlsController.h"
#include "controlsInput.h"
#include "EntityController.h"
#include "Camera.h"
#include "Cursor.h"
#include <string>

/// The gamestate currently containing all gameplay.
//
/// In this gamestate the player can play the game. Pressing 2 switches back to
/// the main menu state. Currently, returning to the main menu introduces a bug
/// with zoom/camera on the main menu state.
class Level1State : public GameState {
private:
	sf::RenderWindow & window;
	GameStateManager & gsm;
	ControlsInput & controlsInput;
	EntityController & entityCtrl;
	Camera & camera;
public:
	/// The constructor method of the gamestate with all gameplay.
	//
	/// Requires a window to draw on, the gamestatemanager to switch states,
	/// controlsinput to read keyboard and mouse input, the entitycontroller to
	/// update and draw objects and the camera that follows the player.
	//
	/// These objects are initialized in the constructor method and handle the
	/// gameplay through their update and draw methods.
	Level1State(sf::RenderWindow & window, GameStateManager & gsm, ControlsInput & ci, EntityController & ec, Camera & cm);
	/// The state's game loop method for handling keyboard and mouse input.
	//
	/// Currently, pressing 2 switches to main menu. Nothing else yet.
	void HandleInput();
	/// The state's game loop method for updating the game.
	//
	/// checks if the state should be switched. updates camera. updates the
	/// entitycontroller.
	void Update();
	/// The state's game loop method for drawing on the window.
	//
	/// the entitycontroller's draw is called.
	void Draw(sf::RenderWindow & window);
};

#endif // Level1State_HPP