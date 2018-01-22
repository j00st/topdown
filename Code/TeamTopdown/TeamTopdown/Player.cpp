#include "stdafx.h"
#include "Player.h"


Player::Player(Vector2f position, Vector2f size, Cursor &c, ControlsInput& controlsInput, bool isSolid):
	Entity(position, size, isSolid), cursor(c), controlsInput(controlsInput)
{
	hitbox = RectangleShape(size);
	hitbox.setFillColor(Color::Green);
}

void Player::update()
{
	playerSprite.setPosition(position);
	rotate();
}

void Player::rotate()
{
	rotation = atan2(cursor.getPos().y - position.y, cursor.getPos().x - position.x);
	rotation = rotation * (float(180.0) / float(3.141592653589793238463)); // transform radian to degree
	playerSprite.rotate(rotation);
}

void Player::draw(RenderWindow &window)
{
	//hitbox.setPosition(position - Vector2f(size.x/2, size.y/2));
	//window.draw(hitbox);
	playerSprite.draw(window);
}

Vector2f Player::getPos()
{
	return position;
}