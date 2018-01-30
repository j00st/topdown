#include "stdafx.h"
#include "EntityController.h"

EntityController::EntityController(Player &p, Cursor &c, ControlsInput &ci, Map &map) :
	map (map),
	player(p),
	cursor(c),
	ci(ci),
	entities(map.getEntities()),
	enemies(map.getEnemies()),
	shakeTimer(Timer(7)),
	exits(map.getExits())
{
	player.position = map.getSpawnPoint();
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

bool EntityController::checkBulletMap() {
	for (int i = 0; i < bulletId; i++) {
		if (!bullets.count(i)) {
			bullets[i] = new Bullet(8.0f, (cursor.getPos() - player.getPos()), player.getPos(), Vector2f(1, 1), true);
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
			return player.stats.speed * 1.5;
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
	//std::cout << "shoot\n";
	std::cout << ci.rKeyPressed << "\n";
	int& ammo = player.stats.ammo;
	Timer& reload = player.stats.reload;
	Timer& shoot = player.stats.shoot;

	//-- reloading --//
	if (ci.rKeyPressed) {
		if (reload.done) {
			reload.reset();
			ammo = 5;
		}
	}

	//-- fire weapon --//
	if (ci.lmbKeyPressed) {
		if (reload.done) {
			if (shoot.done) {
				shakeTimer.reset();
				ammo--;
				shoot.reset();
				if (!checkBulletMap()) {
					bullets[bulletId] = new Bullet(8.0f, (cursor.getPos() - player.getPos()), player.getPos(), Vector2f(1, 1), true);
					bulletId++;
				}

				if (ammo <= 0) {
					reload.reset();
					ammo = 5;
				}
			}
		}
	}
}

// rename to player movement? or seperate?
void EntityController::update() {
	shakeTimer.update();
	std::cout << shakeTimer.timer << "\n";

	// 0 key triggers death
	if (ci.num0KeyPressed) {
		player.TriggerDeath();
	}
	// 9 key triggers life
	if (ci.num9KeyPressed) {
		player.TriggerLife();
	}

	// when alive, do this:
	if (!player.stats.isDead) {

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
			} 
		}
		if (ci.sKeyPressed) { //sKeyPressed wow
			if (!playerColliding(downwards)) {
				vector.y -= calcSpeed();
			}
		}
		if (ci.aKeyPressed) { //aKeyPressed
			if (!playerColliding(leftwards)) {
				vector.x -= calcSpeed();
			}
		}
		if (ci.dKeyPressed) { //dKeyPressed
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

		player.move(vector);
		cursor.move(vector);
		player.stats.position = player.position;
	}

	for (auto exitTile : exits) {
		if (player.collidesWith(exitTile, Vector2f(0, 0))) {
			exit = exitTile->state;
			break;
		}
	}
	player.update();
	for (auto entity : entities)
	{
		entity->update();
	}
	for (auto enemy : enemies)
	{
		enemy->update();
		if (enemy->state != 2) {
			Vector2f RPP = player.position - enemy->position;
			Vector2f RLP = enemy->getLookAtObj() - enemy->position;
			float angle = acos((RPP.x * RLP.x + RPP.y * RLP.y) / (sqrt((int)RPP.x * (int)RPP.x + (int)RPP.y * (int)RPP.y) * sqrt((int)RLP.x * (int)RLP.x + (int)RLP.y * (int)RLP.y)));
			angle *= (float(180.0) / float(3.141592653589793238463));
			/*std::cout << "angle: " << angle << '\n';
			std::cout << "Relative Player Pos: " << RPP.x << "," << RPP.y << '\n';
			std::cout << "Relative LookAt Pos: " << RLP.x << "," << RLP.y << '\n' << '\n';*/
			if (angle < 90 || RPP == RLP) {
				visionBullet vb = visionBullet(8, player.position - enemy->position, enemy->position, Vector2f(5, 5), true);
				while (vb.getIsAlive())
				{
					if (vb.collidesWith(&player, vb.getDirection()))
					{
						vb.setIsAlive(false);
						enemy->state = 1;
						Time elapsed1 = clock.getElapsedTime();
						if (elapsed1.asMilliseconds() > 1000 - (std::rand() % 800 - 400))
						{
							bullets[bulletId] = new Bullet(8.0f, (player.getPos() - enemy->position), enemy->position, Vector2f(1, 1), true);
							bulletId++;
							clock.restart();
						}
					}
					for (auto entity : entities)
					{
						if (entity->isSolid && vb.collidesWith(entity, vb.getDirection())) {
							vb.setIsAlive(false);
							enemy->hostile = false;
						}
					}
					vb.update();
				}
			}
		}
	}
	cursor.update();

	/* Bullet update */
	for (auto & bullet : bullets) {
		if (bullet.second->collidesWith(&player, bullet.second->getDirection())) {
			player.TriggerDeath();
		}
		for (auto entity : entities) {
			if (entity->isSolid && bullet.second->collidesWith(entity, bullet.second->getDirection())) {
				bullet.second->setIsAlive(false);
				entity->hit();
			}
		}
		for (auto enemy : enemies) {
			if (enemy->isSolid && bullet.second->collidesWith(enemy, bullet.second->getDirection())) {
				bullet.second->setIsAlive(false);
				enemy->hit();
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

void EntityController::draw(RenderWindow & w) {
	map.background.draw(w);
	for (auto entity : entities) {
		entity->draw(w);
	}
	for (auto enemy : enemies)
	{
		enemy->draw(w);
	}
	/* Bullet draw */
	for (auto & bullet : bullets) {
		bullet.second->draw(w);
	}
	player.draw(w);
	map.shadowMap.draw(w);
	// build interface
	cursor.draw(w);
}


int EntityController::exiting() {
	return exit;
}
