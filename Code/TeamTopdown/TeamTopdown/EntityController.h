#ifndef EntityCtrl_HEADER
#define EntityCtrl_HEADER

#include "PlayerTemp.h"
#include "Crate.h"

class EntityController
{
private:
	PlayerTemp p;
	Crate c;
	float speed = 5.0f;
public:
	EntityController();
	void update();
	void draw(RenderWindow & w);
};

#endif