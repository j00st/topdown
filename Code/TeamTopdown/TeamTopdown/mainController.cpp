// TeamTopdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PlayerTemp.h"
#include "Crate.h"
#include "EntityController.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	// window setup
	RenderWindow window(VideoMode(1200, 800), "SFML works!");
	window.setFramerateLimit(60); //60 fps cinematic experience

	// object setup
	RectangleShape mouseObject(Vector2f(20,20));
	mouseObject.setFillColor(Color::White);
	Vector2f mousePos;
	auto EC = EntityController();
	/*PlayerTemp player(Vector2f(500.0f, 500.0f), Vector2f(20.0f, 20.0f));
	Crate c1(Vector2f(200.0f, 200.0f), Vector2f(40.0f, 40.0f));*/
	//Crate c2(Vector2f(70.0f, 50.0f), Vector2f(20.0f, 20.0f));

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

		//player.collidesWith(c1);
		//player.collidesWith(c2, 0.5f);
		//c1.collidesWith(c2, 0.5f);

		/*player.update();
		c1.update();*/
		//c2.update();
		EC.update();

		//draw
		window.clear();
		window.draw(mouseObject);
		/*player.draw(window);
		c1.draw(window);*/
		//c2.draw(window);
		EC.draw(window);
		window.display();
	}

	return 0;
}