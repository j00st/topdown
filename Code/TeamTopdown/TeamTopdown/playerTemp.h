#pragma once
#include "Entity.h"

/** \class playerTemp
* \brief Player class
* This class represents our player.
* It derives from Entity. As such, it overrides the update() function by positioning our sprite according to the entity position.
* It also contains the player's size and speed to do collision detection.
*/

class PlayerTemp :
	public Entity
{
private:
	RectangleShape playerShape;
public:
	PlayerTemp(Vector2f position, Vector2f size, bool isSolid = false);
	float speed = 5.0f;
	void update() override;
	void draw(RenderWindow & w) override;
};

