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
	if (GetAsyncKeyState(VK_UP)) {
		playerY--;
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		playerY++;
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		playerX--;
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		playerX++;
	}
	playerShape.setPosition(Vector2f(playerX, playerY));
}

void Player::draw( RenderWindow & w ) 
{
	w.draw(playerShape);
}