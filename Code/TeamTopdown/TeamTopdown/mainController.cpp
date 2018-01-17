// TeamTopdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "player.h"
#include "Camera.h"
#include "Cursor.h"
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
	window.setMouseCursorVisible(false);
	window.setFramerateLimit(60); //60 fps cinematic experience

	// object setup
	ControlsInput controlsInput;
	ControlsController controlsController(controlsInput, window);
	Cursor cursor(controlsInput);

	Player player(Vector2f(64, 64), window, controlsInput);

	Graphic background(window, "sprites/map1.png");

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
		controlsController.update(); // updates controlsInput
		std::cout << controlsInput.aKeyPressed << controlsInput.wKeyPressed <<
			controlsInput.sKeyPressed << controlsInput.dKeyPressed << "__x" <<
			controlsInput.mousePos.x << ".y" << controlsInput.mousePos.y << "\n"; // test prompt to visualise current controlsInput

		player.update();
		cursor.update();
		camera.update();

		//draw
		window.clear();
		background.draw(Vector2f(0, 0));
		player.draw();
		window.display();
	}

	return 0;
}