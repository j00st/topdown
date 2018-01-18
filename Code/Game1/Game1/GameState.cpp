
#include "stdafx.h"
#include "GameState.hpp"

/*
 * GameState base class.
 */
GameState::GameState()
{

}

// implement input handling for stuff dat should always be handled in every state (like ESC = exit game)
void GameState::HandleInput()
{
	// while there's events to handle

}

void GameState::Update()
{

}

void GameState::Draw()
{

}

void GameState::Reset()
{

}

GameState::~GameState()
{

}