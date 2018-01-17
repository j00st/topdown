#include "stdafx.h"
#include "Player.h"


Player::Player(Vector2f size, RenderWindow& w, ControlsInput& controlsInput) :
	size(size), window(w), controlsInput(controlsInput)
{
	hitbox = RectangleShape(size);
	hitbox.setFillColor(Color::Green);
}

void Player::update()
{
	if (controlsInput.wKeyPressed) { playerPos.y += speed; }
	if (controlsInput.sKeyPressed) { playerPos.y -= speed; }
	if (controlsInput.aKeyPressed) { playerPos.x -= speed; }
	if (controlsInput.dKeyPressed) { playerPos.x += speed; }
}

void Player::rotate()
{
	rotation = atan2(controlsInput.mousePos.y - playerPos.y, controlsInput.mousePos.x - playerPos.x);
	rotation = rotation * (float(180.0) / float(3.141592653589793238463)); // transform radian to degree
	graphic.rotate(rotation);
}

void Player::draw() 
{
	rotate();
	hitbox.setPosition(playerPos - Vector2f(size.x/2, size.y/2));
	window.draw(hitbox);
	graphic.draw(playerPos);
}

Vector2f Player::getPos()
{
	return playerPos;
}