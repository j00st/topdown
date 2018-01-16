#ifndef controlsController_HEADER
#define controlsController_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>

/*! \brief controlsHandler
brief description of controlsHandler*/
class controlsHandler
{
private:
public:
	controlsHandler();
	bool getKey(int key);
};

struct controlsInput
{
	controlsInput();
	bool wKeyPressed = false;
	bool aKeyPressed = false;
	bool sKeyPressed = false;
	bool dKeyPressed = false;
};

class controlsController
{
private:
	controlsHandler& ctrlsHndlr = controlsHandler();
	controlsInput& ctrlsInpt;
public:
	controlsController(controlsInput& inpt);
	void update();
};

#endif