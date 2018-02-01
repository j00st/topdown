#include "stdafx.h"
#include "EntityController.h"

EntityController::EntityController(Player &p, Cursor &c, ControlsInput &ci, Map * map) :
	map (map),
	player(p),
	cursor(c),
	ci(ci),
	entities(map->getEntities()),
	enemies(map->getEnemies()),
	shakeTimer(Timer(7)),
	exits(map->getExits()),
	turrets(map->getTurrets()),
	meleeTimer(player.stats.meleeSpeed)
{
	player.position = map->getSpawnPoint();

	SBshoot.loadFromFile("audio/soundeffects/gunshot1.wav");
	SBGshoot.loadFromFile("audio/soundeffects/gunshot2.ogg");
	SBreload.loadFromFile("audio/soundeffects/LoadGun.wav");

	SEshoot.setBuffer(SBshoot);
	SEGshoot.setBuffer(SBGshoot);
	SEreload.setBuffer(SBreload);
}

void EntityController::meleeAttack()
{
	player.setSprite("sprites/characterMelee.png");
	//melee.position = player.position;
	//melee.rotation = player.rotation;
	//meleeBox.setPosition(player.position);
	//meleeBox.setRotation(player.rotation);
	//meleeBox.setSize(Vector2f(32, 16));
	for (auto entity : entities) {
		if (entity->isSolid) {
			Vector2f delta = entity->position + Vector2f(16, 16) - player.getPos();
			float deltaLength = sqrt(delta.x * delta.x + delta.y * delta.y);
			if (deltaLength < player.stats.meleeRange) {
				Entity* temp = entity->hit();
				if (temp != nullptr) {
					Item* temp2;
					temp2 = dynamic_cast<Item*> (temp);
					items.push_back(temp2);
				}
			}
		}
	}
	for (auto turret : turrets) {
		if (turret->isSolid) {
			Vector2f delta = turret->position + Vector2f(16, 16) - player.getPos();
			float deltaLength = sqrt(delta.x * delta.x + delta.y * delta.y);
			if (deltaLength < player.stats.meleeRange) {
				turret->hit();
			}
		}
	}
	for (auto enemy : enemies) {
		if (enemy->state != 2) {
			Vector2f delta = enemy->position - player.getPos();
			float deltaLength = sqrt(delta.x * delta.x + delta.y * delta.y);
			if (deltaLength < player.stats.meleeRange) {
				Entity* temp = enemy->hit();
				if (temp != nullptr) {
					Item* temp2;
					temp2 = dynamic_cast<Item*> (temp);
					items.push_back(temp2);
				}
			}
		}
	}
}

bool EntityController::playerColliding(Vector2f direction) {
	//for (std::vector<Entity*>::iterator obj = entities.begin(); obj != entities.end(); ++obj) {
	// entity check
	for (auto entity : entities) {
		if (entity->isSolid && entity->collidesWith(&player, direction)) {
			return true;
		}
	}
	return false;
}

std::vector<Bullet*>::iterator EntityController::deleteBullet(std::vector<Bullet*>::iterator & bulletIt) {
	delete *bulletIt;
	return bullets.erase(bulletIt);
}

void EntityController::deleteItem(std::vector<Item*>::iterator & itemIt) {
	delete *itemIt;
	items.erase(itemIt);
}

float EntityController::calcSpeed() {
	int& stamina = player.stats.stamina;
	Timer& sprint = player.stats.sprint;
	Timer& energy = player.stats.energy;

	if (ci.spaceKeyPressed && stamina > 40) {
		player.stats.dodging = true;
		stamina -= 40;
		player.stats.dodge.reset();
		return player.stats.speed * 4;
	}
	// sprint detection
	if (ci.shiftKeyPressed && stamina > 0) {
		if (sprint.done) {
			stamina -= 10;
			sprint.reset();
		}
		return player.stats.speed * 1.5;
	}
	else if (stamina < 100) {
		if (energy.done) {
			stamina += 10;
			energy.reset();
		}
	}
	if (stamina < 0) { stamina = 0; }
	if (stamina > 100) { stamina = 100; }

	// walk
	return player.stats.speed;
}

void EntityController::playerFire()
{
	if (!player.stats.pauseMenuOpen) {
		int& ammo = player.stats.ammo;
		int& maxAmmo = player.stats.maxAmmo;
		Timer& reload = player.stats.reload;
		Timer& shoot = player.stats.shoot;

		//-- reloading --//
		if (ci.rKeyPressed) {
			if (reload.done) {
				if (maxAmmo >= 0) {
					int tempAmmo = ammo;
					reload.reset();
					ammo = (maxAmmo < 5) ? (maxAmmo + ammo) : 5;
					maxAmmo -= 5 - tempAmmo;
					SEreload.play();
				}
			}
		}

		//-- fire weapon --//
		if (ci.lmbKeyPressed) {
			if (ammo > 0) {
				if (reload.done) {
					if (shoot.done) {
						SEshoot.play();
						player.setSprite("sprites/characterMuzzle.png");
						shakeTimer.reset();
						ammo--;
						shoot.reset();
						bullets.push_back(new Bullet(8.0f, (cursor.getPos() - player.getPos()), player.getPos(), Vector2f(1, 1), true));
					}
					else if (shoot.timer > 5) {
						player.setSprite("sprites/character.png");
					}
					if (ammo <= 0 && maxAmmo >= 0) {
						ammo = (maxAmmo < 5) ? maxAmmo : 5;
						maxAmmo -= ammo;
						reload.reset();
						player.setSprite("sprites/character.png");
						SEreload.play();
					} 
				}
			}
			 
		}
		else if(meleeTimer.done) {
			player.setSprite("sprites/character.png");
		}
		else { meleeTimer.update(); }
		if (ci.rmbKeyPressed) {
			if (meleeTimer.done) {
				meleeAttack();
				meleeTimer.reset();
			}
		}
		maxAmmo = (maxAmmo < 0) ? 0 : maxAmmo;
	}
}

