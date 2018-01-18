#include "stdafx.h"
#include "MainMenuState.hpp"
#include <iostream>


MainMenuState::MainMenuState(sf::RenderWindow & w) : window(w)
{
	
	font1.loadFromFile("Lato-Black.ttf");
	text1.setString("SUP PEEPS DIS IS MAIN MENU");
	text1.setFont(font1);
	text1.setCharacterSize(30);
	text1.setFillColor(sf::Color::Green);
	text1.setStyle(sf::Text::Bold);
	
}

void MainMenuState::HandleInput()
{

}

void MainMenuState::Update()
{
	
}

void MainMenuState::Draw()
{
	window.clear(sf::Color::Red);
	window.draw(text1);
	std::cout << "mainmenustate draw() exec ||| ";
	window.display();
}