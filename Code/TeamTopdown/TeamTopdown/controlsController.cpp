#include "stdafx.h"
#include "controlsController.h"
controlsHandler::controlsHandler()
{
}

bool controlsHandler::getKey(int key) 
{
	if (GetAsyncKeyState(key)) 
	{
		return true;
	}
	else {
		return false;
	}
}

controlsController::controlsController(controlsInput& inpt, Window& w) :
	ctrlsInpt(inpt), wndw(w)
{
}

void controlsController::update()
{
	ctrlsInpt.mousePos = Vector2i(Mouse::getPosition(wndw)); // Mouse Position
	ctrlsInpt.wKeyPressed = ctrlsHndlr.getKey(83); // UP key
	ctrlsInpt.aKeyPressed = ctrlsHndlr.getKey(65); // LEFT key
	ctrlsInpt.sKeyPressed = ctrlsHndlr.getKey(87); // DOWN key
	ctrlsInpt.dKeyPressed = ctrlsHndlr.getKey(68); // RIGHT key
}