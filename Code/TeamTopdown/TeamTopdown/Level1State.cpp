#include "stdafx.h"
#include "Level1State.hpp"
#include <iostream>


Level1State::Level1State(sf::RenderWindow & window, GameStateManager & gsm, ControlsInput & ci, Camera & cm, Cursor & c, Player & p) :
	window(window),
	gsm(gsm),
	controlsInput(ci),
	camera(cm),
	cursor(c),
	player(p),
	map(Map("sprites/map0.png", "sprites/map0s.png", "sprites/map0c.png", player)),
	entityController(player, cursor, controlsInput, map)
{
	std::vector<std::string> buttonList;
	buttonList.push_back("Resume Game");
	buttonList.push_back("Restart Game");
	buttonList.push_back("Return To Main Menu");
	buttonList.push_back("Exit Game");
	pauseMenu = new Menu(window, Vector2f(camera.getView().getCenter().x, 35), 
		//window.getViewport(window.getView()).left + window.getViewport(window.getView()).width / 2.0f,
		//window.getViewport(window.getView()).top + 35),
		sf::Vector2f(200, 35), buttonList, false, true, 10);

	//camera.view.getCenter().x, 35), 
}

void Level1State::HandleInput()
{
	if (controlsInput.num2KeyPressed) {
		gsm.SetNext("MainMenu");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		if (pauseMenu->IsVisible()) pauseMenu->Hide();
		else pauseMenu->Show();
	}
	// pause menu handle each button
	pauseMenu->HandleInput();
	int i = pauseMenu->FindButtonPress();
	switch (i) {
	case 0: // nothing pressed
		break;
	case 1: { // Resume Game
		std::cout << "first button pressed" << std::endl;
		pauseMenu->Hide();
		break;
	}
	case 2: { // Restart Game
		std::cout << "second button pressed" << std::endl;
		pauseMenu->Hide();
		// Reset level
		break;
	}
	case 3: { // Return To Main Menu
		std::cout << "third button pressed" << std::endl;
		// reset alles
		pauseMenu->Hide();
		gsm.SetNext("MainMenu");
		break;
	}
	case 4: { // Quit Game
		std::cout << "fourth button pressed" << std::endl;
		pauseMenu->Hide();
		window.close();
		break;
	}
	} // end switch




	if (int nextLevel = entityController.exiting()) {
		gsm.SetNext("Level" + std::to_string(nextLevel) + "State");
	}
}

void Level1State::Update()
{
	camera.setTimer(entityController.shakeTimer);
	gsm.SwitchState();
	camera.update();
	entityController.update();
	pauseMenu->Update();
}

void Level1State::Draw(sf::RenderWindow & window)
{
	window.clear(Color::Color(22, 23, 25));
	entityController.draw(window);
	pauseMenu->Draw(window);
	window.display();
}