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

	button1 = new MenuButton(window, Vector2f(10, 10), Vector2f(50, 50), std::to_string(window.getSize().x) + ", " + std::to_string(window.getSize().y));
	button2 = new MenuButton(window, Vector2f(10, 20), Vector2f(50, 50), "Exit Game");
	std::string buttonList[] = { "but1", "but2" };
	menu1 = new Menu(window, Vector2f(50, 50), Vector2f(75, 75), buttonList, true);
	view.getCenter();
	view.getSize();
}

void MainMenuState::HandleInput()
{
	if (controlsInput.num1KeyPressed) {
		gsm.SetNext("Level1State");
	}
	button1->HandleInput();
}

void MainMenuState::Update()
{
	gsm.SwitchState(); // switches state if a new state has been set.
}

void MainMenuState::Draw(sf::RenderWindow & window)
{
	window.setView(view);
	window.clear(sf::Color::Red);
	background.draw(window);
	window.draw(text1);
	button1->Draw(window);
	window.display();
}