// Game1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "GameStateManager.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 1024), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);


	GameStateManager gameStateManager;
	gameStateManager.AddGameState("MainMenu", new MainMenuState(window));
	gameStateManager.SetNext("MainMenu");
	gameStateManager.SwitchState();

	// states deleten
	// for auto gs in gamestatemanager.getstates()
	//	delete gs
	// want pointers

	// of gsm wordt eigenaar van pointer en mag deleten
	// dan uniquepointer gebruiken unique_ptr









	//MainMenuState mm1(window);




	while (window.isOpen())
	{
		sf::Event event;

		// handle input
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		gameStateManager.HandleInput();

		// update
		gameStateManager.Update();

		// draw
		gameStateManager.Draw();
	}

	return 0;
}