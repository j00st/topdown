#include "stdafx.h"
#include "Cursor.h"

Cursor::Cursor(sf::RenderWindow & window, Vector2f position, Vector2f size, ControlsInput& controlsInput, bool isSolid) :
	Entity(position, size, isSolid, hostile), controlsInput(controlsInput), window(window)
{
	cursorTexture.loadFromFile("Sprites/Crosshair.png");
	cursorSprite.setTexture(cursorTexture);
	cursorSprite.setOrigin(Vector2f(16, 16));
	cursorSprite.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
}

void Cursor::update()
{
	cursorSprite.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
}

void Cursor::draw(RenderWindow& w)
{
	w.draw(cursorSprite);
}

Vector2f Cursor::getPos()
{
	return window.mapPixelToCoords(sf::Mouse::getPosition(window));
}