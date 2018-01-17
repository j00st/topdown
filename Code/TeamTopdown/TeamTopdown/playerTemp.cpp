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
	//TEST CODE:
	if (GetAsyncKeyState(87)) {
		position.y -= 5;
	}
	if (GetAsyncKeyState(83)) {
		position.y += 5;
	}
	if (GetAsyncKeyState(65)) {
		position.x -= 5;
	}
	if (GetAsyncKeyState(68)) {
		position.x += 5;
	}
	//
	playerShape.setPosition(position);
}

void PlayerTemp::draw(RenderWindow & w)
{
	w.draw(playerShape);
}
