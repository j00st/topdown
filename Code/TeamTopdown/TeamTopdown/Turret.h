#pragma once

#include "Entity.h"
#include "Graphic.h"
#include "Timer.h"

class Turret :
	public Entity
{
private:
	enum states {alive, dead};
	Vector2f shootDirection;
	Graphic turret = Graphic("sprites/turret.png", true);
	Timer bulletTimer;
public:
	Turret(Vector2f position, Vector2f size, Vector2f lookAtObject, int framesBetweenShots = 60, bool isSolid = true);
	bool willShoot = false;
	Vector2f getDirection();
	Vector2f getPos() override;
	void update() override;
	Entity* hit() override;
	void draw(RenderWindow & window) override;
	bool collidesWith(Entity* other);
};

