#include "stdafx.h"
#include "Player.h"


Player::Player(Vector2f position, Vector2f size, Cursor &c, ControlsInput& controlsInput, bool isSolid, int state):
	Entity(position, size, isSolid, state), cursor(c), controlsInput(controlsInput)
{
	SBplayerDeath.loadFromFile("audio/soundeffects/PlayerDeath.wav");
	SEplayerDeath.setBuffer(SBplayerDeath);
}

void Player::update()
{
	if (state == states::alive) {
		playerSprite.setPosition(position + Vector2f(8.0, 8.0));
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
	playerSprite.draw(window);
}

Entity* Player::hit() {
	TriggerDeath();
	return nullptr;
}
Vector2f Player::getPos()
{
	return position + Vector2f(8.0f, 8.0f);
}

void Player::TriggerDeath()
{
	stats.isDead = 1;
	playerSprite.SetSprite("sprites/character_dead.png", true);
	SEplayerDeath.play();
}

void Player::TriggerLife()
{
	stats.isDead = 0;
	playerSprite.SetSprite("sprites/character.png", true);
}

bool Player::collidesWith(Entity* other) {
	Vector2f delta = other->position - getPos();
	return size.x / 2 > sqrt((int) delta.x * delta.x + delta.y * delta.y);
}

void Player::setSprite(std::string path)
{
	playerSprite.SetSprite(path, true);
}