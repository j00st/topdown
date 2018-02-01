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
	/*! /constructor ControlsHandler
	/brief creates a COntrolsHandler */
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
	/*! /constructor ControlsController
	/brief makes a controller that controls controls. requires a ControlsInput and window object to record and save keyboard inputs. */
	ControlsController(ControlsInput& inpt, Window& w); 
	/*! /void update()
	/brief updates controlsInput based on handler data. */
	void update();
};

#endif