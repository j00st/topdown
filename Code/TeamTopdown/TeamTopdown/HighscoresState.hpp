#ifndef HighscoresState_HPP
#define HighscoresState_HPP

#include "stdafx.h"
#include <string>
#include "GameState.hpp"
#include "GameStateManager.hpp"
#include "controlsInput.h"
#include "Graphic.h"

/// The gamestate that shows the highscores.
//
/// This gamestate shows the highscores screen. Pressing space/enter/backspace
/// lets the player return to the main menu.
class HighscoresState : public GameState {
private:
	sf::RenderWindow & window;
	ControlsInput & controlsInput;
	GameStateManager & gsm;

	Graphic background = Graphic("sprites/op0.png");
	View view;

	sf::Font font1;
	sf::Text text1;
public:
	/// The title screen's constructor method.
	//
	/// The title screen's constructor requires the gamestatemanager to be able
	/// to switch states and the controlsinput object to read user input.
	HighscoresState(sf::RenderWindow & window, GameStateManager & gsm, ControlsInput & ci);
	/// The title screen's game loop method for handling user input.
	//
	/// This method handles all user input related to this gamestate. Pressing
	/// space/enter lets the player proceed to the main menu.
	void HandleInput();
	/// The title screen's game loop method for updating the game.
	//
	/// Currently only checks if a gamestate switch should be executed.
	void Update();
	/// The title screen's game loop method for drawing on the window.
	//
	/// Draws the background and text on the screen.
	void Draw(sf::RenderWindow & window);
	/// The intro state's reset method to reset all values to default.
	//
	/// 
	void Reset();
};

#endif // HighscoresState_HPP