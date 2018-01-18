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
		cursor.update();
		camera.update();
		EC.update();

		//draw
		//background.draw(Vector2f(0, 0));
//		mousePos = Vector2f(Mouse::getPosition(window));
//		mousePos.x = mousePos.x - 10;
//		mousePos.y = mousePos.y - 10;
//		mouseObject.setPosition(mousePos);

		//draw
		window.clear();
		window.draw(mouseObject);
		EC.draw(window);
		window.display();
	}

	return 0;
}