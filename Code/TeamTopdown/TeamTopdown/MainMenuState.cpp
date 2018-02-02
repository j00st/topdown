#include "stdafx.h"
#include "MainMenuState.hpp"
#include <iostream>


MainMenuState::MainMenuState(sf::RenderWindow & window, GameStateManager & gsm,
	ControlsInput & ci, LevelManager & lm, Camera & cm, Cursor & cr, Player & plr) :
	window(window),
	gsm(gsm),
	controlsInput(ci),
	levelManager(lm),
	camera(cm),
	cursor(cr),
	player(plr)
{
	// load music
	menuOst.openFromFile("audio/music/menu.wav");

	// scale background, set view, load text
	view.setSize(Vector2f(640, 360));
	view.setCenter(Vector2f(320, 180));
	background.setScale(Vector2f(1.0, 1.0));

	// set up text
	font1.loadFromFile("Lato-Black.ttf");
	text1.setString("made by: michel baartman, bart commandeur, ruben rajan, dylan rakiman, joost van lingen\n");
	text1.setFont(font1);
	text1.setCharacterSize(50);
	text1.setScale(Vector2f(0.15, 0.15));
	text1.setFillColor(sf::Color::White);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(Vector2f(120, 312));

	// create main menu
	std::vector<std::string> buttonList1;
	buttonList1.push_back("Start New Game");
	buttonList1.push_back("Level Select");
	buttonList1.push_back("High Scores");
	buttonList1.push_back("Credits");
	buttonList1.push_back("Exit Game");
	menu1 = new Menu(window, Vector2f(view.getSize().x - 90, view.getSize().y - 170), 
		sf::Vector2f(200, 25), buttonList1, camera, true, true);
	
	// create level select menu
	std::vector<std::string> buttonList2;
	buttonList2.push_back("Level 1");
	buttonList2.push_back("Level 2");
	buttonList2.push_back("Level 3");
	buttonList2.push_back("Level 4");
	buttonList2.push_back("Back");
	menu2 = new Menu(window, Vector2f(view.getSize().x - 90, view.getSize().y - 170), 
		sf::Vector2f(menu1->GetButtonWidth(), 25), buttonList2, camera, false, false);
}

void MainMenuState::HandleInput()
{
	if (controlsInput.backspaceKeyPressed) {
		gsm.SetNext("TitleScreen");
		switchingStates = 1;
	}

	// handle all main menu stuff
	if (menu1->IsVisible()) { // main menu
		menu1->HandleInput();
		switch (menu1->FindButtonPress()) {
		case 0: // nothing pressed
			break;
		case 1: { // Start New Game
			transitionFromThis();
			player.hud.resetTime();
			levelManager.SwitchToLevel(1);
			gsm.SetNext("Playing");
			switchingStates = 1;
			break;
		}
		case 2: { // Level Select
			menu1->Hide();
			menu2->Show();
			break;
		}
		case 3: { // High Scores
			gsm.SetNext("Highscores");
			break;
		}
		case 4: { // Credits
			gsm.SetNext("Credits");
			break;
		}
		case 5: { // Exit Game
			window.close();
			break;
		}
		} // end switch
	}

	// handle all level select menu stuff
	if (menu2->IsVisible()) { // level select menu
		menu2->HandleInput();
		int j = menu2->FindButtonPress();
		switch (j) {
		case 0: // nothing pressed
			break;
		case 1: { // Level 1
			transitionFromThis();
			levelManager.SwitchToLevel(1);
			player.hud.resetTime();
			gsm.SetNext("Playing");
			switchingStates = 1;
			break;
		}
		case 2: { // Level 2
			transitionFromThis();
			levelManager.SwitchToLevel(2);
			player.hud.resetTime();
			gsm.SetNext("Playing");
			switchingStates = 1;
			break;
		}
		case 3: { // Level 3
			transitionFromThis();
			levelManager.SwitchToLevel(3);
			player.hud.resetTime();
			gsm.SetNext("Playing");
			switchingStates = 1;
			break;
		}
		case 4: { // Level 4
			transitionFromThis();
			levelManager.SwitchToLevel(4);
			player.hud.resetTime();
			gsm.SetNext("Playing");
			switchingStates = 1;
		}
		case 5: { // Back
			menu2->Hide();
			menu1->Show();
			break;
		}
		} // end switch
	}
}

void MainMenuState::Update()
{
	if (!switchingStates && menuOst.getStatus() != sf::SoundSource::Status::Playing) {
		menuOst.play();
	}
	if (menu1->IsVisible()) menu1->Update();
	if (menu2->IsVisible()) menu2->Update();
	if (switchingStates) {
		gsm.SwitchState(); // switches state if a new state has been set.
		menuOst.stop();
		Reset();
	}
	
}

void MainMenuState::Draw(sf::RenderWindow & window)
{
	window.setMouseCursorVisible(true);
	window.setView(view);
	window.clear(sf::Color::Red);
	background.draw(window);
	window.draw(text1);
	if (menu1->IsVisible()) menu1->Draw(window);
	if (menu2->IsVisible()) menu2->Draw(window);
	window.display();
}

void MainMenuState::Reset()
{
	menu1->Show();
	menu2->Hide();
	switchingStates = 0;
	menuOst.stop();
}

void MainMenuState::transitionFromThis()
{
	int count = 0;
	//tLeft.setPosition(Vector2f(342 * 2, 0));
	Vector2f offset = Vector2f(342 * 2, 0);

	while (1 && count < 60) {
		//window.clear(Color::Color(22, 23, 25));
		window.setMouseCursorVisible(true);
		window.setView(view);
		window.clear(sf::Color::Red);
		background.draw(window);
		window.draw(text1);
		if (menu1->IsVisible()) menu1->Draw(window);
		if (menu2->IsVisible()) menu2->Draw(window);

		tLeft.setPosition(Vector2f(-44,0) + offset - Vector2f(count *11.4, 0));//offset); //- Vector2f(count*11.4, 0));
		tLeft.draw(window);
		window.display();
		count += 1;
	}
	tLeft.setPosition(Vector2f(-44, 0));
	tLeft.draw(window);
	window.display();
}