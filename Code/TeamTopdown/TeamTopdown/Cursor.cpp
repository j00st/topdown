#include "stdafx.h"
#include "Cursor.h"

Cursor::Cursor(sf::Vector2f position, sf::Vector2f size, ControlsInput& controlsInput, bool isSolid) :
	Entity(position, size, isSolid), controlsInput(controlsInput)
{
	cursorTexture.loadFromFile("Sprites/Crosshair.png");
	cursorSprite.setTexture(cursorTexture);
	cursorSprite.setOrigin(sf::Vector2f(16, 16)); // set center point of cursor sprite
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

sf::Vector2f Cursor::getPos()
{
	return position;
}