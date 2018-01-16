#include "stdafx.h"
#include "Player.h"


Player::Player(controlsInput& inpt, Vector2f size):
	ctrlsInpt(inpt)
{
	playerShape = RectangleShape(size);
	playerX = 0;
	playerY = 0;
	playerShape.setPosition(Vector2f(playerX, playerY));
	playerShape.setFillColor(Color::Green);
}

void Player::update()
{
	if (ctrlsInpt.sKeyPressed) {
		playerY -= 10;
	}
	if (ctrlsInpt.wKeyPressed) {
		playerY += 10;
	}
	if (ctrlsInpt.aKeyPressed) {
		playerX -= 10;
	}
	if (ctrlsInpt.dKeyPressed) {
		playerX += 10;
	}
	if (state == false) { playerY += 5; state = true; }
	else { playerY -= 5; state = false; };
	playerShape.setPosition(Vector2f(playerX, playerY));
}

void Player::draw( RenderWindow & w ) 
{
	w.draw(playerShape);
}