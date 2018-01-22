#ifndef EntityCtrl_HEADER
#define EntityCtrl_HEADER

#include "Graphic.h"
#include "Player.h"
#include "Crate.h"
#include "controlsInput.h"
#include "Cursor.h"

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
	Graphic background = Graphic("sprites/map1.png");
	Cursor &cursor;
	Entity* entities[2] = { 
		new Crate(Vector2f(320.0f, 320.0f), Vector2f(64.0f, 64.0f)),
		new Crate(Vector2f(160.0f, 160.0f), Vector2f(32.0f, 32.0f), false)
	};

	Vector2f upwards;
	Vector2f downwards;
	Vector2f leftwards;
	Vector2f rightwards;

	bool playerColliding(Vector2f direction);
public:
	EntityController(Player &p, Cursor &c, ControlsInput &ci);
	void update();
	void draw(RenderWindow & w);
};

#endif