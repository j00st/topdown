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
	gameStates[name] = state;
}

void GameStateManager::SetNext(std::string name)
{
	//check if user wants to exit (close window with X)
	if (gameStates.count(name))
	{
		nextState = gameStates[name];
	}
}

void GameStateManager::SwitchState()
{
	//if (currentState != nextState)
	//{
		currentState = nextState;
		nextState = nullptr;

	//}
	
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

void GameStateManager::Draw()
{
	// if(currentState != null)
	currentState->Draw();
}

void GameStateManager::Reset()
{
	// if(currentState != null)
	currentState->Reset();
}
