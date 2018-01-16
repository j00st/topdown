#ifndef controlsController_HEADER
#define controlsController_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "controlsInput.h"
#include <SFML/Graphics.hpp>

using namespace sf;

/*! \brief controlsHandler
brief description of controlsHandler*/
class controlsHandler
{
private:
public:
	controlsHandler();
	bool getKey(int key);
};

class controlsController
{
private:
	controlsHandler& ctrlsHndlr = controlsHandler();
	controlsInput& ctrlsInpt;
	Window& wndw;
public:
	controlsController(controlsInput& inpt, Window& w);
	void update();
};

#endif