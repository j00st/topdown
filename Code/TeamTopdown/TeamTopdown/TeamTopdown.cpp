// TeamTopdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "player.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	// window setup
	RenderWindow window(VideoMode(1200, 800), "SFML works!");
	window.setFramerateLimit(60); //60 fps cinematic experience

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	// main loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					std::cout << "the escape key was pressed" << std::endl;
					//std::cout << "control:" << event.key.control << std::endl;
					//std::cout << "alt:" << event.key.alt << std::endl;
					//std::cout << "shift:" << event.key.shift << std::endl;
					//std::cout << "system:" << event.key.system << std::endl;
					window.close();
				}
			}
		}




		//draw
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}