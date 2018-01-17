#include "stdafx.h"
#include "Player.h"


Player::Player( Vector2f size )
{
	playerShape = RectangleShape(size);
	playerX = 0;
	playerY = 0;
	playerShape.setPosition(Vector2f(playerX, playerY));
	playerShape.setFillColor(Color::Green);
}

void Player::update()
{
	if (GetAsyncKeyState(87)) {
		playerY -= 10;
	}
	if (GetAsyncKeyState(83)) {
		playerY += 10;
	}
	if (GetAsyncKeyState(65)) {
		playerX -= 10;
	}
	if (GetAsyncKeyState(68)) {
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