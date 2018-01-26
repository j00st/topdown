#include "stdafx.h"
#include "EntityController.h"

EntityController::EntityController(Player &p, Cursor &c, ControlsInput &ci):
	player (p),
	cursor(c),
	ci (ci)
{
	gameStartTime = time(0);
	font.loadFromFile("sprites/C64_Pro_Mono-STYLE.ttf");
	gameTimeText.setFont(font);
	gameTimeText.setCharacterSize(7);
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

Vector2f EntityController::playerCollisionCheck() 
{
	Vector2f vector = Vector2f(0, 0);
	int speed = player.calcSpeed();
	Vector2f upwards = Vector2f(0.0f, speed);
	Vector2f downwards = Vector2f(0.0f, -speed);
	Vector2f leftwards = Vector2f(-speed, 0.0f);
	Vector2f rightwards = Vector2f(speed, 0.0f);
	float normY = 0, normX = 0;

	if (ci.wKeyPressed) {
		if (!playerColliding(upwards)) {
			vector.y += speed;
		}
	}
	if (ci.sKeyPressed) { //sKeyPressed wow
		if (!playerColliding(downwards)) {
			vector.y -= speed;
		}
	}
	if (ci.aKeyPressed) { //aKeyPressed
		if (!playerColliding(leftwards)) {
			vector.x -= speed;
		}
	}
	if (ci.dKeyPressed) { //dKeyPressed
		if (!playerColliding(rightwards)) {
			vector.x += speed;
		}
	}

	float length = sqrt(vector.y * vector.y + vector.x * vector.x);
	if (length > 0 || length < 0) {
		normY += vector.y / length; if (normY < 0) { normY = normY * -1; };
		normX += vector.x / length; if (normX < 0) { normX = normX * -1; };
	}
	vector.x = vector.x * normX;
	vector.y = vector.y * normY;
	
	return vector;
}

bool EntityController::checkBulletMap() {
	for (int i = 0; i < bulletId; i++) {
		if (!bullets.count(i)) {
			bullets[i] = new Bullet(15, (cursor.getPos() - player.getPos()), player.getPos(), Vector2f(11, 2), true);
			return true;
		}
	}
	return false;
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
				if (!checkBulletMap()) {
					bullets[bulletId] = new Bullet(15, (cursor.getPos() - player.getPos()), player.getPos(), Vector2f(11, 2), true);
					bulletId++;
				}
				//std::cout <<"size of bullet map: " << bulletId << "\n"; // spawn bullet here
				if (ammo <= 0) {
					reload.reset();
					//std::cout << "reloading!\n";
					ammo = 5;
				}
			}
		}
	}
}


// rename to player movement? or seperate?
void EntityController::update() {

	// when alive, do this:
	if (!player.stats.isDead) {

		//-- player firing --//
		playerFire();
		player.stats.shoot.update();

		player.move(playerCollisionCheck());
		cursor.move(playerCollisionCheck());
		player.stats.position = player.getPos();
	}
	
	cursor.update();
	player.update();

	for (auto entity : entities) {
		entity->update();
	}

	/* Bullet update */
	for (auto & bullet : bullets) {
		for (auto entity : entities) {
			if (entity->isSolid && bullet.second->collidesWith(entity, bullet.second->getDirection())) {
				bullet.second->setIsAlive(false);
			}
		}
		bullet.second->update();
	}
	for (auto bullet = bullets.begin(); bullet != bullets.end(); ) {
		//std::cout << bullet->second->getIsAlive() << "\n";
		if (!bullet->second->getIsAlive()) {
			delete bullet->second;
			bullet = bullets.erase(bullet);
		}
		else
			++bullet;
	}
}

//--
//-- quick hud setup start --//
void EntityController::updateHUD() {
	Vector2f offset = Vector2f(50, -40);
	//-- game time --//
	gameTime = 60 - (int(time(0)) - int(gameStartTime));
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
		staminaBar.setSize(Vector2f(float(player.stats.stamina), 10));
	}
	else {
		staminaBar.setFillColor(Color::Transparent);
		staminaBarBorder.setFillColor(Color::Transparent);
		staminaBarBorder.setOutlineColor(Color::Black);
		staminaBarBorder.setOutlineThickness(0);
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
	backgrounds.draw(w);
	// build interface
	drawHUD(w);
	cursor.draw(w);
}
