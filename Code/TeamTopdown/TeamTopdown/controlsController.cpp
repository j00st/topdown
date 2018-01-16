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

controlsInput::controlsInput()
{
}

controlsController::controlsController(controlsInput& inpt) :
	ctrlsInpt(inpt)
{
}

void controlsController::update()
{
	ctrlsInpt.wKeyPressed = ctrlsHndlr.getKey(83);
	ctrlsInpt.aKeyPressed = ctrlsHndlr.getKey(65);
	ctrlsInpt.sKeyPressed = ctrlsHndlr.getKey(87);
	ctrlsInpt.dKeyPressed = ctrlsHndlr.getKey(68);
}