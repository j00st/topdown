#ifndef Entity_HEADER
#define Entity_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>

using namespace sf;

/** \class entityController
* \brief Entity class
* This class represents any entity in the game.
* It contains information about its position, size and whether it's solid or not.
* It also has a function to change the position, a pure virtual update function
* and a function to determine collision via axis-aligned bounding boxes.
*/

class Entity
{
protected:
	Vector2f size;
public:
	Vector2f position;
	bool isSolid;
	bool hostile;

	Entity(Vector2f position, Vector2f size, bool isSolid, bool hostile);
	///move our entity by adding the parameter vector to our position.
	void move(Vector2f delta);
	///Return whether or not this entity will collide with another when moved to a new position.
	virtual bool collidesWith(Entity* other, Vector2f delta);
	virtual void update() = 0;
	virtual void draw(RenderWindow &w) = 0;
};

#endif
