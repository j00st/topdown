#ifndef ControlsController_HEADER
#define ControlsController_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "ControlsInput.h"
#include <SFML/Graphics.hpp>

using namespace sf;

/*! \class controlsHandler
\brief handles retrieving the data from hardware inputs*/
class ControlsHandler
{
private:
public:
	ControlsHandler();
	bool getKey(int key); /*!< gets keyboard int key state */
};

/*! \class controlsController
\brief updates data from controlsHandler to controlsInput*/
class ControlsController
{
private:
	ControlsHandler& ctrlsHndlr = ControlsHandler();
	ControlsInput& ctrlsInpt;
	Window& wndw;
public:
	ControlsController(ControlsInput& inpt, Window& w); 
	void update(); /*!< updates controlsinput based on handler data */
};

#endif