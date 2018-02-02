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
/*!
\brief
Item is a entity that can modify the stats
\details
Contains the item graphic and overrides the necessary functions from Entity.
The item contains ammo and energy that will be added when it`s picked up.
Energy isn`t used in the end game beacuse we diced not to use it at last minute.
*/
class Item : public Entity
{
private:
	Graphic sprite = Graphic("sprites/item.png");
public:
	int ammo; /*!< ammo  to be refiled*/
	int energy; /*!< energy  to be refiled*/
	Item(sf::Vector2f pos, sf::Vector2f size, int ammo, int energy); 
	/* void draw()
	\brief draws item in the window */
	void draw(sf::RenderWindow &window) override; /*!< Draw item on window */
	/*void pickUp()
	\brief adds ammo to the player
	\details
	PlayerStats stats the player stats that has to be updated */
	void pickUp( PlayerStats & stats); /*!< ads ammo and energy to the player stats*/
};
#endif
