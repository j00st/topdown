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
/// In this gamestate, the player should be able to select buttons that will
/// start the game, exit the game, and other functionality that is yet to be
/// implemented. Currently, pressing 1 switches to the level1state that contains
/// all gameplay implemented so far. Returning from level1state to mainmenustate
/// introduces a bug with camera zoom.
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
	sf::Music level1Ost;
	sf::Music level2Ost;
	sf::Music levelOst3;
	sf::Music level4Ost;


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
	/// gamestatemanger to switch to other gamestates and controlsinput so it
	/// can read keyboard and mouse inputs. These will be initialized in the
	/// constructor method.
	//
	/// At the moment, this also sets a placeholder text to be displayed on the
	/// screen. 
	MainMenuState(sf::RenderWindow & window, GameStateManager & gsm, 
		ControlsInput & ci, LevelManager & lm, Camera & cm, Cursor & cr, Player & plr);
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
	void Draw(sf::RenderWindow & window);
	/// The state's reset method. Resets the menu to default.
	//
	/// Hides level select menu, shows main menu.
	void Reset();
	/*! void transitionFromThis
	/brief Initiates a screen transition towards the next state.*/
	void transitionFromThis();
};

#endif // MainMenuState_HPP