#pragma once
#include "Entity.h"

/*! \class Exit
\brief Invisible wall which handles 'exiting' a level.
The wall contains a number representing the level to advance to.
It uses standard AABB-collision detection to determine if our player collides.
The exit number is saved in the state and read by EC to determine where to exit to.*/

class Exit :
	public Entity
{
public:
	Exit(Vector2f position, int exitNr, Vector2f size = Vector2f(32.0f, 32.0f), bool isSolid = false);
};

