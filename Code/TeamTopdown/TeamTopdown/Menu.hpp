#ifndef MENU_HPP
#define MENU_HPP

#include "stdafx.h"
#include "GameLoopObject.hpp"
#include "ClickableButton.hpp"
#include <vector>

/// A modular menu of buttons.
//
/// asdfasdfasdf
class Menu : public GameLoopObject {
private:
	sf::RenderWindow & window;
	sf::Vector2f position;
	std::vector<ClickableButton *> listOfButtons;
	std::string maxString = "";
	int amountOfButtons;
	int buttonWidth;
	bool isVisible;
public:
	/// Constructor
	//
	/// To create a menu, you first have to create a std::vector of std::strings
	/// in which you store all your button names (aka the text displayed on the
	/// buttons). Then, call the menu's constructor, in which you pass the 
	/// window, a position (x value of desired origin, y value of menu top) and
	/// the desired size of the buttons.
	//
	/// Optionally, you can set if the menu is visible or hidden (visible (true)
	/// by default), if the button size should be auto-calculated (takes the
	/// longest button text and resizes all buttons to match the width), and if
	/// there should be a vertical offset between each button (0 by default).
	Menu(sf::RenderWindow & window, sf::Vector2f position, 
		sf::Vector2f buttonSize, std::vector<std::string> buttonNames, 
		bool isVisible = 1, bool autoCalcWidth = 0, int offset = 0);
	/// The menu's user input handling method.
	//
	/// Runs the HandleInput methods of all buttons in the menu if the menu is
	/// visible. Else this does nothing.
	void HandleInput();
	/// The menu's update method.
	//
	/// Runs the update methods of all buttons in the menu if the menu is
	/// visible. Else this does nothing.
	void Update();
	/// The menu's draw method.
	//
	/// Runs the draw methods of all buttons if the menu is set to visible. Else
	/// this does nothing.
	void Draw(sf::RenderWindow & window);
	/// The menu's reset method.
	//
	/// Runs the reset methods of all buttons. The button's reset method is not
	/// implemented yet.
	void Reset();
	/// Toggles visibility of the menu to visible.
	//
	/// Sets the bool isVisible to 1. Does nothing else.
	void Show();
	/// Toggles visibility of the menu to hidden.
	//
	/// Sets the bool isVisible to -1. Does nothing else.
	void Hide();
	/// Returns an int with the amount of buttons the instance of a menu has.
	//
	/// Returns the amountOfButtons it. Does nothing else.
	int GetAmountOfButtons();
	/// Returns the width of the buttons in the menu as an int.
	//
	/// 'nuff said.
	int GetButtonWidth();
	/// Checks all buttons for a button press and returns which one was pressed.
	//
	/// Runs the IsPressed method of all buttons and returns an int with the
	/// number of the button that was pressed. Counts from 1 to end. If 0 is
	/// returned, no button was pressed.
	int FindButtonPress();
	/// Checks if the menu is currently visible and returns true or false.
	//
	/// Returns the bool isVisible. Does nothing else.
	bool IsVisible();
};
#endif // MENU_HPP