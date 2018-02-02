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
	alpha = 0;
	redness.setFillColor(Color(255, 0, 0, alpha));
	redness.setSize(camera.GetView().getSize());
	redness.setOrigin(sf::Vector2f(
		redness.getSize().x / 2.0f, 
		redness.getSize().y / 2.0f));
	redness.setPosition(camera.GetView().getCenter());

	// set up text on death
	font1.loadFromFile("sprites/C64_Pro_Mono-STYLE.ttf");

	text1.setString("YOU ARE DEAD");
	text1.setFont(font1);
	text1.setCharacterSize(300);
	text1.setScale(Vector2f(0.15, 0.15));
	text1.setFillColor(sf::Color::White);
	text1.setStyle(sf::Text::Bold);
	text1.setOrigin(
		text1.getLocalBounds().left + text1.getLocalBounds().width / 2.0f,
		text1.getLocalBounds().top + text1.getLocalBounds().height / 2.0f);
	text1.setPosition(Vector2f(camera.GetView().getCenter().x, camera.GetView().getCenter().y - camera.GetView().getSize().y / 4.0f));

	text2.setString("[ press space to restart ]");
	text2.setFont(font1);
	text2.setCharacterSize(75);
	text2.setScale(Vector2f(0.15, 0.15));
	text2.setFillColor(sf::Color::White);
	text2.setStyle(sf::Text::Bold);
	text2.setOrigin(
		text2.getLocalBounds().left + text2.getLocalBounds().width / 2.0f,
		text2.getLocalBounds().top + text2.getLocalBounds().height / 2.0f);
	text2.setPosition(Vector2f(camera.GetView().getCenter().x, camera.GetView().getCenter().y + camera.GetView().getSize().y / 4.0f));

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
	
	// DEBUG FUNCTIONS
	
	// 0 key triggers death
	if (controlsInput.num0KeyPressed) {
		player.TriggerDeath();
	}
	// 9 key triggers life
	if (controlsInput.num9KeyPressed) {
		player.TriggerLife();
		alpha = 0;
		redness.setFillColor(Color(255, 0, 0, alpha));
	}
	
	// END DEBUG FUNCTIONS
	

	// toggle pause menu by pressing P
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		if (pauseMenu->IsVisible() && pause.done) {
			player.stats.pauseMenuOpen = 0;
			pauseMenu->Hide();
			pause.reset();
		}
		else if (pause.done) {
			player.stats.pauseMenuOpen = 1;
			pauseMenu->Show();
			pause.reset();
		}
	}
	// revive if dead with space key
	if (player.stats.isDead) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			transitionFromThis();
			levelManager.RestartCurrentLevel();
			pauseMenu->Hide();
			alpha = 0;
			redness.setFillColor(Color(255, 0, 0, alpha));
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
		levelManager.RestartCurrentLevel();
		alpha = 0;
		redness.setFillColor(Color(255, 0, 0, alpha));
		pauseMenu->Hide();
		break;
	}
	case 3: { // Return To Main Menu
		std::cout << "third button pressed" << std::endl;
		gsm.SetNext("MainMenu");
		transitionFromThis();
		levelManager.Reset();
		player.stats.Reset();
		player.TriggerLife();
		alpha = 0;
		redness.setFillColor(Color(255, 0, 0, alpha));
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
	pause.update();
	// Handling death: update fade out to red, update text position
	redness.setPosition(camera.GetView().getCenter());
	text1.setPosition(Vector2f(
		camera.GetView().getCenter().x,
		camera.GetView().getCenter().y - camera.GetView().getSize().y / 4.0f)); 
	text2.setPosition(Vector2f(
		camera.GetView().getCenter().x, 
		camera.GetView().getCenter().y + camera.GetView().getSize().y / 4.0f));
	
	if (player.stats.isDead) {
		if (alpha < 150) {
			redness.setFillColor(Color(255, 0, 0, alpha));
			alpha++;
		}
	}

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
		window.draw(redness);
		window.draw(text1);
		window.draw(text2);
	}
	window.display();
}

void PlayingState::transitionToThis()
{
	// first frame update
	levelManager.Update();
	levelManager.Draw(window);
	camera.update();

	// actual transition
	int count = 0;
	//tRight.setPosition(Vector2f(0, 0));
	Vector2f offset = Vector2f(342, 180);
	while (1 && count < 60) {
		window.clear(Color::Color(22, 23, 25));
		levelManager.Draw(window);
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
	//tLeft.setPosition(Vector2f(342 * 2, 0));
	Vector2f offset(342, -180);
	offset = offset - Vector2f(32, 0);
	while (1 && count < 60) {
		window.clear(Color::Color(22, 23, 25));
		levelManager.Draw(window);
		pauseMenu->Draw(window);
		setup = false;
		tLeft.setPosition(camera.getPosition() + offset - Vector2f(count*11.4, 0));
		tLeft.draw(window);
		window.display();
		count += 1;
	}
	tLeft.setPosition(camera.getPosition() + offset);
}

void PlayingState::DeathTransition()
{
	
}

void PlayingState::Reset() {
	pauseMenu->Hide();
}