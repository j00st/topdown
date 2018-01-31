#ifndef Item_HEADER
#define Item_HEADER

//#include "PlayerStats.h"
#include "Entity.h"
#include "stdafx.h"
#include "Graphic.h"
#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include "PlayerStats.h"

class Item : public Entity
{
private:
	Graphic sprite = Graphic("sprites/item.png");
public:
	//PlayerStats & stats;
	int ammo; /*!< ammo  to be refiled*/
	int energy; /*!< energy  to be refiled*/
	Item(sf::Vector2f pos, sf::Vector2f size, int ammo, int energy); 
	void draw(sf::RenderWindow &window) override; /*!< Draw item on window */
	void pickUp( PlayerStats & stats); /*!< ads ammo and energy to the player stats*/
};
#endif
