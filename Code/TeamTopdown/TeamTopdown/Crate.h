#pragma once
#include "Entity.h"
class Crate :
	public Entity
{
private:
	RectangleShape body;
public:
	Crate(Vector2f position, Vector2f size, bool isSolid = true);
	void update() override;
	void draw(RenderWindow & w) override;
};

