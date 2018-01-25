#include "stdafx.h"
#include "Cursor.h"

Cursor::Cursor(Vector2f position, Vector2f size, ControlsInput& controlsInput, bool isSolid, bool hostile) :
	Entity(position, size, isSolid, hostile), controlsInput(controlsInput)
{
	cursorTexture.loadFromFile("Sprites/Crosshair.png");
	cursorSprite.setTexture(cursorTexture);
	cursorSprite.setOrigin(Vector2f(16, 16)); // set center point of cursor sprite
	cursorSprite.setPosition(controlsInput.mousePos);
}

void Cursor::update()
{
	position += controlsInput.mousePos;
	cursorSprite.setPosition(position);
}

void Cursor::draw(RenderWindow& w)
{
	w.draw(cursorSprite);
}

Vector2f Cursor::getPos()
{
	return position;
}