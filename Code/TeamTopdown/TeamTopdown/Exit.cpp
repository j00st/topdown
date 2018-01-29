#include "stdafx.h"
#include "Exit.h"


Exit::Exit(Vector2f position, int exitNr, Vector2f size, bool isSolid):
	Entity(position, size, isSolid, exitNr)
{}
