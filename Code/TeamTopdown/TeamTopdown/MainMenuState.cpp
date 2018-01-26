#include "stdafx.h"
#include "MainMenuState.hpp"
#include <iostream>


MainMenuState::MainMenuState(sf::RenderWindow & window, GameStateManager & gsm, ControlsInput & ci) :
	window(window), 
	gsm(gsm),
	controlsInput(ci)
{
	view.setSize(Vector2f(640, 360));
	view.setCenter(Vector2f(320, 180));
	font1.loadFromFile("Lato-Black.ttf");
	text1.setString("MAIN MENU STATE\nPress 1 to switch to the game, Press 2 to return to main menu.\n");
	text1.setFont(font1);
	text1.setCharacterSize(100);
	text1.setScale(Vector2f(0.15, 0.15));
	text1.setFillColor(sf::Color::White);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(Vector2f(120, 312));

	std::vector<std::string> buttonList;
	buttonList.push_back("Start New Game");
	buttonList.push_back("Level Select");
	buttonList.push_back("Options");
	buttonList.push_back("Credits");
	buttonList.push_back("Exit Game");
	menu1 = new Menu(window, Vector2f(view.getSize().x - 90, view.getSize().y - 170), sf::Vector2f(200, 25), buttonList, true, true);
	//button1 = new MenuButton(window, Vector2f(0, 0), sf::Vector2f(200, 50), "TESTBUTTON", false); //view.getCenter().x, 50
}

void MainMenuState::HandleInput()
{
	if (controlsInput.num1KeyPressed) {
		gsm.SetNext("Level1State");
	}
	if (controlsInput.num6KeyPressed) {
		menu1->Hide();
	}
	if (controlsInput.num7KeyPressed) {
		menu1->Show();
	}
	menu1->HandleInput();
	//button1->HandleInput();
	
	int i = menu1->FindKeyPress();
	switch (i) {
	case 0: // nothing pressed
		break;
	case 1: { // Start New Game
		std::cout << "first button pressed" << std::endl;
		gsm.SetNext("Level1State");
		break;
	}
	case 2: { // Level Select
		std::cout << "second button pressed" << std::endl;

		break;
	}
	case 3: { // Options
		std::cout << "third button pressed" << std::endl;

		break;
	}
	case 4: { // Credits
		std::cout << "fourth button pressed" << std::endl;
		gsm.SetNext("Credits");
		break;
	}
	case 5: { // Exit Game
		std::cout << "fifth button pressed" << std::endl;
		window.close();
		break;
	}
	} // end switch
}

void MainMenuState::Update()
{
	menu1->Update();
	//button1->Update();
	gsm.SwitchState(); // switches state if a new state has been set.
}

void MainMenuState::Draw(sf::RenderWindow & window)
{
	window.setView(view);
	window.clear(sf::Color::Red);
	background.draw(window);
	window.draw(text1);
	menu1->Draw(window);
	//button1->Draw(window);
	window.display();
}