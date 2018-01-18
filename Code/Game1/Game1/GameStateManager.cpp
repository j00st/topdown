#include "stdafx.h"
#include "GameStateManager.hpp"
#include <iostream>

GameStateManager::GameStateManager()
{

}

void GameStateManager::AddGameState(std::string name, GameState * state)
{
	gameStates.insert(std::make_pair(name, * state));
}

void GameStateManager::SetNext(std::string name)
{
	//check if user wants to exit (close window with X)
	if (gameStates.count(name))
	{
		//nextState = gameStates[name];
		nextState = name;
	}
}

void GameStateManager::SwitchState()
{
	if (currentState != nextState)
	{
		currentState = nextState;
	}
	
}

void GameStateManager::HandleInput()
{
	// if(currentState != null)
	gameStates[currentState].HandleInput();
}

void GameStateManager::Update()
{
	// if(currentState != null)
	//currentState.Update();
	gameStates[currentState].Update();
}

void GameStateManager::Draw()
{
	// if(currentState != null)
	//currentState.Draw();
	gameStates[currentState].Draw();
	std::cout << "gsm draw() exec ||| ";
}

void GameStateManager::Reset()
{
	// if(currentState != null)
	//currentState.Reset();
	gameStates[currentState].Reset();
}
