#include "stdafx.h"
#include "playerTemp.h"


PlayerTemp::PlayerTemp(Vector2f position, Vector2f size, bool isSolid):
	Entity( position, size, isSolid )
{
	playerShape = RectangleShape(size);
	playerShape.setFillColor(Color::Green);
}

void PlayerTemp::update()
{
	playerShape.setPosition(position);
}

void PlayerTemp::draw(RenderWindow & w)
{
	w.draw(playerShape);
}
