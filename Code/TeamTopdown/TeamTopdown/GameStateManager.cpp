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
	//check if name exists in list of gamestates
	if (gameStates.count(name))
	{
		std::cout << "name found in list, setting nextState to " + name +"\n";
		nextState = gameStates[name];
	}
}

void GameStateManager::SwitchState()
{
	if (nextState != nullptr)
	{
		currentState = nextState;
		nextState = nullptr;
		std::cout << "switchState() successfully called\n";
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
