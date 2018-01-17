#ifndef Entity_HEADER
#define Entity_HEADER

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>

using namespace sf;

class drawable
{
public:
	virtual void draw(RenderWindow & w) = 0;
};

/** \class entityController
* \brief Entity class
* This class represents any 'physical' entity in the game.
* Meaning it contains information about its position, size and whether it's solid or not.
* The class contains functions to get, set or change the position.
*/

class Entity :
	public drawable
{
protected:
	Vector2f position;
	Vector2f size;
public:
	bool isSolid;

	Entity(Vector2f position, Vector2f size, bool isSolid);

	void move(Vector2f delta);
	bool collidesWith(Entity &other, Vector2f delta);
	virtual void update() = 0;
};

#endif
