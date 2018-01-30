#include "stdafx.h"
#include "Item.h"

using namespace sf;
Item::Item(Vector2f pos,Vector2f size,int ammo, int energy)://, PlayerStats & stats):
	Entity(pos, size, false),
	//stats (stats),
	ammo(ammo),
	energy(energy)
{
	sprite.setPosition(position);
}
void Item::pickUp(PlayerStats & stats) {
	stats.ammo += ammo;
}

void Item::draw(RenderWindow &window) {
	sprite.draw(window);
}