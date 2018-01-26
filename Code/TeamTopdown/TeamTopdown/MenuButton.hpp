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
	
	int detectCounter = 1;
	int hoverCheckBool = 0;
	int mouseHoldBool = 0;
	bool isPressed = 0;
public:
	/// Constructor
	//
	/// if the optional bool autoCalcWidth is set to true, the x value of the
	/// input vector size is ignored and is calculated based on the text length.
	MenuButton(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, std::string text, bool autoCalcWidth = 0);
	void HandleInput();
	void Update();
	void Draw(sf::RenderWindow & window);
	bool IsPressed();
};

#endif // MENUBUTTON_HPP