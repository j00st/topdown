#ifndef CreditsState_HPP
#define CreditsState_HPP

#include "stdafx.h"
#include <string>
#include "GameState.hpp"
#include "GameStateManager.hpp"
#include "controlsInput.h"
#include "Graphic.h"

/// The gamestate that shows the credits screen.
//
/// This game shows the credits screen. Pressing space/enter/backspace lets the
/// player return to the main menu.
class CreditsState : public GameState {
private:
	sf::RenderWindow & window;
	ControlsInput & controlsInput;
	GameStateManager & gsm;

	Graphic background = Graphic("sprites/op0.png");
	View view;

	sf::Font font1;
	sf::Text text1;
public:
	/// The credits screen's constructor method.
	//
	/// The credits screen's constructor requires a window to draw on, the
	/// gamestatemanager to be able to switch states and the controlsinput 
	/// to read user input.
	CreditsState(sf::RenderWindow & window, GameStateManager & gsm, ControlsInput & ci);
	/// The credits screen's game loop method for handling user input.
	//
	/// This method handles all user input related to this gamestate. Pressing
	/// space/enter/backspace lets the player return to the main menu.
	void HandleInput();
	/// The credits screen's game loop method for updating the game.
	//
	/// Currently only checks if a gamestate switch should be executed.
	void Update();
	/// The credits screen's game loop method for drawing on the window.
	//
	/// Draws the background and text on the screen.
	void Draw(sf::RenderWindow & window);
	/// The credits state's reset method to reset all values to default.
	//
	/// Doesn't do anything.
	void Reset();
};

#endif // CreditsState_HPP