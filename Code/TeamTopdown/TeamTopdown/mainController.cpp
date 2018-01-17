// TeamTopdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "player.h"
#include "Camera.h"
#include <SFML/Graphics.hpp>
#include "controlsInput.h"
#include "controlsController.h"

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
	Player player(Vector2f(20, 20));

	View view;
	view.setCenter(Vector2f(600, 400)); view.setSize(Vector2f(600, 400));
	Camera camera(view, player, window, Vector2f(2000, 1600));

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
		cntrlsCntrl.update(); // updates ctrlsInpt
		std::cout << ctrlsInpt.aKeyPressed << ctrlsInpt.wKeyPressed <<
			ctrlsInpt.sKeyPressed << ctrlsInpt.dKeyPressed << "__x" <<
			ctrlsInpt.mousePos.x << ".y" << ctrlsInpt.mousePos.y << "\n"; // test prompt to visualise current ctrlsInpt

		mousePos = Vector2f(Mouse::getPosition(window));
		mousePos.x = mousePos.x - 10;
		mousePos.y = mousePos.y - 10;
		mouseObject.setPosition(mousePos);
		player.update();
		camera.update();

		//draw
		window.clear();
		window.draw(mouseObject);
		player.draw(window);
		window.display();
	}

	return 0;
}