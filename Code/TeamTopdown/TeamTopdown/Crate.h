#ifndef Crate_HEADER
#define Crate_HEADER

#include "Entity.h"
#include "bullet.h"
#include "Graphic.h"
#include "SFML\Audio.hpp"
#include "Item.h"

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
	static SoundBuffer audioClip;
	Sound crateDestroyed;
public:
	Crate(Vector2f position, Vector2f size, bool isSolid = true, int state = states::normal);
	/* Entity* hit()
	\brief change the state of the crate to destroyed and returns a item object pointer
	*/
	Entity* hit() override;
	/*void draw()
	\brief function to draw the crate on screen*/
	void draw(RenderWindow & w) override;
};

#endif
