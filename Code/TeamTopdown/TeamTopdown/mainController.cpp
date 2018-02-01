// TeamTopdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameStateManager.hpp"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"
#include "Cursor.h"
#include "Crate.h"
#include "EntityController.h"
#include "Graphic.h"
#include "controlsInput.h"
#include "controlsController.h"
#include "LevelManager.hpp"
#include "AllGameStates.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	/*
	 * window setup
	 */
	std::vector<sf::VideoMode> i = sf::VideoMode::getFullscreenModes();
	RenderWindow window(i.front(), "SFML WORKS!", Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60); //60 fps cinematic experience

	/*
	 * controls setup
	 */
	ControlsInput controlsInput;
	ControlsController controlsController(controlsInput, window);

	/*
	* object setup
	*/
	Cursor cursor = Cursor(window, Vector2f(100, 100), Vector2f(16, 16), controlsInput, 0);
	Player player = Player(Vector2f(0, 0), Vector2f(16.0f, 16.0f), cursor, controlsInput);

	Mouse::setPosition(Vector2i(640, 360));
	RectangleShape mouseObject(Vector2f(20, 20));
	Vector2f mousePos;

	/*
	 * camera setup
	 */
	View view;
	view.setSize(Vector2f(640, 360));
	Camera camera(view, player, window, Vector2f(1920, 1080));

	/*
	 * GameStateManager setup
	 */
	LevelManager levelManager(player, cursor, controlsInput);
	GameStateManager gameStateManager;
	//gameStateManager.AddGameState("Intro", new IntroState(window, gameStateManager, controlsInput));
	gameStateManager.AddGameState("TitleScreen", new TitleScreenState(window, gameStateManager, controlsInput));
	gameStateManager.AddGameState("Highscores", new HighscoresState(window, gameStateManager, controlsInput));
	gameStateManager.AddGameState("Credits", new CreditsState(window, gameStateManager, controlsInput));
	gameStateManager.AddGameState("MainMenu", new MainMenuState(window, gameStateManager, controlsInput, levelManager, camera, cursor, player));
	gameStateManager.AddGameState("Playing", new PlayingState(window, gameStateManager, controlsInput, levelManager, camera, cursor, player));
	//gameStateManager.AddGameState("Level1", new Level1State(window, gameStateManager, controlsInput, camera, cursor, player));
	//gameStateManager.AddGameState("Level2", new Level2State(window, gameStateManager, controlsInput, camera, cursor, player));
	//gameStateManager.AddGameState("Level3", new Level3State(window, gameStateManager, controlsInput, camera, cursor, player));
	//gameStateManager.AddGameState("Level4", new Level4State(window, gameStateManager, controlsInput, camera, cursor, player));
	gameStateManager.SetNext("TitleScreen");
	gameStateManager.SwitchState();

	/*
	 * Game Loop
	 */
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();
			if (GetAsyncKeyState(27)) window.close(); // close fullscreen window when esc is pressed
		}

		//update
		controlsController.update(); // updates controlsInput
		gameStateManager.HandleInput();
		gameStateManager.Update();
		gameStateManager.Draw(window);
	}
	return 0;
}