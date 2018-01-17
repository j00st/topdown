#ifndef EntityCtrl_HEADER
#define EntityCtrl_HEADER

#include "PlayerTemp.h"
#include "Crate.h"

class EntityController
{
private:
	PlayerTemp player;
	Crate c;
	float speed = 2.5f;
public:
	EntityController();
	void update();
	void draw(RenderWindow & w);
};

#endif