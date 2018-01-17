// TeamTopdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "player.h"
#include "controlsController.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	// window setup
	RenderWindow window(VideoMode(1200, 800), "SFML works!");
	window.setFramerateLimit(60); //60 fps cinematic experience

	// object setup
	ControlsInput ctrlsInpt;
	ControlsController cntrlsCntrl(ctrlsInpt, window);

	window.setMouseCursorVisible(false);
	Sprite cursor;
	Texture cursorTexture;
	cursorTexture.loadFromFile("sprites/crosshair.png");
	cursor.setTexture(cursorTexture);

	Player player(ctrlsInpt, Vector2f(20, 20));

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

		//controls controller
		cntrlsCntrl.update();
		std::cout << ctrlsInpt.aKeyPressed << ctrlsInpt.wKeyPressed <<
			ctrlsInpt.sKeyPressed << ctrlsInpt.dKeyPressed << "__" << 
			ctrlsInpt.mousePos.x << "." << ctrlsInpt.mousePos.y << "\n";

		player.update();
		cursor.setPosition(static_cast<Vector2f>(Mouse::getPosition(window) - Vector2i(32, 32)));

		//draw
		window.clear(Color::Green);
		window.draw(cursor);
		player.draw(window);
		window.display();
	}

	return 0;
}