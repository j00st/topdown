#ifndef MainMenuState_HPP
#define MainMenuState_HPP

#include "stdafx.h"
#include "GameState.hpp"
#include "controlsController.h"
#include "controlsInput.h"
#include "GameStateManager.hpp"
#include <string>

/// The gamestate that is the game's main menu.
//
/// In this gamestate, the player should be able to select buttons that will
/// start the game, exit the game, and other functionality that is yet to be
/// implemented. Currently, pressing 1 switches to the level1state that contains
/// all gameplay implemented so far. Returning from level1state to mainmenustate
/// introduces a bug with camera zoom.
class MainMenuState : public GameState{
private:
	sf::RenderWindow & window;
	ControlsInput & controlsInput;
	GameStateManager & gsm;

	sf::Font font1;
	sf::Text text1;
public:
	/// The main menu's constructor method.
	//
	/// The main menu's constructor requires a window to draw on, the
	/// gamestatemanger to switch to other gamestates and controlsinput so it
	/// can read keyboard and mouse inputs. These will be initialized in the
	/// constructor method.
	//
	/// At the moment, this also sets a placeholder text to be displayed on the
	/// screen. 
	MainMenuState(sf::RenderWindow & w, GameStateManager & gsm, ControlsInput & ci);
	/// The main menu's game loop method for handling keyboard and mouse input.
	//
	/// Currently, pressing 1 switches to Level1State. Nothing else yet.
	void HandleInput();
	/// The main menu's game loop method for updating the game.
	//
	/// Currently only checks if a gamestate switch should be executed.
	void Update();
	/// The main menu's game loop method for drawing on the window.
	//
	/// Currently only refreshes a red background and draws green placeholder
	/// text.
	void Draw();
};

#endif // MainMenuState_HPP