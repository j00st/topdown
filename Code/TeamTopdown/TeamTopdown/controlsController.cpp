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
	ctrlsInpt.mousePos = Vector2f(Mouse::getPosition(wndw) - Vector2i(100, 100)); // Mouse Position
	Mouse::setPosition(Vector2i(100, 100)); // Put mouse back at 100,100 to prevent it from hitting the window edge
	ctrlsInpt.wKeyPressed = ctrlsHndlr.getKey(83); // UP key
	ctrlsInpt.aKeyPressed = ctrlsHndlr.getKey(65); // LEFT key
	ctrlsInpt.sKeyPressed = ctrlsHndlr.getKey(87); // DOWN key
	ctrlsInpt.dKeyPressed = ctrlsHndlr.getKey(68); // RIGHT key
	ctrlsInpt.num1KeyPressed = ctrlsHndlr.getKey(49); // num1 key //97
	ctrlsInpt.num2KeyPressed = ctrlsHndlr.getKey(50); // num2 key //98
	ctrlsInpt.shiftKeyPressed = ctrlsHndlr.getKey(16); // SHIFT key
	ctrlsInpt.spaceKeyPressed = ctrlsHndlr.getKey(32); // SPACE key
}