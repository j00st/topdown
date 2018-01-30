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
	static sf::SoundBuffer audioClip;
	sf::Sound crateDestroyed;
public:
	Crate(sf::Vector2f position, sf::Vector2f size, bool isSolid = true, int state = states::normal);
	Entity* hit() override;
	void draw(sf::RenderWindow & w) override;
};

#endif
