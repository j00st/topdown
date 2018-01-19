#include "stdafx.h"
#include "GameStateManager.hpp"
#include <iostream>

GameStateManager::GameStateManager()
{

}

void GameStateManager::AddGameState(std::string name, GameState & state)
{
	gameStates.insert(std::make_pair(name,  state));
}

void GameStateManager::SetNext(std::string name)
{
	//check if user wants to exit (close window with X)
	if (gameStates.count(name))
	{
		//nextState = gameStates[name];
		nextState = gameStates[name];
	}
}

void GameStateManager::SwitchState()
{
	//if (currentState != nextState)
	//{
		currentState = nextState;
	//}
	
}

void GameStateManager::HandleInput()
{
	// if(currentState != null)
	//gameStates[currentState].HandleInput();
	currentState.HandleInput();
}

void GameStateManager::Update()
{
	// if(currentState != null)
	//currentState.Update();
	//gameStates[currentState].Update();
	currentState.Update();
}

void GameStateManager::Draw()
{
	// if(currentState != null)
	////currentState.Draw();
	//for (auto it = gameStates.cbegin(); it != gameStates.cend(); it++)
	//{
	//	std::cout << it->first << " " << it->second.Print() << "\n";
	//}
	currentState.Draw();
	//gameStates["MainMenu"].Draw();
	std::cout << "gsm draw() exec ||| ";
}

void GameStateManager::Reset()
{
	// if(currentState != null)
	currentState.Reset();
	//gameStates[currentState].Reset();
}
