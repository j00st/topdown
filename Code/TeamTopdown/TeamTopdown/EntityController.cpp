#include "stdafx.h"
#include "EntityController.h"

EntityController::EntityController(Player &p, ControlsInput &ci):
	player (p),
	ci (ci)
{
	gameStartTime = time(0);
	font.loadFromFile("sprites/C64_Pro_Mono-STYLE.ttf");
	gameTimeText.setFont(font);
	gameTimeText.setCharacterSize(15);
}

bool EntityController::playerColliding(Vector2f direction) {
	//for (std::vector<Entity*>::iterator obj = entities.begin(); obj != entities.end(); ++obj) {
	for (auto entity : entities) {
		if (entity->isSolid && player.collidesWith(entity, direction)) {
			return true;
		}
	}
	return false;
}

float EntityController::calcSpeed() {
	int& stamina = player.stats.stamina;
	Timer& sprint = player.stats.sprint;
	Timer& energy = player.stats.energy;

	// dodge detection
	if (!player.stats.dodging) {
		if (ci.spaceKeyPressed && stamina > 40) {
			player.stats.dodging = true;
			stamina -= 40;
			player.stats.dodge.reset();
			std::cout << "dodge!\n";
			return player.stats.speed * 4;
		}
		// sprint detection
		if (ci.shiftKeyPressed && stamina > 0) {
			if (sprint.done) {
				stamina -= 10;
				sprint.reset();
				std::cout << "sprint!\n";
			}
			return player.stats.speed * 2;
		}
		else if (stamina < 100) {
			if (energy.done) {
				stamina += 10;
				energy.reset();
			}
		}
	}
	else {
		if (player.stats.dodge.done) {
			player.stats.dodging = false;
		}
		else {
			//std::cout << "dodging!\n";
			return player.stats.speed * 4;
		}
	}
	if (stamina < 0) { stamina = 0; }
	if (stamina > 100) { stamina = 100; }

	// walk
	return player.stats.speed;
}

void EntityController::playerFire()
{
	int& ammo = player.stats.ammo;
	Timer& reload = player.stats.reload;
	Timer& shoot = player.stats.shoot;

	if (ci.lmbKeyPressed) {
		if (reload.done) {
			if (shoot.done) {
				ammo--;
				shoot.reset();
				bullets[bulletId] = new Bullet(5, (ci.mousePos - player.getPos()), player.getPos(), Vector2f(74, 46), true);
				bulletId++;
				std::cout << "pew!\n"; // spawn bullet here
				if (ammo <= 0) {
					reload.reset();
					std::cout << "reloading!\n";
					ammo = 5;
				}
			}
		}
	}
}

// rename to player movement? or seperate?
void EntityController::update() {
	//-- player firing --//
	playerFire();
	player.stats.shoot.update();

	//-- player movement --//
	player.stats.energy.update();
	player.stats.sprint.update();
	player.stats.dodge.update();
	player.stats.reload.update();

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
	if (ci.sKeyPressed) { //sKeyPressed wow
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
	/* not sure if we'll need it, normalize seems serve its purpose, angle detection of player mov
	float angle = atan2(normX, normY);
	float deg = angle * (180.0 / 3.141592653589793238463);
	*/

	vector.x = vector.x * normX;
	vector.y = vector.y * normY;

	player.move(vector);
	cursor.update(Vector2f(0.0f, 0.0f));
	player.update();
}

//--
//-- quick hud setup start --//
void EntityController::updateHUD() {
	Vector2f offset = Vector2f(50, -40);
	//-- game time --//
	gameTime = 60 - (time(0) - gameStartTime);
	gameTimeText.setString(std::to_string(gameTime));
	gameTimeText.setPosition(player.getPos() - offset + Vector2f(0, -20));

	//-- stamina bar --//
	if (player.stats.stamina < 99) {
		staminaBar.setFillColor(Color::Yellow);
		staminaBarBorder.setFillColor(Color::Transparent);
		staminaBarBorder.setOutlineColor(Color::Black);
		staminaBarBorder.setOutlineThickness(2);

		staminaBar.setPosition(player.getPos() - offset);
		staminaBarBorder.setPosition(player.getPos() - offset);
		staminaBar.setSize(Vector2f(player.stats.stamina, 10));
	}
	else {
		staminaBar.setFillColor(Color::Transparent);
		staminaBarBorder.setFillColor(Color::Transparent);
		staminaBarBorder.setOutlineColor(Color::Black);
		staminaBarBorder.setOutlineThickness(0);
	}
	/* Bullet update */
	for (auto bullet = bullets.begin(); bullet != bullets.end(); )
		if (bullet->second->getTimeAlive() >= 30) {
			delete bullet->second;
			bullet = bullets.erase(bullet);
		}else
			++bullet;
	
	for (auto & bullet : bullets) {
		bullet.second->update();
		}
	}



void EntityController::drawHUD(RenderWindow & w) {
	updateHUD();
	w.draw(gameTimeText);
	w.draw(staminaBarBorder);
	w.draw(staminaBar);
}
//-- quick hud setup end --//
//--

void EntityController::draw(RenderWindow & w) {
	background.draw(w);
	for (auto entity : entities) {
		entity->draw(w);
	}
	/* Bullet draw */
	for (auto & bullet : bullets) {
		bullet.second->draw(w);
	}
	player.draw(w);

	// build interface
	drawHUD(w);
	cursor.draw(w);
}
