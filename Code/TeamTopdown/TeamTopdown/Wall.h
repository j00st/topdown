#ifndef WALL_HEADER
#define WALL_HEADER

#include "Entity.h"
class Wall :
	public Entity
{
public:
	Wall(Vector2f position, Vector2f size);
	void update() override {}
	void draw(RenderWindow & w) override {}
};

#endif