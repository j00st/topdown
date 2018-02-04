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
	Timer meleeTimer;
	int bulletId = 0;
	int exit = 0;
	float aggroRange = 8 * 32;

	sf::SoundBuffer SBshoot;
	sf::SoundBuffer SBGshoot;
	sf::SoundBuffer SBreload;
	sf::SoundBuffer SBGreload;

	sf::Sound SEshoot;
	sf::Sound SEGshoot;
	sf::Sound SEreload;
	
	std::vector<Entity*> entities;
	std::vector<Enemy*> enemies;
	std::vector<Bullet*> bullets;
	std::vector<Item*> items;
	std::vector<Exit*> exits;
	std::vector<Turret*> turrets;

	bool playerColliding(Vector2f direction); /*!< checks if player is colliding in direction */
	std::vector<Bullet*>::iterator deleteBullet(std::vector<Bullet*>::iterator & bulletIt);

	void deleteItem(std::vector<Item*>::iterator & itemIt);

public:
	EntityController(Player &p, Cursor &c, ControlsInput &ci, Map * map);
	~EntityController();
	void meleeAttack();
	Timer shakeTimer; /*!< creates a timer that contains data for shake */

	/*! /float calcSpeed()
	/brief checks what speed to return based on keyboard inputs */
	float calcSpeed(); 

	/*! /void playerFire()
	/brief checks whether the player is shooting or not and fires bullets based on the keyboard inputs */
	void playerFire();

	/*! /void update()
	/brief updates the following within this object:
	- sets the shakeTimer to shake the screen
	- checks if the player is dead
	- checks whether the player is moving or not
	- moves the player
	- checks entity colissions
	- checks bullets on map */
	void update();

	/*! /void draw()
	/brief draws the following objects on the screen:
	- entities
	- bullets
	- items
	- player 
	- hud
	- cursor
	- background */
	void draw(RenderWindow & w); 
	int exiting();
};

#endif