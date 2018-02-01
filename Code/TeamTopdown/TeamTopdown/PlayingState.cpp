#include "stdafx.h"
#include "PlayingState.hpp"
#include <iostream>


PlayingState::PlayingState(sf::RenderWindow & window, GameStateManager & gsm, 
	ControlsInput & ci, LevelManager & lm, Camera & cm, Cursor & c, Player & p) :
	window(window),
	gsm(gsm),
	controlsInput(ci),
	levelManager(lm),
	camera(cm),
	cursor(c),
	player(p)
{
	// set up text on death
	font1.loadFromFile("Lato-Black.ttf");
	text1.setString("You are dead.\nPress Space to restart.");
	text1.setFont(font1);
	text1.setCharacterSize(50);
	text1.setScale(Vector2f(0.15, 0.15));
	text1.setFillColor(sf::Color::White);
	text1.setStyle(sf::Text::Bold);
	///
	/// THIS IS A FIXED POSITION. FIX THIS TO CENTER OF SCREEN
	/// AND ADD IT TO UPDATE().
	///
	text1.setPosition(Vector2f(120, 312));

	// create pause menu
	std::vector<std::string> buttonList;
	setup = false;
	buttonList.push_back("Resume Game");
	buttonList.push_back("Restart Level");
	buttonList.push_back("Return To Main Menu");
	buttonList.push_back("Exit Game");
	pauseMenu = new Menu(window, Vector2f(camera.GetView().getCenter().x, 80),
		sf::Vector2f(200, 35), buttonList, camera, false, true, 10, true);
}

void PlayingState::HandleInput()
{
	// toggle pause menu by pressing P
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		if (pauseMenu->IsVisible()) {
			player.stats.pauseMenuOpen = 0;
			pauseMenu->Hide();
		}
		else {
			player.stats.pauseMenuOpen = 1;
			pauseMenu->Show();
		}
	}
	// revive if dead
	if (player.stats.isDead) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			transitionFromThis();
			levelManager.Reset();
			levelManager.SwitchToLevel(levelManager.GetCurrentLevel());
			player.stats.Reset();
			pauseMenu->Hide();
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
	case 2: { // Restart Level
		std::cout << "second button pressed" << std::endl;
		// get current level and restart lvl state
		//gsm.RefreshGameState("Level1", new PlayingState(window, gsm, controlsInput, levelManager, camera, cursor, player));
		//gsm.SetNext("Level1");
		transitionFromThis();
		levelManager.Reset();
		levelManager.SwitchToLevel(levelManager.GetCurrentLevel());
		player.stats.Reset();
		pauseMenu->Hide();
		break;
	}
	case 3: { // Return To Main Menu
		std::cout << "third button pressed" << std::endl;
		transitionFromThis();
		gsm.SetNext("MainMenu");
		levelManager.Reset();
		pauseMenu->Hide();
		break;
	}
	case 4: { // Quit Game
		std::cout << "fourth button pressed" << std::endl;
		window.close();
		break;
	}
	} // end switch

	// check player collission with a level switch block
	if (int nextLevel = levelManager.GetExitingBlock()) {
		//entityController->exiting()) {
		//gsm.SetNext("Level" + std::to_string(nextLevel));
		transitionFromThis();
		levelManager.SwitchToLevel(nextLevel);
	}
}

void PlayingState::Update()
{
	// update the first frame to correctly transition into this level
	if (!setup) { // if game is not set up yet
		player.position = levelManager.GetSpawnPoint();
		//player.position = map->getSpawnPoint();
		transitionToThis();
		setup = true;
	}
	else {
		camera.setTimer(levelManager.GetShakeTimer());
		//camera.setTimer(entityController->shakeTimer);
		levelManager.Update();
		//entityController->update();
		camera.update();
		pauseMenu->Update();
		gsm.SwitchState();
	}
}

void PlayingState::Draw(sf::RenderWindow & window)
{
	if (!setup) { // if not yet setup
		tRight.setPosition(Vector2f(0, 0));
		tRight.draw(window);
	}
	else {
		window.setMouseCursorVisible(false);
		window.clear(Color::Color(22, 23, 25));
		levelManager.Draw(window);
		//entityController->draw(window);
		pauseMenu->Draw(window);
	}
	if (player.stats.isDead) {
		window.draw(text1);
	}
	window.display();
}

void PlayingState::transitionToThis()
{
	// first frame update
	levelManager.Update();
	levelManager.Draw(window);
	//entityController->update();
	//entityController->draw(window);
	camera.update();
	pauseMenu->Draw(window);

	// actual transition
	int count = 0;
	//tRight.setPosition(Vector2f(0, 0));
	Vector2f offset = Vector2f(352, 180);
	while (1 && count < 60) {
		window.clear(Color::Color(22, 23, 25));
		levelManager.Draw(window);
		//entityController->draw(window);
		pauseMenu->Draw(window);
		tRight.setPosition(camera.getPosition() - offset + Vector2f(0 - count * 11.4, 0));
		//tRight.setPosition(Vector2f(0 - (count * 11.4), 0));
		tRight.draw(window);
		window.display();
		count += 1;
	}
	tRight.setPosition(Vector2f((342 * 2)*-1, 0));
}

void PlayingState::transitionFromThis()
{
	int count = 0;
	tLeft.setPosition(Vector2f(342 * 2, 0));
	while (1 && count < 60) {
		window.clear(Color::Color(22, 23, 25));
		levelManager.Draw(window);
		//entityController->draw(window);
		pauseMenu->Draw(window);
		Vector2f offset(342, -180);
		tLeft.setPosition(camera.getPosition() + offset - Vector2f(count*11.4, 0));
		tLeft.draw(window);
		window.display();
		count += 1;
	}
	tLeft.setPosition(Vector2f(342 * 2, 0));
}

void PlayingState::Reset() {
	pauseMenu->Hide();
}