#include "stdafx.h"
#include "GameStateManager.hpp"
#include <iostream>

GameStateManager::GameStateManager() :
	currentState(nullptr),
	nextState(nullptr)
{

}

void GameStateManager::AddGameState(std::string name, GameState * state)
{
	// check if name exists in list of gamestates. Only one instance of the same
	// key (the 'name' string) can exist in a map, so counting the amount of
	// times that 'name' exists in the map will either return 1 (true) or 0
	// (false).
	// if it exists, do nothing. else add the new state.
	if (gameStates.count(name)) {
	}
	else gameStates[name] = state;
}

void GameStateManager::RefreshGameState(std::string name, GameState * state)
{
	// check if name exists in list of gamestates. Only one instance of the same
	// key (the 'name' string) can exist in a map, so counting the amount of
	// times that 'name' exists in the map will either return 1 (true) or 0
	// (false).
	// if it exists, replace it with the new state. else, do nothing.
	if (gameStates.count(name)) {
		gameStates[name] = state;
	}
}

void GameStateManager::SetNext(std::string name)
{
	// check if name exists in list of gamestates. Only one instance of the same
	// key (the 'name' string) can exist in a map, so counting the amount of
	// times that 'name' exists in the map will either return 1 (true) or 0
	// (false).
	if (gameStates.count(name))
	{
		nextState = gameStates[name];
	}
}

void GameStateManager::SwitchState()
{
	if (nextState != nullptr)
	{
		currentState = nextState;
		nextState = nullptr;
	}
	
}

void GameStateManager::HandleInput()
{
	// if(currentState != null)
	currentState->HandleInput();
}

void GameStateManager::Update()
{
	// if(currentState != null)
	currentState->Update();
}

void GameStateManager::Draw(sf::RenderWindow & window)
{
	// if(currentState != null)
	currentState->Draw(window);
}

void GameStateManager::Reset()
{
	// if(currentState != null)
	currentState->Reset();
}
