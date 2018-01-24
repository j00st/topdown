#include "stdafx.h"
#include "Player.h"


Player::Player(sf::Vector2f position, sf::Vector2f size, Cursor & c, ControlsInput & ci, EntityController & ec, bool isSolid):
	Entity(position, size, isSolid), 
	cursor(c), 
	controlsInput(ci),
	entityController(ec)
{
	hitbox = sf::RectangleShape(size);
	hitbox.setFillColor(Color::Green);
}

void Player::HandleInput()
{
	// 0 key triggers death
	if (controlsInput.num0KeyPressed) {
		TriggerDeath();
	}
	// 9 key triggers life
	if (controlsInput.num9KeyPressed) {
		TriggerLife();
	}

	// when alive, do this:
	if (!stats.isDead) {

		//-- player firing --//
		playerFire();
		stats.shoot.update();

		//-- player movement --//
		stats.energy.update();
		stats.sprint.update();
		stats.dodge.update();
		stats.reload.update();

		Vector2f upwards = Vector2f(0.0f, calcSpeed());
		Vector2f downwards = Vector2f(0.0f, -calcSpeed());
		Vector2f leftwards = Vector2f(-calcSpeed(), 0.0f);
		Vector2f rightwards = Vector2f(calcSpeed(), 0.0f);

		Vector2f vector(0, 0);
		float normY = 0, normX = 0;

		if (controlsInput.wKeyPressed) {
			if (!playerColliding(upwards)) {
				vector.y += calcSpeed();
			}
		}
		if (controlsInput.sKeyPressed) { //sKeyPressed wow
			if (!playerColliding(downwards)) {
				vector.y -= calcSpeed();
			}
		}
		if (controlsInput.aKeyPressed) { //aKeyPressed
			if (!playerColliding(leftwards)) {
				vector.x -= calcSpeed();
			}
		}
		if (controlsInput.dKeyPressed) { //dKeyPressed
			if (!playerColliding(rightwards)) {
				vector.x += calcSpeed();
			}
		}

		float length = sqrt(vector.y * vector.y + vector.x * vector.x);
		if (length > 0 || length < 0) {
			normY += vector.y / length; if (normY < 0) { normY = normY * -1; };
			normX += vector.x / length; if (normX < 0) { normX = normX * -1; };
		}
		/* not sure if we'll need it, normalize seems serve its purpose, angle detection of player mov
		float angle = atan2(normX, normY);
		float deg = angle * (180.0 / 3.141592653589793238463);
		*/

		vector.x = vector.x * normX;
		vector.y = vector.y * normY;

		move(vector);
		cursor.move(vector);
	}
}

void Player::update()
{
	if (!stats.isDead) {
		playerSprite.setPosition(position);
		rotate();
	}
	else if (stats.isDead) {
		playerSprite.setPosition(position);
		rotate();
	}
}

void Player::draw(RenderWindow &window)
{
	//hitbox.setPosition(position - Vector2f(size.x/2, size.y/2));
	//window.draw(hitbox);
	playerSprite.draw(window);
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

void Player::playerFire()
{
	if (controlsInput.lmbKeyPressed) {
		if (stats.reload.done) {
			if (stats.shoot.done) {
				stats.ammo--;
				stats.shoot.reset();
				std::cout << "pew!\n"; // spawn bullet here
				if (stats.ammo <= 0) {
					stats.reload.reset();
					std::cout << "reloading!\n";
					stats.ammo = 5;
				}
			}
		}
	}
}

float Player::calcSpeed() 
{
	// dodge detection
	if (!stats.dodging) {
		if (controlsInput.spaceKeyPressed && stats.stamina > 40) {
			stats.dodging = true;
			stats.stamina -= 40;
			stats.dodge.reset();
			std::cout << "dodge!\n";
			return stats.speed * 4;
		}
		// sprint detection
		if (controlsInput.shiftKeyPressed && stats.stamina > 0) {
			if (stats.sprint.done) {
				stats.stamina -= 10;
				stats.sprint.reset();
				std::cout << "sprint!\n";
			}
			return stats.speed * 2;
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

bool Player::playerColliding(Vector2f direction) {
	//for (std::vector<Entity*>::iterator obj = entities.begin(); obj != entities.end(); ++obj) {
	for (auto entity : entityController.entities) {
		if (entity->isSolid && collidesWith(entity, direction)) {
			return true;
		}
	}
	return false;
}