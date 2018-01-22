// TeamTopdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameStateManager.hpp"
#include "MainMenuState.hpp"
#include "Level1State.hpp"
#include "Player.h"
#include "Camera.h"
#include "Cursor.h"
#include "Crate.h"
#include "EntityController.h"
#include "Graphic.h"
#include "controlsInput.h"
#include "controlsController.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	// window setup
	RenderWindow window(VideoMode(1200, 800), "Team TopDown - Prison Break", Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	window.setMouseCursorVisible(false);
	window.setFramerateLimit(60); //60 fps cinematic experience

	// object setup
	ControlsInput controlsInput;
	ControlsController controlsController(controlsInput, window);
	Cursor cursor(controlsInput);

	Player player(Vector2f(64.0f, 64.0f), Vector2f(32.0f, 32.0f), controlsInput);

	// camera setup
	View view;
	view.setSize(Vector2f(1280, 720)); //view.setCenter(Vector2f(1280, 720));
	Camera camera(view, player, window, Vector2f(1920, 1080));
	RectangleShape mouseObject(Vector2f(20,20));
	mouseObject.setFillColor(Color::White);
	Vector2f mousePos;
	auto EC = EntityController(player, controlsInput);
	/*PlayerTemp player(Vector2f(500.0f, 500.0f), Vector2f(20.0f, 20.0f));
	Crate c1(Vector2f(200.0f, 200.0f), Vector2f(40.0f, 40.0f));*/
	//Crate c2(Vector2f(70.0f, 50.0f), Vector2f(20.0f, 20.0f));





	/*
	 * GameStateManager setup
	 */

	
	GameStateManager gameStateManager;
	gameStateManager.AddGameState("MainMenu", new MainMenuState(window, controlsController, controlsInput, gameStateManager));
	gameStateManager.AddGameState("Level1State", new Level1State(window, gameStateManager, controlsController, controlsInput, EC, camera, cursor));
	gameStateManager.SetNext("Level1State");
	gameStateManager.SwitchState();


	int i = 0;


	// main loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();
			if (GetAsyncKeyState(27)) window.close(); // close fullscreen window when esc is pressed
		}

		//update
		
		//controlsController.update(); // updates controlsInput
		std::cout << controlsInput.wKeyPressed;
		//camera.update();
		//EC.update();
		

		//draw
		//background.draw(Vector2f(0, 0));
//		mousePos = Vector2f(Mouse::getPosition(window));
//		mousePos.x = mousePos.x - 10;
//		mousePos.y = mousePos.y - 10;
//		mouseObject.setPosition(mousePos);

		/*

		if (i < 60) i++;
		else if (i == 60)
		{
			gameStateManager.SetNext("Level1State");
			gameStateManager.SwitchState();
			i++;
		}
		else if (i > 60) i++;
		if (i == 120)
		{
			gameStateManager.SetNext("MainMenu");
			gameStateManager.SwitchState();
			i = 0;
		}
		
		*/




		

		// update

		gameStateManager.HandleInput();
		gameStateManager.Update();
		// draw
		gameStateManager.Draw();

		
		



		/*

		//draw
		window.clear();
		window.draw(mouseObject);
		EC.draw(window);
		window.display();

		*/
	}

	return 0;
}