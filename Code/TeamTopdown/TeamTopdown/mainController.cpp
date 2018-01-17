// TeamTopdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "player.h"
#include "controlsInput.h"
#include "controlsController.h"
#include "Cursor.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	// window setup
	RenderWindow window(VideoMode(1200, 800), "SFML works!");
	window.setFramerateLimit(60); //60 fps cinematic experience
	window.setMouseCursorVisible(false);

	// object setup
	ControlsInput controlsInput;
	ControlsController controlsController(controlsInput, window);
	Cursor cursor(controlsInput);
	Player player(Vector2f(64, 64), controlsInput);

	// main loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//update
		controlsController.update();
		cursor.update();
		player.update();


		//draw
		window.clear();
		cursor.draw(window);
		player.draw(window);
		window.display();
	}

	return 0;
}