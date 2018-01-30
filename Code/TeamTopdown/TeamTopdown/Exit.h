#pragma once
#include "Entity.h"
class Exit :
	public Entity
{
public:
	Exit(Vector2f position, int exitNr, Vector2f size = Vector2f(32.0f, 32.0f), bool isSolid = false);
};

