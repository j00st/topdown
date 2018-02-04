#include "stdafx.h"
#include "Item.h"

using namespace sf;
Item::Item(Vector2f pos,Vector2f size,int ammo, int energy):
	Entity(pos, size, false),
	ammo(ammo),
	energy(energy)
{
	sprite.setPosition(position);
}
void Item::pickUp(PlayerStats & stats) {
	stats.maxAmmo += ammo;

}

void Item::draw(RenderWindow &window) {
	sprite.draw(window);
}