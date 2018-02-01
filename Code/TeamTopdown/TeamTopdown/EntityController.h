#ifndef EntityCtrl_HEADER
#define EntityCtrl_HEADER

#include "Graphic.h"
#include "Player.h"
#include "Enemy.h"
#include "Crate.h"
#include "controlsInput.h"
#include "Cursor.h"
#include "visionBullet.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Map.h"
#include "SFML\Audio.hpp"

/*! \class EntityController
\brief Contains instances of every entity, including player and background.
This class contains instances of every entity.
It has a function to update positions of every entity, including player, taking collision into account.
It also has a draw() function to draw all entities at once.
Furthermore, it contains 4 vectors to determine direction, to be built into a seperate class.
*/
class EntityController
{
private:
	Map * map;
	Player &player;
	ControlsInput &ci;
	Cursor &cursor;
	Clock clock;
	int bulletId = 0;
	int exit = 0;

	sf::SoundBuffer SBshoot;
	sf::SoundBuffer SBreload;

	sf::Sound SEshoot;
	sf::Sound SEreload;
	
	std::vector<Entity*> entities;
	std::vector<Enemy*> enemies;
	std::vector<Bullet*> bullets;
	std::vector<Item*> items;
	std::vector<Exit*> exits;
	std::vector<Turret*> turrets;

	bool playerColliding(Vector2f direction); /*!< checks if player is colliding in direction */
	void deleteBullet(std::vector<Bullet*>::iterator & bulletIt);

	void deleteItem(std::vector<Item*>::iterator & itemIt);
public:
	EntityController(Player &p, Cursor &c, ControlsInput &ci, Map * map);
	Timer shakeTimer;
	float calcSpeed(); /*!< check how player is moving */
	void playerFire(); /*!< check if player is firing */
	void update(); /*!< updates current game */
	void draw(RenderWindow & w); /*!< draws objects on screen */
	int exiting();
};

#endif