#pragma once

#include "Entity.h"
#include "Graphic.h"
#include "Timer.h"

/*! \class Turret
\brief Turret that shoots bullets in a certain direction.
This turret is created with a direction in our map, as well as the amount of frames between each shot.
The bullets themselves are shot from EC, with the shot timer being contained inside this class.
The turret sets a public boolean to true when it is time to shoot and sets it to false. This way, EC can read out the boolean to shoot a bullet.*/

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

