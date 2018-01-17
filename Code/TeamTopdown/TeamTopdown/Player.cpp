#include "stdafx.h"
#include "Player.h"


Player::Player(Vector2f size, ControlsInput& controlsInput) :
	size(size), controlsInput(controlsInput)
{
	playerTexture.loadFromFile("player_idle.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(Vector2f(0,0));
	playerSprite.setOrigin(Vector2f(size.x / 4, size.x / 2)); // set center point for rotation
}

void Player::update()
{
	if (GetAsyncKeyState(87)) {
		playerPos.y -= 10;
	}
	if (GetAsyncKeyState(83)) {
		playerPos.y += 10;
	}
	if (GetAsyncKeyState(65)) {
		playerPos.x -= 10;
	}
	if (GetAsyncKeyState(68)) {
		playerPos.x += 10;
	}
	playerSprite.setPosition(playerPos);
}

void Player::rotate()
{
	rotation = atan2(controlsInput.mousePos.y - playerPos.y, controlsInput.mousePos.x - playerPos.x);
	rotation = rotation * (float(180.0) / float(3.141592653589793238463)); // transform radian to degree
	playerSprite.setRotation(rotation);
}

void Player::draw( RenderWindow & w ) 
{
	rotate();
	w.draw(playerSprite);
}

Vector2f Player::getPos()
{
	return playerPos;
}