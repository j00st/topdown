#include "stdafx.h"
#include "Level2State.h"
#include <iostream>


Level2State::Level2State(sf::RenderWindow & window, GameStateManager & gsm, ControlsInput & ci, Camera & cm, Cursor & c, Player & p) :
	window(window),
	gsm(gsm),
	controlsInput(ci),
	camera(cm),
	cursor(c),
	player(p),
	map(Map("sprites/map2.png", "sprites/map2s.png", "sprites/map2c.png", player)),
	entityController(player, cursor, controlsInput, map)
{
	std::vector<std::string> buttonList;
	setup = false;
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

void Level2State::HandleInput()
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
		transitionFromThis();
	}
}

void Level2State::Update()
{
	if (!setup) {
		player.position = map.getSpawnPoint();
		transitionToThis();
		setup = true;
	}
	else {
		camera.setTimer(entityController.shakeTimer);
		gsm.SwitchState();
		camera.update();
		entityController.update();
		pauseMenu->Update();
	}
}

void Level2State::Draw(sf::RenderWindow & window)
{
	if (!setup) {
		tRight.setPosition(Vector2f(0, 0));
		tRight.draw(window);
	}
	else {
		window.setMouseCursorVisible(false);
		window.clear(Color::Color(22, 23, 25));
		entityController.draw(window);
		pauseMenu->Draw(window);
	}
	window.display();
}

void Level2State::transitionToThis()
{
	// first frame update
	entityController.update();
	entityController.draw(window);
	camera.update();
	pauseMenu->Draw(window);

	// actual transition
	int count = 0;
	//tRight.setPosition(Vector2f(0, 0));
	Vector2f offset = Vector2f(352, 180);
	while (1 && count < 60) {
		window.clear(Color::Color(22, 23, 25));
		entityController.draw(window);
		pauseMenu->Draw(window);
		tRight.setPosition(camera.getPosition() - offset + Vector2f(0 - count * 11.4, 0));
		//tRight.setPosition(Vector2f(0 - (count * 11.4), 0));
		tRight.draw(window);
		window.display();
		count += 1;
	}
	tRight.setPosition(Vector2f((342 * 2)*-1, 0));
}

void Level2State::transitionFromThis()
{
	int count = 0;
	tLeft.setPosition(Vector2f(342 * 2, 0));
	while (1 && count < 60) {
		window.clear(Color::Color(22, 23, 25));
		entityController.draw(window);
		pauseMenu->Draw(window);
		Vector2f offset(342, -180);
		tLeft.setPosition(camera.getPosition() + offset - Vector2f(count*11.4, 0));
		tLeft.draw(window);
		window.display();
		count += 1;
	}
	tLeft.setPosition(Vector2f(342 * 2, 0));
}