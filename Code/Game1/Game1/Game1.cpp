// Game1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "GameStateManager.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	// protected static?
	GameStateManager gameStateManager;
	//MainMenuState * mainMenuState = new MainMenuState;
	//gameStateManager.AddState("MainMenu", mainMenuState);
	gameStateManager.AddGameState("MainMenu", new MainMenuState());
	gameStateManager.SwitchTo("MainMenu");






	while (window.isOpen())
	{
		sf::Event event;

		// handle input
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//gameStateManager.HandleInput();
		




		


		// update
		//gameStateManager.Update();





		// draw
		//gameStateManager.Draw();
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}