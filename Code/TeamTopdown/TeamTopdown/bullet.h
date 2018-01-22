#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Entity.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet : public Entity
{
private:
	Vector2f speedVect;
	RectangleShape rect;
public:
	Bullet(float speed, Vector2f relativePosBul, Vector2f position, Vector2f size, bool isSolid);
	void update();
	void draw(RenderWindow &window);
};

