// TeamTopdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1200, 800), "SFML works!");
	window.setFramerateLimit(60); //60 fps cinematic experience
	//CircleShape shape(100.f);
	RectangleShape mouseObject(Vector2f(20,20));
	//RectangleShape line;
	CircleShape player(10.f);
	player.setFillColor(Color::Green);
	mouseObject.setFillColor(Color::White);
	Vector2f mousePos;
	//Vector2f linePos(20, 20);
	//shape.setFillColor(Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//update
		player.setPosition(Vector2f(600, 400));
		//line.setPosition(linePos);
		mousePos = Vector2f(Mouse::getPosition(window));
		mouseObject.setPosition(mousePos);

		//draw
		window.clear();
		window.draw(player);
		window.draw(mouseObject);
		//window.draw(line)
		window.display();
	}

	return 0;
}