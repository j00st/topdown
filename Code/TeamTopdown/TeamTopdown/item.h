#include "stdafx.h"
#include <iostream>
#include "PlayerStats.h"
#include "Entity.h"
#include "Graphic.h"
#include <windows.h>
#include <SFML/Graphics.hpp>
using namespace sf;
class Item : public Entity
{
private:
		Vector2f position;
		Vector2f size;
		int statToBeCahnged;
		int power;
		Graphic sprite;
public:
	Item(Vector2f position, Vector2f size, int statToBeCahnged,int power);
	void pickUp(PlayerStats & stats);
	void draw(RenderWindow & window);
};

