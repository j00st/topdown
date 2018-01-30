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
#include "IntroState.hpp"
#include "TitleScreenState.hpp"
#include "CreditsState.hpp"
#include "MainMenuState.hpp"
#include "Level1State.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	/*
	 * window setup
	 */
	std::vector<sf::VideoMode> i = sf::VideoMode::getFullscreenModes();
	RenderWindow window(i.front(), "SFML WORKS!", Style::Fullscreen);
	//RenderWindow window(VideoMode(1280, 720), "SFML works!", Style::Fullscreen);// , Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	//window.setMouseCursorVisible(false);
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
	Player player = Player(Vector2f(0, 0), Vector2f(12.0f, 12.0f), cursor, controlsInput);

	Mouse::setPosition(Vector2i(640, 360));
	RectangleShape mouseObject(Vector2f(20, 20));
	mouseObject.setFillColor(Color::White);
	Vector2f mousePos;
	/*PlayerTemp player(Vector2f(500.0f, 500.0f), Vector2f(20.0f, 20.0f));
	Crate c1(Vector2f(200.0f, 200.0f), Vector2f(40.0f, 40.0f));*/
	//Crate c2(Vector2f(70.0f, 50.0f), Vector2f(20.0f, 20.0f));

	/*
	 * camera setup
	 */
	View view;
	view.setSize(Vector2f(640, 360));
	Camera camera(view, player, window, Vector2f(1920, 1080));

	/*
	 * GameStateManager setup
	 */
	GameStateManager gameStateManager;
	gameStateManager.AddGameState("Intro", new IntroState(window, gameStateManager, controlsInput));
	gameStateManager.AddGameState("TitleScreen", new TitleScreenState(window, gameStateManager, controlsInput));
	gameStateManager.AddGameState("Credits", new CreditsState(window, gameStateManager, controlsInput));
	gameStateManager.AddGameState("MainMenu", new MainMenuState(window, gameStateManager, controlsInput, camera, cursor, player));
	gameStateManager.AddGameState("Level1State", new Level1State(window, gameStateManager, controlsInput, camera, cursor, player));
	gameStateManager.SetNext("Intro");
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
		//camera.update();
		//EC.update();

		//draw
		//window.clear(Color::Color(22, 23,25));
		//EC.draw(window);
		//window.display();
	}
	return 0;
}