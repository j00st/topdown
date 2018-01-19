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
	Graphic background = Graphic("sprites/map2.png");
	Graphic backgroundS = Graphic("sprites/map2_s.png");
	Graphic backgroundT = Graphic("sprites/map2_t.png");
	Cursor cursor = Cursor(ci);
	Entity* entities[2] = { 
		new Crate(Vector2f(100.0f, 100.0f), Vector2f(64.0f, 64.0f)),
		new Crate(Vector2f(50.0f, 50.0f), Vector2f(32.0f, 32.0f), false)
	};

	Vector2f upwards;
	Vector2f downwards;
	Vector2f leftwards;
	Vector2f rightwards;

	bool playerColliding(Vector2f direction);
public:
	EntityController(Player &p, ControlsInput &ci);
	void update();
	void draw(RenderWindow & w);
};

#endif