#ifndef CLICKABLEBUTTON_HPP
#define CLICKABLEBUTTON_HPP

#include "stdafx.h"
//#include <SFML/Graphics.hpp>
#include "GameLoopObject.hpp"

/// A clickable button with text, animation and auto-resize to text width.
//
/// A clickable button. Has an idle,'on-hover' and pressed state and changes 
/// sprites accordingly. Can be auto-resized to text length if desired. The 
/// pressed state can be read by calling the IsPressed() method.
class ClickableButton : public GameLoopObject {
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
	/// To create a button, it needs a window (to read mouseposition), a position,
	/// a desired size (length and width), a text to draw on the button and,
	/// optionally, either a true or a false if the button should be resized
	/// automatically to text length (false by default). If this is set to true,
	/// the x value of size is ignored and calculated by the button itself.
	/// if the optional bool autoCalcWidth is set to true, the x value of the
	/// input vector size is ignored and is calculated based on the text length.
	ClickableButton(sf::RenderWindow & window, sf::Vector2f position, 
		sf::Vector2f size, std::string text, bool autoCalcWidth = 0);
	/// The method to handle user input (currently only mouse input).
	//
	/// This method reads if the mouse is hovering over a button, if a button is
	/// pressed + being held, if pressing is canceled (moving the mouse away
	/// from the button while holding and then releasing), and if a button is
	/// successfully pressed. Textures are then updated accordingly.
	void HandleInput();
	/// The button's update method.
	//
	/// Does nothing, as everything else is handled in the HandleInput method.
	void Update();
	/// The button's draw method.
	//
	/// First draws the button's sprite, then draws the button's text on top.
	void Draw(sf::RenderWindow & window);
	/// The button's reset method.
	//
	/// Not yet implemented.
	void Reset();
	/// This method recalculates the button's width based on the button's text.
	//
	/// 'nuff said.
	void AutoCalcWidth(std::string str);
	/// The AutoCalcWidth method if the button is part of a menu.
	//
	/// This method does the same as AutoCalcWidth, but is used when the button
	/// is part of a menu. A menu is drawn based on its origin's x-value, while
	/// a regular button is drawn from the top left corner instead of origin.
	/// This means the button's position also has to be recalculated if it is
	/// part of a menu. This method is only called in the menu class, never in
	/// the button's class itself.
	void AutoCalcWidthMenu(std::string str);
	/// Returns the width of the button as an int.
	//
	/// 'nuff said.
	int GetWidth();
	/// Checks if the button is pressed and returns a bool accordingly.
	//
	/// If the button is pressed, it is first reset to its unpressed state, then
	/// 'true' is returned. Else, false is returned.
	bool IsPressed();
	/// Repositions the button's origin to the center of the screen.
	//
	/// Method used by the menu class to reposition the origins of buttons to
	/// the center of the screen when making a pause menu.
	void RepositionToCenter(sf::Vector2f screenOrigin, int height);
};

#endif // CLICKABLEBUTTON_HPP