#include "stdafx.h"
#include "item.h"


Item::Item(Vector2f position, Vector2f size, int statToBeCahnged,int power):
	Entity(position, size, false)
{
	switch (statToBeCahnged) {
		case 0:
			sprite = Graphic("sprites/item0.png", true);
		case 1:
			sprite = Graphic("sprites/item1.png", true);
	}
	
}

void Item::pickUp(PlayerStats & stats) {
	switch (statToBeCahnged) {
	case 0:
		stats.stamina = 100;
	case 1:
		stats.energy = 100;
	}
}

void Item::draw(RenderWindow &window) {
	sprite.draw(window);
}