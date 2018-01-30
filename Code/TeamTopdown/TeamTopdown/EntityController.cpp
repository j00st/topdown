#include "stdafx.h"
#include "EntityController.h"

EntityController::EntityController(Player &p, Cursor &c, ControlsInput &ci, Map &map) :
	map (map),
	player(p),
	ci(ci), 
	cursor(c),
	entities(map.getEntities()),
	enemies(map.getEnemies())
{
	player.position = map.getSpawnPoint();
}

bool EntityController::playerColliding(Vector2f direction) {
	for (auto item : items){
		for (std::vector<Item*>::iterator itemIt = items.begin(); itemIt != items.end(); ++itemIt) {
			if (player.collidesWith(*itemIt, direction)) {
				item->pickUp(player.stats);
				deleteItem(itemIt);
				break;
			}
		}
	}
	
	//for (std::vector<Entity*>::iterator obj = entities.begin(); obj != entities.end(); ++obj) {
	for (auto entity : entities) {
		if (entity->isSolid && player.collidesWith(entity, direction)) {
			return true;
		}
	}
	return false;
}

void EntityController::deleteBullet(std::vector<Bullet*>::iterator & bulletIt) {
	delete *bulletIt;
	bullets.erase(bulletIt);
}

void EntityController::deleteItem(std::vector<Item*>::iterator & itemIt) {
	delete *itemIt;
	items.erase(itemIt);
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
	int& ammo = player.stats.ammo;
	Timer& reload = player.stats.reload;
	Timer& shoot = player.stats.shoot;

	for (auto enemy : enemies) {
		if (enemy->hostile) {
			bullets.push_back(new Bullet(8.0f, (player.getPos() - enemy->position), enemy->position, Vector2f(1, 1), true));
		}
	}

	if (ci.lmbKeyPressed) {
		if (reload.done) {
			if (shoot.done) {
				ammo--;
				shoot.reset();
				bullets.push_back(new Bullet(8.0f, (cursor.getPos() - player.getPos()), player.getPos(), Vector2f(1, 1), true));
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
	
	player.update();
	for (auto entity : entities)
	{
		entity->update();
	}
	for (auto enemy : enemies)
	{
		enemy->update();
	}
	cursor.update();

	/* Bullet update */
	for (std::vector<Bullet*>::iterator bulletIt = bullets.begin(); bulletIt != bullets.end(); ++bulletIt) {
		(*bulletIt)->update();
		bool deleted = false;
		if ((*bulletIt)->collidesWith(&player, (*bulletIt)->getDirection())) {
			deleteBullet(bulletIt);
			deleted = true;
			player.TriggerDeath();
		}
		if (deleted) break;
		for (auto entity : entities) {
			if (entity->isSolid && (*bulletIt)->collidesWith(entity, (*bulletIt)->getDirection())) {
				deleteBullet(bulletIt);
				deleted = true;
				Entity* temp = entity->hit();
				if (temp != nullptr) {
					//entities.resize(entities.size()+1);
					//entities.push_back(temp);
					Item* temp2;
					temp2 = dynamic_cast<Item*> (temp);
					items.push_back(temp2);
				}
				break;
			}
		}
		if (deleted) break;
		for (auto enemy : enemies) {
			if (enemy->isSolid && (*bulletIt)->collidesWith(enemy, (*bulletIt)->getDirection())) {
				deleteBullet(bulletIt);
				deleted = true;
				enemy->hit();
				break;
			}
		}
		if (deleted) break;
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
		bullet->draw(w);
	}

	for (auto & item : items) {
		item->draw(w);
	}

	player.draw(w);
	map.shadowMap.draw(w);
	// build interface
	cursor.draw(w);
}
