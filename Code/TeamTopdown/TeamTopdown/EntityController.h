#ifndef EntityCtrl_HEADER
#define EntityCtrl_HEADER

#include "PlayerTemp.h"
#include "Crate.h"
#include "Entity.h"

class EntityController
{
private:
	PlayerTemp player;
	Entity* collisionObjects[2] = { 
		new Crate(Vector2f(320.0f, 320.0f), Vector2f(64.0f, 64.0f)),
		new Crate(Vector2f(160.0f, 160.0f), Vector2f(32.0f, 32.0f))
	};

	Vector2f upwards;
	Vector2f downwards;
	Vector2f leftwards;
	Vector2f rightwards;

	bool playerColliding(Vector2f direction);
public:
	EntityController();
	void update();
	void draw(RenderWindow & w);
};

#endif