#include "stdafx.h"
#include "Player.h"


Player::Player(Vector2f position, Vector2f size, Cursor &c, ControlsInput& controlsInput, bool isSolid):
	Entity(position, size, isSolid), cursor(c), ci(controlsInput)
{
	hitbox = RectangleShape(size);
	hitbox.setFillColor(Color::Green);
}

void Player::HandleInput()
{

}

float Player::calcSpeed() 
{
	// dodge detection
	if (!stats.dodging) {
		if (ci.spaceKeyPressed && stats.stamina > 40) {
			stats.dodging = true;
			stats.stamina -= 40;
			stats.dodge.reset();
			std::cout << "dodge!\n";
			return stats.speed * 2;
		}
		// sprint detection
		if (ci.shiftKeyPressed && stats.stamina > 0) {
			if (stats.sprint.done) {
				stats.stamina -= 10;
				stats.sprint.reset();
				std::cout << "sprint!\n";
			}
			return stats.speed * 1.5;
		}
		else if (stats.stamina < 100) {
			if (stats.energy.done) {
				stats.stamina += 10;
				stats.energy.reset();
			}
		}
	}
	else {
		if (stats.dodge.done) {
			stats.dodging = false;
		}
		else {
			//std::cout << "dodging!\n";
			return stats.speed * 4;
		}
	}
	if (stats.stamina < 0) { stats.stamina = 0; }
	if (stats.stamina > 100) { stats.stamina = 100; }

	// walk
	return stats.speed;

}

void Player::update()
{
	stats.energy.update();
	stats.sprint.update();
	stats.dodge.update();
	stats.reload.update();

	// 0 key triggers death
	if (ci.num0KeyPressed) {
		TriggerDeath();
	}
	// 9 key triggers life
	if (ci.num9KeyPressed) {
		TriggerLife();
	}

	if (!stats.isDead) {
		playerSprite.setPosition(position);
		rotate();
	}
	else if (stats.isDead) {
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