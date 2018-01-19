#include "stdafx.h"
#include "EntityController.h"

EntityController::EntityController(Player &p, ControlsInput &ci):
	player (p),
	ci (ci)
{
	staminaBar.setFillColor(Color::Yellow);
	staminaBarBorder.setFillColor(Color::Transparent);
	staminaBarBorder.setOutlineColor(Color::Black);
	staminaBarBorder.setOutlineThickness(1);
}

bool EntityController::playerColliding(Vector2f direction) {
	for (auto const object : entities) {
		if (object->isSolid && player.collidesWith(*object, direction)) {
			return true;
		}
	}
	return false;
}

float EntityController::calcSpeed() {
	time_t& prevT = player.stats.sprintTimer;
	time_t curT = time(0);
	int& stam = player.stats.stamina;

	if (ci.shiftKeyPressed) {
		if (stam > 0) {
			if (curT > prevT) {
				std::cout << "stamina - 33 :: new = " << stam << "\n";
				stam -= 20;
				prevT = curT;
			}
			return player.stats.speed * 2;
		}
		if (stam < 0) { stam = 0; }
	}
	else if (stam < 100) {
		if (curT > prevT) {
			std::cout << "stamina + 20 :: new = " << stam << "\n";
			stam += 20;
			prevT = curT;
		}
		if (stam > 100) { stam = 100; }
	}
	return player.stats.speed;
}

void EntityController::update() {

	Vector2f upwards = Vector2f(0.0f, calcSpeed());
	Vector2f downwards = Vector2f(0.0f, -calcSpeed());
	Vector2f leftwards = Vector2f(-calcSpeed(), 0.0f);
	Vector2f rightwards = Vector2f(calcSpeed(), 0.0f);

	Vector2f vector(0, 0);
	float normY = 0, normX = 0;

	if (ci.wKeyPressed) {
		if (!playerColliding(upwards)) { 
			vector.y += calcSpeed(); 
			cursor.update(upwards);
		} 
	}

	if (ci.sKeyPressed) { //sKeyPressed
		if (!playerColliding(downwards)) {
			vector.y -= calcSpeed();
			cursor.update(downwards);
		}
	}
	if (ci.aKeyPressed) { //aKeyPressed
		if (!playerColliding(leftwards)) {
			vector.x -= calcSpeed();
			cursor.update(leftwards);
		}
	}
	if (ci.dKeyPressed) { //dKeyPressed
		if (!playerColliding(rightwards)) {
			vector.x += calcSpeed();
			cursor.update(rightwards);
		}
	}

	float length = sqrt(vector.y * vector.y + vector.x * vector.x);
	if (length > 0 || length < 0) {
		normY += vector.y / length; if (normY < 0) { normY = normY * -1; };
		normX += vector.x / length; if (normX < 0) { normX = normX * -1; };
	}

	float angle = atan2(normX, normY);
	float deg = angle * (180.0 / 3.141592653589793238463);

	vector.x = vector.x * normX;
	vector.y = vector.y * normY;

	player.move(vector);
	cursor.update(Vector2f(0.0f, 0.0f));
	player.update();
}

void EntityController::updateHUD() {
	staminaBar.setPosition(player.getPos() - Vector2f(50, 40));
	staminaBarBorder.setPosition(player.getPos() - Vector2f(50, 40));
	staminaBar.setSize(Vector2f(player.stats.stamina, 10));
}

void EntityController::drawHUD(RenderWindow & w) {
	w.draw(staminaBarBorder);
	w.draw(staminaBar);
}

void EntityController::draw(RenderWindow & w) {
	background.draw(w);
	for (auto object : entities) {
		object->draw(w);
	}
	player.draw(w);

	// build interface
	updateHUD();
	drawHUD(w);

	cursor.draw(w);
}
