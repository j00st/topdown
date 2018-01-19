#include "stdafx.h"
#include "Cursor.h"

Cursor::Cursor(ControlsInput& controlsInput) :
	controlsInput(controlsInput)
{
	cursorTexture.loadFromFile("Sprites/Crosshair.png");
	cursorSprite.setTexture(cursorTexture);
	cursorSprite.setOrigin(Vector2f(16, 16)); // set center point of cursor sprite
	cursorSprite.setPosition(controlsInput.mousePos);
}

void Cursor::update()
{
	cursorSprite.setPosition(controlsInput.mousePos);
}

void Cursor::draw(RenderWindow& w)
{
	w.draw(cursorSprite);
}