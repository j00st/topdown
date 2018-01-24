#ifndef WALL_HEADER
#define WALL_HEADER

#include "Entity.h"
#include <SFML/System.hpp>

/*! \class Wall
\brief (invisible) Wall class
This class represents an invisible wall-tile. Its position is a multitude of (32,32) and its size is exactly (32,32).
It cannot update, since our position is always set, and it cannot draw, because it is invisible. 
So we override those functions with empty brackets.
*/

class Wall :
	public Entity
{
public:
	Wall(sf::Vector2f position, sf::Vector2f size);
	void update() override {}
	void draw(sf::RenderWindow & w) override {}
};

#endif