#ifndef Melee_HEADER
#define Melee_HEADER

#include "Entity.h"
#include "Graphic.h"

/*! \class Melee
\brief Melee class
Contains the Melee graphic and overrides the necessary functions from Entity.
*/
class Melee :
	public Entity
{
public:
	Melee(Vector2f position, Vector2f size, bool isSolid = false, float rotation = 0);
	void update() override;
	void draw(RenderWindow & w) override;
	

	float rotation = 0;
};

#endif
