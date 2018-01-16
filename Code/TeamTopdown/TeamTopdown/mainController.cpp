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

	RectangleShape mouseObject(Vector2f(20,20));
	mouseObject.setFillColor(Color::White);
	Vector2f mousePos;
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
		mousePos = Vector2f(Mouse::getPosition(window));
		mousePos.x = mousePos.x - 10;
		mousePos.y = mousePos.y - 10;
		mouseObject.setPosition(mousePos);

		//controls controller
		cntrlsCntrl.update();
		std::cout << ctrlsInpt.aKeyPressed << ctrlsInpt.wKeyPressed <<
			ctrlsInpt.sKeyPressed << ctrlsInpt.dKeyPressed << "__" << 
			ctrlsInpt.mousePos.x << "." << ctrlsInpt.mousePos.y << "\n";

		player.update();

		//draw
		window.clear();
		window.draw(mouseObject);
		player.draw(window);
		window.display();
	}

	return 0;
}