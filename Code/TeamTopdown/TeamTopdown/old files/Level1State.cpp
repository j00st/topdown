#include "stdafx.h"
#include "Level1State.hpp"
#include <iostream>


Level1State::Level1State(sf::RenderWindow & window, GameStateManager & gsm, ControlsInput & ci, Camera & cm, Cursor & c, Player & p) :
	window(window),
	gsm(gsm),
	controlsInput(ci),
	camera(cm),
	cursor(c),
	player(p)
	//map(Map("sprites/map1.png", "sprites/map1s.png", "sprites/map1c.png", player))
	//entityController(player, cursor, controlsInput, map)
{
	map = new Map("sprites/map1.png", "sprites/map1s.png", "sprites/map1c.png", player);
	entityController = new EntityController(player, cursor, controlsInput, map);
	//metal1.openFromFile("audio/music/metal1.ogg");
	std::vector<std::string> buttonList;
	setup = false;
	buttonList.push_back("Resume Game");
	buttonList.push_back("Restart Game");
	buttonList.push_back("Return To Main Menu");
	buttonList.push_back("Exit Game");
	pauseMenu = new Menu(window, Vector2f(camera.GetView().getCenter().x, 80), 
		sf::Vector2f(200, 35), buttonList, camera, false, true, 10, true);
}

void Level1State::HandleInput()
{
	if (controlsInput.num2KeyPressed) { // force switch to main menu
		//gsm.SetNext("MainMenu");
		map = new Map("sprites/map1.png", "sprites/map1s.png", "sprites/map1c.png", player);
		entityController = new EntityController(player, cursor, controlsInput, map);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) { // toggle pause menu
		if (pauseMenu->IsVisible()) {
			player.stats.pauseMenuOpen = 0;
			pauseMenu->Hide();
		}
		else {
			player.stats.pauseMenuOpen = 1;
			pauseMenu->Show();
		}
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
		gsm.RefreshGameState("Level1", new Level1State(window, gsm, controlsInput, camera, cursor, player));
		gsm.SetNext("Level1");
		transitionFromThis();
		player.stats.Reset();
		break;
	}
	case 3: { // Return To Main Menu
		std::cout << "third button pressed" << std::endl;
		player.stats.Reset();
		gsm.SetNext("MainMenu");
		transitionFromThis();
		break;
	}
	case 4: { // Quit Game
		std::cout << "fourth button pressed" << std::endl;
		window.close();
		break;
	}
	} // end switch
	// check player collission with a level switch block
	if (int nextLevel = entityController->exiting()) {
		gsm.SetNext("Level" + std::to_string(nextLevel));
		transitionFromThis();
	}
}

void Level1State::Update()
{
	if (!setup) { // if not yet setup
		player.position = map->getSpawnPoint();
		transitionToThis();
		setup = true;
	}
	else {
		camera.setTimer(entityController->shakeTimer);
		entityController->update();
		camera.update();
		pauseMenu->Update();
		gsm.SwitchState();
	}
}

void Level1State::Draw(sf::RenderWindow & window)
{
	if (!setup) { // if not yet setup
		tRight.setPosition(Vector2f(0, 0));
		tRight.draw(window);
	}
	else {
		window.setMouseCursorVisible(false);
		window.clear(Color::Color(22, 23, 25));
		entityController->draw(window);
		pauseMenu->Draw(window);
	}
	window.display();
}

void Level1State::transitionToThis()
{
	// first frame update
	entityController->update();
	entityController->draw(window);
	camera.update();
	pauseMenu->Draw(window);

	// actual transition
	int count = 0;
	//tRight.setPosition(Vector2f(0, 0));
	Vector2f offset = Vector2f(352, 180);
	while (1 && count < 60) {
		window.clear(Color::Color(22, 23, 25));
		entityController->draw(window);
		pauseMenu->Draw(window);
		tRight.setPosition(camera.getPosition() - offset + Vector2f(0 - count * 11.4, 0));
		//tRight.setPosition(Vector2f(0 - (count * 11.4), 0));
		tRight.draw(window);
		window.display();
		count += 1;
	}
	tRight.setPosition(Vector2f((342 * 2)*-1, 0));
}

void Level1State::transitionFromThis()
{
	int count = 0;
	tLeft.setPosition(Vector2f(342 * 2, 0));
	while (1 && count < 60) {
		window.clear(Color::Color(22, 23, 25));
		entityController->draw(window);
		pauseMenu->Draw(window);
		Vector2f offset(342, -180);
		tLeft.setPosition(camera.getPosition() + offset - Vector2f(count*11.4, 0));
		tLeft.draw(window);
		window.display();
		count += 1;
	}
	tLeft.setPosition(Vector2f(342 * 2, 0));
}