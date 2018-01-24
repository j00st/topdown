#ifndef Crate_HEADER
#define Crate_HEADER

#include "Entity.h"
#include "Graphic.h"
#include <SFML/System.hpp>

/*! \class Crate
\brief Crate class
Contains the crate graphic and overrides the necessary functions from Entity.
*/
class Crate : public Entity
{
private:
	Graphic body = Graphic("sprites/crate.png");
public:
	Crate(sf::Vector2f position, sf::Vector2f size, bool isSolid = true);
	void update() override;
	void draw(sf::RenderWindow & w) override;
};

#endif
