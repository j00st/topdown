#include "stdafx.h"
#include "MainMenuState.hpp"


MainMenuState::MainMenuState(sf::RenderWindow & w) :
	window(w)
{
	
}

void MainMenuState::HandleInput()
{

}

void MainMenuState::Update()
{

}

void MainMenuState::Draw()
{
	window.clear();
	//window.draw(shape);
	window.display();
}



