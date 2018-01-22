// TeamTopdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
	RenderWindow window(VideoMode(1200, 800), "SFML works!", Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	window.setMouseCursorVisible(false);
	window.setFramerateLimit(60); //60 fps cinematic experience

	// object setup
	ControlsInput controlsInput;
	ControlsController controlsController(controlsInput, window);
	Cursor cursor(Vector2f(100, 100), Vector2f(16,16), controlsInput, 0);
	Player player(Vector2f(64.0f, 64.0f), Vector2f(32.0f, 32.0f), cursor, controlsInput);

	// camera setup
	View view;
	view.setSize(Vector2f(1280, 720));
	Camera camera(view, player, window, Vector2f(1920, 1080));
	Mouse::setPosition(Vector2i(640, 360));
	auto EC = EntityController(player, cursor, controlsInput);

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
		camera.update();
		EC.update();

		//draw
		window.clear();
		EC.draw(window);
		window.display();
	}

	return 0;
}