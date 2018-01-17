#pragma once
#include "Entity.h"

/** \class playerTemp
* \brief Player class
* This class represents our player.
* It derives from entityController.
* It overrides the update function to set our current position,
* and overrides the draw to draw the shape according to our camera position.
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

