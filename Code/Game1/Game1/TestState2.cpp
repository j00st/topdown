#include "stdafx.h"
#include "TestState2.hpp"
#include <iostream>


TestState2::TestState2(sf::RenderWindow & w) : window(w)
{
	font1.loadFromFile("Lato-Black.ttf");
	text1.setString("TestState2");
	text1.setFont(font1);
	text1.setCharacterSize(30);
	text1.setFillColor(sf::Color::Yellow);
	text1.setStyle(sf::Text::Bold);

}

void TestState2::HandleInput()
{

}

void TestState2::Update()
{

}

void TestState2::Draw()
{
	window.clear(sf::Color::Blue);
	window.draw(text1);
	window.display();
}