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
	// toggle pause menu by pressing the Escape button
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
		pauseMenu->Hide();
		break;
	}
	case 2: { // Restart Level
		transitionFromThis();
		levelManager.RestartCurrentLevel();
		alpha = 0;
		redness.setFillColor(Color(255, 0, 0, alpha));
		pauseMenu->Hide();
		break;
	}
	case 3: { // Return To Main Menu
		transitionFromThis();
		gsm.SetNext("MainMenu");
		player.stats.Reset();
		player.hud.resetTime();
		player.TriggerLife();
		alpha = 0;
		redness.setFillColor(Color(255, 0, 0, alpha));
		pauseMenu->Hide();
		levelManager.Reset();
		gsm.SwitchState();
		break;
	}
	case 4: { // Quit Game
		window.close();
		break;
	}
	} // end switch
}

void PlayingState::Update()
{ 
	// check player colission with a level switch block
	if (int nextLevel = levelManager.GetExitingBlock()) {
		transitionFromThis();
		if (nextLevel == 5) { // end game
			gsm.SetNext("MainMenu");
			player.stats.Reset();
			player.hud.resetTime();
			gsm.SwitchState();
		}
		else levelManager.SwitchToLevel(nextLevel);
	}

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
		gsm.SwitchState(); // switch state if a new state is selected
		camera.setTimer(levelManager.GetShakeTimer());
		//camera.setTimer(entityController->shakeTimer); // removed feature
		levelManager.Update();
		camera.update();
		pauseMenu->Update();
		
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
	//tLeft.setPosition(Vector2f(342 * 2, 0));
	Vector2f offset(342, -180);
	offset = offset - Vector2f(32, 0);
	while (1 && count < 60) {
		window.clear(Color::Color(22, 23, 25));
		levelManager.Draw(window);
		//entityController->draw(window);
		pauseMenu->Draw(window);
		setup = false;
		tLeft.setPosition(camera.getPosition() + offset - Vector2f(count*11.4, 0));
		tLeft.draw(window);
		window.display();
		count += 1;
	}
	tLeft.setPosition(camera.getPosition() + offset);
}