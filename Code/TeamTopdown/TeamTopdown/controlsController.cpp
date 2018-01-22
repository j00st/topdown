#include "stdafx.h"
#include "ControlsController.h"
ControlsHandler::ControlsHandler()
{
}

bool ControlsHandler::getKey(int key) 
{
	if (GetAsyncKeyState(key)) 
	{
		return true;
	}
	else {
		return false;
	}
}

ControlsController::ControlsController(ControlsInput& inpt, Window& w) :
	ctrlsInpt(inpt), wndw(w)
{
}

void ControlsController::update()
{
	ctrlsInpt.mousePos = Vector2f(Mouse::getPosition(wndw)); // Mouse Position
	ctrlsInpt.wKeyPressed = ctrlsHndlr.getKey(83); // UP key
	ctrlsInpt.aKeyPressed = ctrlsHndlr.getKey(65); // LEFT key
	ctrlsInpt.sKeyPressed = ctrlsHndlr.getKey(87); // DOWN key
	ctrlsInpt.dKeyPressed = ctrlsHndlr.getKey(68); // RIGHT key
	ctrlsInpt.num1KeyPressed = ctrlsHndlr.getKey(49); // num1 key //97
	ctrlsInpt.num2KeyPressed = ctrlsHndlr.getKey(50); // num2 key //98
}