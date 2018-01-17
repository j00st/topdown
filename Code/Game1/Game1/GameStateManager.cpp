
#include "stdafx.h"
#include "GameStateManager.hpp"

GameStateManager::GameStateManager()
{

}

void GameStateManager::AddGameState(std::string name, GameState * state)
{
	gameStates.insert(std::make_pair(name, * state));
}

void GameStateManager::SwitchTo(std::string name)
{
	if (gameStates.count(name))
	{
		currentState = gameStates[name];
	}
	// else throw exception
}

void GameStateManager::HandleInput()
{
	// if(currentState != null)
	currentState.HandleInput();
}

void GameStateManager::Update()
{
	// if(currentState != null)
	currentState.Update();
}

void GameStateManager::Draw()
{
	// if(currentState != null)
	currentState.Draw();
}

void GameStateManager::Reset()
{
	// if(currentState != null)
	currentState.Reset();
}
