#ifndef MENUBUTTON_HPP
#define MENUBUTTON_HPP

#include "stdafx.h"
//#include <SFML/Graphics.hpp>
#include "GameLoopObject.hpp"

class MenuButton : public GameLoopObject {
private:
	sf::RenderWindow & window;
	sf::Texture rect1texture1;
	sf::Texture rect1texture2;
	sf::Texture rect1texture3;
	sf::RectangleShape rect1;
	sf::Font font1;
	sf::Text rect1text;
	sf::FloatRect textRect;
	
	int detectCounter = 1;
	int hoverCheckBool = 0;
	int mouseHoldBool = 0;
	bool pressed = 0;
public:
	MenuButton(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, std::string text);
	void HandleInput();
	void Update();
	void Draw(sf::RenderWindow & window);
	bool OnPress();
};

#endif // MENUBUTTON_HPP