#include "stdafx.h"
#include "MainMenuState.hpp"
#include <iostream>


MainMenuState::MainMenuState(sf::RenderWindow & window, GameStateManager & gsm, ControlsInput & ci,
	Camera & cm, Cursor & cr, Player & plr) :
	window(window),
	gsm(gsm),
	controlsInput(ci),
	camera(cm),
	cursor(cr),
	player(plr)
{
	view.setSize(Vector2f(640, 360));
	view.setCenter(Vector2f(320, 180));
	font1.loadFromFile("Lato-Black.ttf");
	text1.setString("made by: michel baartman, bart commandeur, ruben rajan, dylan rakiman, joost van lingen\n");
	text1.setFont(font1);
	text1.setCharacterSize(50);
	text1.setScale(Vector2f(0.15, 0.15));
	text1.setFillColor(sf::Color::White);
	text1.setStyle(sf::Text::Bold);
	text1.setPosition(Vector2f(120, 312));

	// main menu
	std::vector<std::string> buttonList1;
	buttonList1.push_back("Start New Game");
	buttonList1.push_back("Level Select");
	buttonList1.push_back("High Scores");
	buttonList1.push_back("Credits");
	buttonList1.push_back("Exit Game");
	menu1 = new Menu(window, Vector2f(view.getSize().x - 90, view.getSize().y - 170), 
		sf::Vector2f(200, 25), buttonList1, camera, true, true);
	
	// level select menu
	std::vector<std::string> buttonList2;
	buttonList2.push_back("Level 1");
	buttonList2.push_back("Level 2");
	buttonList2.push_back("Level 3");
	buttonList2.push_back("Back");
	menu2 = new Menu(window, Vector2f(view.getSize().x - 90, view.getSize().y - 170), 
		sf::Vector2f(menu1->GetButtonWidth(), 25), buttonList2, camera, false, false);

	background.setScale(Vector2f(1.0, 1.0));
}

void MainMenuState::HandleInput()
{
	if (controlsInput.backspaceKeyPressed) {
		gsm.SetNext("TitleScreen");
	}
	// debug
	//if (controlsInput.num1KeyPressed) {
	//	gsm.SetNext("Level1State");
	//}
	//if (controlsInput.num6KeyPressed) {
	//	menu1->Hide();
	//}
	//if (controlsInput.num7KeyPressed) {
	//	menu1->Show();
	//}

	// handle all menu1 stuff
	if (menu1->IsVisible()) { // main menu
		menu1->HandleInput();
		int i = menu1->FindButtonPress();
		switch (i) {
		case 0: // nothing pressed
			break;
		case 1: { // Start New Game
			std::cout << "MM first button pressed" << std::endl;
			player.stats.Reset();
			gsm.RefreshGameState("Level1State", new Level1State(window, gsm, controlsInput, camera, cursor, player));
			gsm.SetNext("Level1State");
			transitionFromThis();
			break;
		}
		case 2: { // Level Select
			std::cout << "MM second button pressed" << std::endl;
			menu1->Hide();
			menu2->Show();
			break;
		}
		case 3: { // High Scores
			std::cout << "MM third button pressed" << std::endl;
			gsm.SetNext("Highscores");
			break;
		}
		case 4: { // Credits
			std::cout << "MM fourth button pressed" << std::endl;
			gsm.SetNext("Credits");
			break;
		}
		case 5: { // Exit Game
			std::cout << "MM fifth button pressed" << std::endl;
			window.close();
			break;
		}
		} // end switch
	}

	// handle all menu2 stuff
	if (menu2->IsVisible()) { // level select menu
		menu2->HandleInput();
		int j = menu2->FindButtonPress();
		switch (j) {
		case 0: // nothing pressed
			break;
		case 1: { // Level 1
			std::cout << "LS first button pressed" << std::endl;
			player.stats.Reset();
			gsm.RefreshGameState("Level1State", new Level1State(window, gsm, controlsInput, camera, cursor, player));
			gsm.SetNext("Level1State");
			break;
		}
		case 2: { // Level 2
			std::cout << "LS second button pressed" << std::endl;
			player.stats.Reset();
			gsm.RefreshGameState("Level2State", new Level2State(window, gsm, controlsInput, camera, cursor, player));
			gsm.SetNext("Level2State");
			break;
		}
		case 3: { // Level 3
			/*
			* VERWIJDER DIT ALS DIT LEVEL IS GEIMPLEMENTEERD
			*/
			break;
			/*
			* VERWIJDER DIT ALS DIT LEVEL IS GEIMPLEMENTEERD
			*/
			std::cout << "LS third button pressed" << std::endl;
			player.stats.Reset();
			//gsm.RefreshGameState("Level3State", new Level3State(window, gsm, controlsInput, camera, cursor, player));
			gsm.SetNext("Level3State");
			break;
		}
		case 4: { // Back
			std::cout << "LS fourth button pressed" << std::endl;
			menu2->Hide();
			menu1->Show();
			break;
		}
		} // end switch
	}
}

void MainMenuState::Update()
{
	if (menu1->IsVisible()) menu1->Update();
	if (menu2->IsVisible()) menu2->Update();
	gsm.SwitchState(); // switches state if a new state has been set.
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

void MainMenuState::transitionFromThis()
{
	//Draw(window);
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

		tLeft.setPosition(offset - Vector2f(count*11.4, 0)); //- Vector2f(count*11.4, 0));
		tLeft.draw(window);
		window.display();
		count += 1;
	}
	tLeft.setPosition(Vector2f(342 * 2, 0));
}