#ifndef EntityCtrl_HEADER
#define EntityCtrl_HEADER

#include "Graphic.h"
#include "Player.h"
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
	Graphic background = Graphic("sprites/map0.png");
	Graphic backgrounds = Graphic("sprites/map0s.png");
	Map collisionMap = Map("sprites/map0c.png");
	std::vector<Entity*> entities = collisionMap.getEntities();
	std::map< int, Bullet* > bullets{};
	int bulletId = 0;
	/*Entity* entities[2] = { 
		new Crate(Vector2f(320.0f, 320.0f), Vector2f(64.0f, 64.0f)),
		new Crate(Vector2f(160.0f, 160.0f), Vector2f(32.0f, 32.0f), false)
	};*/

	bool playerColliding(Vector2f direction);
	bool checkBulletMap();
public:
	//basic hud//
	RectangleShape staminaBar = RectangleShape(Vector2f(100, 10));
	RectangleShape staminaBarBorder = RectangleShape(Vector2f(100, 10));
	Font font;
	Text gameTimeText;
	time_t gameStartTime;
	int gameTime;


	EntityController(Player &p, Cursor &c, ControlsInput &ci);
	float calcSpeed();
	void playerFire();
	void update();
	void updateHUD();
	void drawHUD(RenderWindow& w);
	void draw(RenderWindow & w);
};

#endif