void EntityController::update() {
	shakeTimer.update();
	// when alive, do this:
	if (!player.stats.isDead) {
		//-- player firing --//
		if (!player.stats.pauseMenuOpen) { // cant fire when pause menu is open
			playerFire();
			player.stats.shoot.update();
		}
		
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
	player.update();
	cursor.update();

	// item check
	for (std::vector<Item*>::iterator itemIt = items.begin(); itemIt != items.end(); ++itemIt) {
		if ((*itemIt)->collidesWith(&player)) {
			(*itemIt)->pickUp(player.stats);
			player.hud.createPopUp((*itemIt)->ammo, (*itemIt)->position);
			if (player.stats.ammo <= 0){
				player.stats.reload.reset();
				player.stats.ammo = (*itemIt)->ammo;
				player.stats.maxAmmo -= (*itemIt)->ammo;
				SEreload.play();
			}
			deleteItem(itemIt);
			break;
		}
	}
	for (auto exitTile : exits) {
		if (exitTile->collidesWith(&player)) {
			exit = exitTile->state;
			break;
		}
	}
	for (auto entity : entities)
	{
		entity->update();
	}
	for (auto enemy : enemies)
	{
		enemy->update();
		if (enemy->state != 2 && !player.stats.isDead) {
			Vector2f RPP = player.position - enemy->position;
			float RPPLength = sqrt(RPP.x * RPP.x + RPP.y * RPP.y);
			if (RPPLength < aggroRange) {
				Vector2f RLP = enemy->getLookAtObj() - enemy->position;
				float angle = acos((RPP.x * RLP.x + RPP.y * RLP.y) / (RPPLength * sqrt((int)RLP.x * (int)RLP.x + (int)RLP.y * (int)RLP.y)));
				angle *= (float(180.0) / float(3.141592653589793238463));
				if (angle < 75 || RPP == RLP) {
					visionBullet vb = visionBullet(8, player.getPos() - enemy->position, enemy->position, Vector2f(5, 5), true);
					while (vb.getIsAlive())
					{
						if (player.collidesWith(&vb))
						{
							if (enemy->state == 0) {
								clock.restart();
							}
							vb.setIsAlive(false);
							enemy->state = 1;
							Time elapsed1 = clock.getElapsedTime();
							if (elapsed1.asMilliseconds() > 1000 - (std::rand() % 800 - 400))
							{
								SEGshoot.play();
								bullets.push_back(new Bullet(8.0f, (player.getPos() - enemy->position), enemy->position, Vector2f(1, 1), true));
								clock.restart();
							}
						}
						for (auto entity : entities)
						{
							if (entity->isSolid && entity->collidesWith(&vb, vb.getDirection())) {
								vb.setIsAlive(false);
								enemy->hostile = false;
							}
						}
						vb.update();
					}
				}
			}
		}
	}
	//Turret update
	for (auto turret : turrets) {
		turret->update();
		if (turret->willShoot) {
			bullets.push_back(new Bullet(8.0f, turret->getDirection(), turret->getPos(), Vector2f(1, 1)));
		}
	}
	/* Bullet update */
	for (std::vector<Bullet*>::iterator bulletIt = bullets.begin(); bulletIt != bullets.end();) {
		(*bulletIt)->update();
		bool deleted = false;
		if (!player.stats.isDead && player.collidesWith(*bulletIt)) {
			bulletIt = deleteBullet(bulletIt);
			deleted = true;
			player.TriggerDeath();
			//de-aggro
			for (auto enemy : enemies) {
				if (enemy->state != 2) {
					enemy->state = 0;
				}
			}
		}
		if (!deleted) {
			for (auto entity : entities) {
				if (entity->isSolid && entity->collidesWith(*bulletIt, (*bulletIt)->getDirection())) {
					bulletIt = deleteBullet(bulletIt);
					deleted = true;
					Entity* temp = entity->hit();
					if (temp != nullptr) {
						Item* temp2;
						temp2 = dynamic_cast<Item*> (temp);
						items.push_back(temp2);
					}
					break;
				}
			}
		}
		if (!deleted) {
			for (auto enemy : enemies) {
				if (enemy->isSolid && enemy->collidesWith(*bulletIt)) {
					bulletIt = deleteBullet(bulletIt);
					deleted = true;
					Entity* temp = enemy->hit();
					if (temp != nullptr) {
						Item* temp2;
						temp2 = dynamic_cast<Item*> (temp);
						items.push_back(temp2);
					}
					break;
				}
			}
		}
		if (!deleted) {
			for (auto turret : turrets) {
				if (turret->isSolid && turret->collidesWith(*bulletIt)) {
					bulletIt = deleteBullet(bulletIt);
					deleted = true;
					turret->hit();
					break;
				}
			}
		}
		if (!deleted) { bulletIt++; }
	}
}

void EntityController::draw(RenderWindow & w) {
	map->background.draw(w);
	for (auto entity : entities) {
		entity->draw(w);
	}
	for (auto turret : turrets) {
		turret->draw(w);
	}
	for (auto enemy : enemies)
	{
		enemy->draw(w);
	}
	/* Bullet draw */
	for (auto & bullet : bullets) {
		bullet->draw(w);
	}

	for (auto & item : items) {
		item->draw(w);
	}
	player.draw(w);
	map->shadowMap.draw(w);
	// build interface
	player.hud.draw(w);
	cursor.draw(w);
}


int EntityController::exiting() {
	return exit;
}
