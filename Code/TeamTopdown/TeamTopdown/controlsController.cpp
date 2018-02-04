#include "stdafx.h"
#include "ControlsController.h"
ControlsHandler::ControlsHandler() {}

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
{}

void ControlsController::update()
{
	ctrlsInpt.wKeyPressed = ctrlsHndlr.getKey(83); // W key
	ctrlsInpt.aKeyPressed = ctrlsHndlr.getKey(65); // A key
	ctrlsInpt.sKeyPressed = ctrlsHndlr.getKey(87); // S key
	ctrlsInpt.dKeyPressed = ctrlsHndlr.getKey(68); // D key
	ctrlsInpt.pKeyPressed = ctrlsHndlr.getKey(80); // P key
	ctrlsInpt.num1KeyPressed = ctrlsHndlr.getKey(49); // num1 key
	ctrlsInpt.num2KeyPressed = ctrlsHndlr.getKey(50); // num2 key
	ctrlsInpt.num3KeyPressed = ctrlsHndlr.getKey(51); // num3 key
	ctrlsInpt.num4KeyPressed = ctrlsHndlr.getKey(52); // num4 key
	ctrlsInpt.num5KeyPressed = ctrlsHndlr.getKey(53); // num5 key
	ctrlsInpt.num6KeyPressed = ctrlsHndlr.getKey(54); // num6 key
	ctrlsInpt.num7KeyPressed = ctrlsHndlr.getKey(55); // num7 key
	ctrlsInpt.num8KeyPressed = ctrlsHndlr.getKey(56); // num8 key
	ctrlsInpt.num9KeyPressed = ctrlsHndlr.getKey(57); // num9 key
	ctrlsInpt.num0KeyPressed = ctrlsHndlr.getKey(48); // num0 key
	ctrlsInpt.minusKeyPressed = ctrlsHndlr.getKey(189); // - _ key
	ctrlsInpt.plusKeyPressed = ctrlsHndlr.getKey(187); // + = key
	ctrlsInpt.shiftKeyPressed = ctrlsHndlr.getKey(16); // SHIFT key
	ctrlsInpt.spaceKeyPressed = ctrlsHndlr.getKey(32); // SPACE key
	ctrlsInpt.enterKeyPressed = ctrlsHndlr.getKey(13); // ENTER key
	ctrlsInpt.backspaceKeyPressed = ctrlsHndlr.getKey(8); // Backspace key
	ctrlsInpt.rKeyPressed = ctrlsHndlr.getKey(0x52); // ENTER key
	ctrlsInpt.lmbKeyPressed = GetAsyncKeyState(VK_LBUTTON); // LEFT mousebutton
	ctrlsInpt.rmbKeyPressed = GetAsyncKeyState(VK_RBUTTON); // RIGHT mousebutton
}