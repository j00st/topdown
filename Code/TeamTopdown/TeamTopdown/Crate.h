#ifndef Crate_HEADER
#define Crate_HEADER

#include "Entity.h"
#include "Graphic.h"
/*! \class Crate
\brief Crate class
Contains the crate graphic and overrides the necessary functions from Entity.
*/
class Crate :
	public Entity
{
private:
	Graphic body = Graphic("sprites/crate.png");
public:
	Crate(Vector2f position, Vector2f size, bool isSolid = true, bool hostile = false);
	void update() override;
	void draw(RenderWindow & w) override;
};

#endif
