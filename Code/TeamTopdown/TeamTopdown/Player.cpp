#include "stdafx.h"
#include "Player.h"


Player::Player(Vector2f position, Vector2f size, Cursor &c, ControlsInput& controlsInput, bool isSolid, int state):
	Entity(position, size, isSolid, state), cursor(c), controlsInput(controlsInput)
{
	hitbox = RectangleShape(size);
	hitbox.setFillColor(Color::Green);
}

void Player::HandleInput()
{

}

void Player::update()
{
	if (state == states::alive) {
		playerSprite.setPosition(position);
		rotate();
	}
}

void Player::rotate()
{
	if (!stats.isDead)
	{
		rotation = atan2(cursor.getPos().y - position.y, cursor.getPos().x - position.x);
		rotation = rotation * (float(180.0) / float(3.141592653589793238463)); // transform radian to degree
	}
	playerSprite.rotate(rotation);
}

void Player::draw(RenderWindow &window)
{
	//hitbox.setPosition(position - Vector2f(size.x/2, size.y/2));
	//window.draw(hitbox);
	playerSprite.draw(window);
	hud.draw(window);
}

Vector2f Player::getPos()
{
	return position;
}

void Player::TriggerDeath()
{
	stats.isDead = 1;
	playerSprite.SetSprite("sprites/character_dead.png", true);
}

void Player::TriggerLife()
{
	stats.isDead = 0;
	playerSprite.SetSprite("sprites/character.png", true);
}

bool Player::collidesWith(Entity* other) {
	Vector2f delta = other->position - position;
	return (size.x / 2.0f > sqrt(delta.x * delta.x + delta.y * delta.y));
}