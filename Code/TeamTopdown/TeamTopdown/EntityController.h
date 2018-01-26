#ifndef EntityCtrl_HEADER
#define EntityCtrl_HEADER

#include "Graphic.h"
#include "Player.h"
#include "Enemy.h"
#include "Crate.h"
#include "controlsInput.h"
#include "Cursor.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Map.h"
#include "bullet.h"

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
	Player &player;
	ControlsInput &ci;
	Cursor &cursor;
	Graphic background = Graphic("sprites/map0.png"); /*!< background art */
	Graphic backgrounds = Graphic("sprites/map0s.png"); /*!< background shadow map */
	Map collisionMap = Map("sprites/map0c.png"); /*!< collision map */
	std::vector<Entity*> entities = collisionMap.getEntities(player.stats.position);
	std::map< int, Bullet* > bullets{};
	int bulletId = 0;

	bool playerColliding(Vector2f direction); /*!< checks if player is colliding in direction */
	bool checkBulletMap(); /*!< checks current bullets onscreen */
public:
	RectangleShape staminaBar = RectangleShape(Vector2f(100, 10));
	RectangleShape staminaBarBorder = RectangleShape(Vector2f(100, 10));
	Font font;
	Text gameTimeText;
	time_t gameStartTime;
	int gameTime;

	EntityController(Player &p, Cursor &c, ControlsInput &ci);
	//float calcSpeed(); /*!< check how player is moving */
	Vector2f playerCollisionCheck();
	void playerFire(); /*!< check if player is firing */
	void update(); /*!< updates current game */
	void updateHUD(); /*!< Basic hud generation */
	void drawHUD(RenderWindow& w); /*!< draws hud on screen */
	void draw(RenderWindow & w); /*!< draws objects on screen */
};

#endif