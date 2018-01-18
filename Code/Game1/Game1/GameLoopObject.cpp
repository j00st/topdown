
#include "stdafx.h"
#include "GameLoopObject.hpp"

/*
* GameLoopObject base class.
*/
GameLoopObject::GameLoopObject()
{

}

// implement input handling for stuff dat should always be handled in every state (like ESC = exit game)
void GameLoopObject::HandleInput()
{
	// while there's events to handle

}

void GameLoopObject::Update()
{

}

void GameLoopObject::Draw()
{

}

void GameLoopObject::Reset()
{

}

GameLoopObject::~GameLoopObject()
{

}