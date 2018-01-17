// TeamTopdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "player.h"
#include "Camera.h"
#include <SFML/Graphics.hpp>
#include "Graphic.h"
#include "controlsInput.h"
#include "controlsController.h"

using namespace sf;

int main()
{
	// window setup
	RenderWindow window(VideoMode(1200, 800), "SFML works!", Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60); //60 fps cinematic experience

	// object setup
	ControlsInput ctrlsInpt;
	ControlsController cntrlsCntrl(ctrlsInpt, window);

	Graphic background(window, "sprites/map1.png");

	Player player(Vector2f(20, 20));

	// camera setup
	View view;
	view.setSize(Vector2f(1280, 720)); //view.setCenter(Vector2f(1280, 720));
	Camera camera(view, player, window, Vector2f(1920, 1080));

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
		cntrlsCntrl.update(); // updates ctrlsInpt
		std::cout << ctrlsInpt.aKeyPressed << ctrlsInpt.wKeyPressed <<
			ctrlsInpt.sKeyPressed << ctrlsInpt.dKeyPressed << "__x" <<
			ctrlsInpt.mousePos.x << ".y" << ctrlsInpt.mousePos.y << "\n"; // test prompt to visualise current ctrlsInpt

		player.update();
		camera.update();

		//draw
		window.clear();
		background.draw(Vector2f(0, 0));
		player.draw(window);
		window.display();
	}

	return 0;
}