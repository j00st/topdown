#ifndef Crate_HEADER
#define Crate_HEADER

#include "Entity.h"
#include "bullet.h"
#include "Graphic.h"
/*! \class Crate
\brief Crate class
Contains the crate graphic and overrides the necessary functions from Entity.
*/
class Crate :
	public Entity
{
private:
	enum states { normal, destroyed };
	String spriteStates[2] = {"sprites/crate0.png" , "sprites/crate1.png" };
	Graphic crate = Graphic(spriteStates[normal]);
public:
	Crate(Vector2f position, Vector2f size, bool isSolid = true, int state = states::normal);
	void update(std::map<int, Bullet*> & bullets);
	void draw(RenderWindow & w) override;
};

#endif
