#include "stdafx.h"
#include "Menu.hpp"
#include <iostream>

Menu::Menu(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f buttonSize, std::vector<std::string> buttonNames, Camera & camera, bool isVisible, bool autoCalcWidth, int offset, bool updateToCenter) :
	window(window),
	position(position),
	isVisible(isVisible),
	inputHeight(position.y),
	offset(offset),
	buttonSize(buttonSize),
	camera(camera),
	updateToCenter(updateToCenter)
{
	// store new buttons in list of buttons
	for (int i = 0; i < buttonNames.size(); i++)
	{
		listOfButtons.push_back(new ClickableButton(window, sf::Vector2f(position.x - buttonSize.x / 2.0f, position.y + i * offset + buttonSize.y * i), buttonSize, buttonNames[i])); // autoCalcWidth));
		if(maxString.length() < buttonNames[i].length()) maxString = buttonNames[i];
	}
	if (autoCalcWidth) {
		for (auto button : listOfButtons) {
			button->AutoCalcWidthMenu(maxString);
		}
	}
	// set variables for getters
	amountOfButtons = listOfButtons.size(); 
	buttonWidth = listOfButtons[0]->GetWidth();
}

void Menu::HandleInput()
{
	if (isVisible) {
		for (auto button : listOfButtons) {
			button->HandleInput();
		}
	}
}

void Menu::Update()
{
	if (isVisible) {
		for (auto button : listOfButtons) {
			button->Update();
		}
	}
	if (updateToCenter) {
		RepositionToCenter();
	}
}

void Menu::Draw(sf::RenderWindow & w)
{
	if (isVisible) {
		for (auto button : listOfButtons) {
			button->Draw(w);
		}
	}
}

void Menu::Reset()
{
	for (auto button : listOfButtons){
		button->Reset();
	}
}

void Menu::Show()
{
	isVisible = 1;
}

void Menu::Hide()
{
	isVisible = 0;
}

int Menu::GetAmountOfButtons()
{
	return amountOfButtons;
}

int Menu::GetButtonWidth()
{
	return buttonWidth;
}
int Menu::FindButtonPress()
{
	int pressedButton = 0;
	int pressedButtonIterator = 0;
	for (auto button : listOfButtons) {
		pressedButtonIterator++;
		if (button->IsPressed()) {
			pressedButton = pressedButtonIterator;
		}
	}
	pressedButtonIterator = 0;
	return pressedButton;
}

bool Menu::IsVisible()
{
	return isVisible;
}

void Menu::RepositionToCenter()
{
	sf::Vector2f screenOrigin = camera.GetView().getCenter();
	int heightCorrection = camera.GetView().getSize().y / 2.0f;
	int i = 0;
	for (auto button : listOfButtons) {
		button->RepositionToCenter(
			screenOrigin, 
			inputHeight + i * offset + buttonSize.y * i - heightCorrection);
		i++;
	}
}