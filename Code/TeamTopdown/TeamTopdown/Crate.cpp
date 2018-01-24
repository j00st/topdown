#include "stdafx.h"
#include "Crate.h"


Crate::Crate(sf::Vector2f position, sf::Vector2f size, bool isSolid):
	Entity(position, size, isSolid)
{
	body.setPosition(position);
}

void Crate::update() {
	body.setPosition(position);
}

void Crate::draw(sf::RenderWindow & w) {
	body.draw(w);
}