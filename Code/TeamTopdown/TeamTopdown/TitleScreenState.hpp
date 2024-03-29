#ifndef TitleScreenState_HPP
#define TitleScreenState_HPP

#include "stdafx.h"
#include <string>
#include "GameState.hpp"
#include "GameStateManager.hpp"
#include "controlsInput.h"
#include "Graphic.h"
#include <time.h>
#include <SFML\Audio.hpp>

/// The gamestate that shows the title screen. The first thing the player sees.
//
/// This game shows the title screen. Pressing space/enter lets the player
/// proceed to the main menu. This state is the first thing the player sees.
class TitleScreenState : public GameState {
private:
	sf::RenderWindow & window;
	ControlsInput & controlsInput;
	GameStateManager & gsm;

	Graphic background = Graphic("sprites/op0.png");
	View view;

	bool switchingStates = 0;

	sf::SoundBuffer SBload;
	sf::SoundBuffer SBshot;
	sf::Sound SEload;
	sf::Sound SEshot;

	sf::Font font1;
	sf::Text text1;
public:
	/// The title screen's constructor method.
	//
	/// The title screen's constructor requires the gamestatemanager to be able
	/// to switch states and the controlsinput object to read user input.
	TitleScreenState(sf::RenderWindow & window, GameStateManager & gsm, ControlsInput & ci);
	/// The title screen's game loop method for handling user input.
	//
	/// This method handles all user input related to this gamestate. Pressing
	/// space/enter lets the player proceed to the main menu.
	void HandleInput();
	/// The title screen's game loop method for updating the game.
	//
	/// Only checks if a gamestate switch should be executed.
	void Update();
	/// The title screen's game loop method for drawing on the window.
	//
	/// Draws the background and text on the screen. Text disappears when the
	/// player presses space/enter to proceed to the main menu.
	void Draw(sf::RenderWindow & window);
	/// The title screen's reset method.
	//
	/// Does nothing.
	void TitleScreenState::Reset();
};

#endif // TitleScreenState_HPP