#ifndef MainMenuState_HPP
#define MainMenuState_HPP

#include "stdafx.h"
#include <string>
#include <SFML/Audio.hpp>
#include "GameState.hpp"
#include "GameStateManager.hpp"
#include "controlsInput.h"
#include "Camera.h"
#include "Cursor.h"
#include "Player.h"
#include "Graphic.h"
#include "Menu.hpp"
#include "AllGameStates.hpp"
#include "PlayingState.hpp"
#include "LevelManager.hpp"

/// The gamestate that is the game's main menu.
//
/// In this gamestate, the player can start a new game, enter the level select
/// menu to choose which level to play, see the high scores (not implemented),
/// the credits and exit the game.
class MainMenuState : public GameState{
private:
	sf::RenderWindow & window;
	GameStateManager & gsm;
	ControlsInput & controlsInput;
	LevelManager & levelManager;
	Camera & camera;
	Cursor & cursor;
	Player & player;

	sf::Music menuOst;

	bool switchingStates = 0;

	Graphic background = Graphic("sprites/op0.png");
	View view;

	sf::Font font1;
	sf::Text text1;

	Menu * menu1;
	Menu * menu2;
	Graphic tLeft = Graphic("sprites/transitionLeft.png"); /*< graphic transition with jagged left side*/
	Graphic tRight = Graphic("sprites/transitionRight.png"); /*< graphic transition with jagged right side*/
public:
	/// The main menu's constructor method.
	//
	/// The main menu's constructor requires a window to draw on, the
	/// gamestatemanger to switch to other gamestates, controlsinput to read
	/// keyboard and mouse input, the levelmanager to set the level to play, the
	/// cursor (not used anymore) and the player to access the HUD to reset time.
	MainMenuState(sf::RenderWindow & window, GameStateManager & gsm, 
		ControlsInput & ci, LevelManager & lm, Camera & cm, Cursor & cr, Player & plr);
	/// The main menu's game loop method for handling keyboard and mouse input.
	//
	/// Handles input for the main menu.
	void HandleInput();
	/// The main menu's game loop method for updating the game.
	//
	/// Starts main menu music. Updates the main menu.
	void Update();
	/// The main menu's game loop method for drawing on the window.
	//
	/// Draws the background and either the main menu or the level select menu.
	void Draw(sf::RenderWindow & window);
	/// The state's reset method. Resets the menu to default.
	//
	/// Resets main menu if level select menu is up. Stops music.
	void Reset();
	/*! void transitionFromThis
	/brief Initiates a screen transition towards the next state.*/
	void transitionFromThis();
};

#endif // MainMenuState_HPP