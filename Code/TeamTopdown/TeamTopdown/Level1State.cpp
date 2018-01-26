#include "stdafx.h"
#include "Level1State.hpp"
#include <iostream>

Level1State::Level1State(sf::RenderWindow & window, GameStateManager & gsm, ControlsInput & ci, EntityController & ec, Camera & cm) :
	window(window),
	gsm(gsm),
	controlsInput(ci),
	entityCtrl(ec),
	camera(cm)
{
	std::vector<std::string> buttonList;
	buttonList.push_back("Resume Game");
	buttonList.push_back("Restart Level");
	buttonList.push_back("Return To Main Menu");
	buttonList.push_back("Exit Game");
	pauseMenu = new Menu(window, Vector2f(camera.view.getCenter().x, 50), sf::Vector2f(50, 50), buttonList, true);

	pauseMenu;
}

void Level1State::HandleInput()
{
	if (controlsInput.num2KeyPressed) {
		gsm.SetNext("MainMenu");
	}
	if (controlsInput.pKeyPressed) {
		if(pauseMenu->IsVisible()) pauseMenu->Hide(); 
		else pauseMenu->Show();
	}
	pauseMenu->HandleInput();

}

void Level1State::Update()
{
	gsm.SwitchState();
	camera.update();
	entityCtrl.update();
	// update pause menu position to center of screen
	pauseMenu->Update();
}

void Level1State::Draw(sf::RenderWindow & window)
{
	window.clear(Color::Color(22, 23, 25));
	entityCtrl.draw(window);
	pauseMenu->Draw(window);
	window.display();
}